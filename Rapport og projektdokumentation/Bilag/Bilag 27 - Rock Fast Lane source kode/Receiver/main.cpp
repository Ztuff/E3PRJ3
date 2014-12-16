#include "Receiver.hpp"
#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
  Receiver rcv;
  rcv.start( 10000 );
}