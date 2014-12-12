//Stærkt inspireret af
//http://www.raspberry-projects.com/pi/programming-in-c/uart-serial-port/using-the-uart

#pragma once

#include <iostream>
#include <unistd.h>     //Used for UART
#include <fcntl.h>      //Used for UART
#include <termios.h>    //Used for UART
#include "Receiver.hpp"

using namespace std;

Receiver::Receiver( /*MsgQueue* contrQ,*/ MsgQueue* midiQ )
: midiQ_( midiQ )
{
  connect();
  /*msgQs msgQs_ = { contrQ, midiQ };
  pthread_create(*/
}

Receiver::~Receiver()
{
  disconnect();
}

void Receiver::connect()
{
  //-------------------------
  //----- SETUP USART 0 -----
  //-------------------------
  //At bootup, pins 8 and 10 are already set to UART0_TXD, UART0_RXD (ie the alt0 function) respectively
  
  //OPEN THE UART
  //The flags (defined in fcntl.h):
  //  Access modes (use 1 of these):
  //    O_RDONLY - Open for reading only.
  //    O_RDWR - Open for reading and writing.
  //    O_WRONLY - Open for writing only.
  //
  //  O_NDELAY / O_NONBLOCK (same function) - Enables nonblocking mode. When set read requests on the file can return immediately with a failure status
  //                      if there is no input immediately available (instead of blocking). Likewise, write requests can also return
  //                      immediately with a failure status if the output can't be written immediately.
  //
  //  O_NOCTTY - When set and path identifies a terminal device, open() shall not cause the terminal device to become the controlling terminal for the process.
  uart0_filestream_ = open( "/dev/ttyAMA0", O_RDONLY | O_NOCTTY & ~O_NDELAY & ~O_NONBLOCK );    //Open in blocking read-only mode
  if ( uart0_filestream_ == -1 )
  {
    //ERROR - CAN'T OPEN SERIAL PORT
    cout << "Error - Unable to open UART.  Ensure it is not in use by another application" << endl;
  }
  
  //CONFIGURE THE UART
  //The flags (defined in /usr/include/termios.h - see  http://pubs.opengroup.org/onlinepubs/007908799/xsh/termios.h.html):
  //  Baud rate:- B1200, B2400, B4800, B9600, B19200, B38400, B57600, B115200, B230400, B460800, B500000,   B576000, B921600, B1000000, B1152000, B1500000, B2000000, B2500000, B3000000, B3500000, B4000000
  //  CSIZE:- CS5, CS6, CS7, CS8
  //  CLOCAL - Ignore modem status lines
  //  CREAD - Enable receiver
  //  IGNPAR = Ignore characters with parity errors
  //  ICRNL - Map CR to NL on input (Use for ASCII comms where you want to auto correct end of line   characters - don't use for bianry comms!)
  //  PARENB - Parity enable
  //  PARODD - Odd parity (else even)
  struct termios options;
  tcgetattr( uart0_filestream_, &options );
  options.c_cflag = B115200 | CS8 | CLOCAL | CREAD;    //<Set baud rate
  options.c_iflag = IGNPAR;
  options.c_oflag = 0;
  options.c_lflag = 0;
  tcflush( uart0_filestream_, TCIFLUSH );
  tcsetattr( uart0_filestream_, TCSANOW, &options );
}

void Receiver::disconnect()
{
  //----- CLOSE THE UART -----
  close( uart0_filestream_ );
}

/* Test function for send. Function not needed by current version of BodyRock3000
void Receiver::send()
{
  //----- TX BYTES -----
  unsigned char tx_buffer[ 20 ]; // Statisk eller dynamisk størrelse?
  unsigned char *p_tx_buffer;

  p_tx_buffer = &tx_buffer[ 0 ];
  *p_tx_buffer++ = 'H';
  *p_tx_buffer++ = 'e';
  *p_tx_buffer++ = 'l';
  *p_tx_buffer++ = 'l';
  *p_tx_buffer++ = 'o';

  if ( uart0_filestream_ != -1 )
  {
    int count = write( uart0_filestream_, &tx_buffer[ 0 ], ( p_tx_buffer - &tx_buffer[ 0 ] ) );    //filestream_, bytes to write, number of bytes to write
    if ( count < 0 )
    {
      cout << "UART TX error" << endl;
    }
  }
}*/


void Receiver::receive()
{
  //----- CHECK FOR ANY RX BYTES -----
  if ( uart0_filestream_ != -1 )
  {
    // Read up to 100 characters from the port if they are there
    unsigned char rx_buffer[ ( MAX_SENSORS * 5 ) + 1 ] = { 0 };
    int rx_length = read( uart0_filestream_, ( void* )rx_buffer, ( MAX_SENSORS * 5 ) );    //filestream_, buffer to store in, number of bytes to read (max)
    rx_buffer[rx_length] = '\0';
    
    if ( rx_length < 0 )
    {
      //An error occured (will occur if there are no bytes)
    }
    
    else if ( rx_length > ( MAX_SENSORS * 5 ) )
    {
      cout << "rx_length too long. Fuck this shit.." << endl;
    }
    
    else if ( rx_length == 0 )
    {
      cout << "ERROR: No data waiting" << endl;//No data waiting
    }
    
    else
    {
      // Til test: Udskriv nøjagtig det array som er modtaget
      for( int i = 0; ( i < rx_length ); i++ )
        cout << "[" << (int)rx_buffer[ i ] << "]";
      
      //Bytes received
      if( ( rx_buffer[ 0 ] == 0x0F ) && rx_buffer[ 1 ] && rx_buffer[ 2 ] && rx_buffer[ 3 ] && rx_buffer[ 4 ] ) // Hvis 0x0F er data-startbit'en
      {          
        /*Udkommenteret, da vi kun sender for én sensor af gangen
        if( lastID_ <= rx_buffer[ 1 ] ) // Send og start forfra efter sidste ID
        {
          // Send data (skal implementeres)
          // Til test udskrives det i stedet.
          
          allData.print();
          cout << endl << "----------------------------------------------" << endl << endl;
        }

        // Husk sidste ID
        lastID_ = rx_buffer[ 0 ];*/
        
        // Opret dataobjekt med dynamisk hukommelse
        DataMsg* allData = new DataMsg;
        
        // Nulstil data
        allData.reset();
          
        // Pak til data-struct
        allData.pack( rx_buffer );
        
        // Til test: Udskriv data-struct som pakket
        /*cout << endl << "ID: " << rx_buffer[ 1 ] - 1 << endl
          << "x value: " << ( int )( allData.dataArray_[ rx_buffer[ 1 ] - 1 ].x )
          << ", y value: " << ( int )( allData.dataArray_[ rx_buffer[ 1 ] - 1 ].y )
          << ", z value: " << ( int )( allData.dataArray_[ rx_buffer[ 1 ] - 1 ].z ) << endl;
        
        cout << endl << "----------------------------------------------" << endl << endl;*/
        
        midiQ_->send( DATA_ARRAY, allData );
      }
      
/*      else if( rx_buffer[ 0 ] == 0xF0 ) // Hvis 0xF0 er preset-startbit'en
      {
        //sendData( rx_buffer[ 1 ] );// Send preset til rette modtager
      }*/
    }
  }
}

void Receiver::start(unsigned long loops )
{
  for( int i = 0; i < loops; i++ )
    Receiver::receive();
}