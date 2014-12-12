#include "Receiver.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
  Receiver rcv;  for(;;)
  {
    rcv.receive();
    sleep( 1 );
  }
}