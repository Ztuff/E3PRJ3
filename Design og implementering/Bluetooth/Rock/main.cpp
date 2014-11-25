#include "Receiver.hpp"

using namespace std;

int main()
{
  Receiver rcv;
  rcv.send();
  for(;;)
    rcv.receive();
}