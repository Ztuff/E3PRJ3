#include "BTRock.hpp"

using namespace std;

int main()
{
  BTRock bt;
  bt.send();
  for(;;)
    bt.receive();
}