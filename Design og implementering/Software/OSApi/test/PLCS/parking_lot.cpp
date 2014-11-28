#include <iostream>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#include <osapi/MsgQueue.hpp>
#include <osapi/Thread.hpp>
#include <osapi/Utility.hpp>
#include <osapi/Mutex.hpp>
#include "SyncPrint.hpp"
#include "Car.hpp"
#include "Guard.hpp"


#define NUM_CARS 2
#define NUM_REPEATS 2
#define WAIT_TIME 3
#define MAX_NUM_CARS 2

using namespace std;
using namespace osapi;

int main(void){
 	srand(time(NULL));
 	SyncPrint* sp = new SyncPrint();
 	
 	Guard entryGuard(NULL, sp);
 	Guard exitGuard(entryGuard.getMsgQueue(), sp);
 	Car* cars[NUM_CARS];
 	for(int i = 0; i < NUM_CARS; i++){
 		cars[i] = new Car(i, &entryGuard, &exitGuard, sp, NUM_REPEATS, WAIT_TIME);
 	}
 	
 	Thread* threads[NUM_CARS + 2];
 	threads[0] = new Thread(&entryGuard, Thread::PRIORITY_NORMAL, "EntryGuard Thread", true);
 	threads[1] = new Thread(&exitGuard, Thread::PRIORITY_NORMAL, "ExitGuard Thread", true);
 	for(int i = 2; i < NUM_CARS + 2; i++){
 		threads[i] = new Thread((cars[i - 2]), Thread::PRIORITY_NORMAL, "Car Thread", true);
 	}
 	
 	for(int i = 2; i < NUM_CARS + 2; i++){
 		threads[i]->join();
 	}
 	entryGuard.getMsgQueue()->send(Guard::SHUTDOWN, NULL);
 	exitGuard.getMsgQueue()->send(Guard::SHUTDOWN, NULL);
 	
 	threads[0]->join();
 	threads[1]->join();
 	
  	return 0;
}
