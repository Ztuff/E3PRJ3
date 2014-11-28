#include "Receiver.hpp"
#include <iostream>

using namespace std;

int main()
{
  Receiver rcv;  for(;;)
    rcv.receive();
}