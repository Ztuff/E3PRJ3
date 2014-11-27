#include <linux/schedule>
#include <linux/wait.h>
#include <list>
#include "SensorConfiguration.h"
#inlude "MidiSignalVectorInit.h"

using namespace std;

unsigned int timeout_in_milliseconds = 20;	//50 times per second = 20 ms
struct timer_list my_timer;
static int wqFlag = 0;						//Flag til wq. Kan dette gøres lettere?!
bool mute = 0;								//bruges ved senere implementering af "mute" på systemet

DECLARE_WAIT_QUEUE_HEAD(wq);				//Wait queue declaration

int main()
{ 
	/** Vi går ud fra, der er oprettet en liste indeholdende
		SensorKonfigurationer:
		
	list<SensKonfiguration> myList;
	husk initDataAndVector
	osv.. */
	
	unMute();	//igangsætter timer

	while(;;)
	{
		do 
		{
			wait_event_interruptible_timeout(wq, wqFlag !=0);	//Wait for next timer tic.
			wqFlag = 0;											//nultstil wq flag
			handleTick(myList);
		}while(!mute)
	
		//Stop all MidiSignals 	
	}
	
	return 0;
}
void unMute()	// Sets up timer
{
	init_timer(&my_timer); 
	my_timer.expires = jiffies + timeout_in_sec*HZ; 
	my_timer.function = timer_funct; 
	add_timer(&my_timer);
}

void timer_funct()
{
	my_timer.expires = jiffies + timeout_in_milliseconds*HZ;    //Re-schedule the timer 
	add_timer(&my_timer);                					 	//Add to timer queue
	
	wqFlag = 1;
	wake_up_interruptible(&wq);
}

void handleTick(list<SensKonfiguration> myList)
{
	handleQueue();
	
	int data = 0;
	
	for (list<SensKonfiguration>::iterator i = myList.begin(); i != myList.end(); ++i)	//Iterate through sensor konfigurations
	{
		switch ((i*).accis)	//Find correct data in dataArray
		{
			case 'x'
				data = dataArray[(i*).ID].x;
				break;
			case 'y'
				data = dataArray[(i*).ID].y;
				break;
			case 'z'
				data = dataArray[(i*).ID].z;
				break;
			default:
				data = dataArray[(i*).ID].x;
				break;
		}
		
		(i*).MappingScheme.map(data,(i*).MidiIter*);		/* 	Prototype: bool map(int data, MidiSignal & signal);
																alder map i den givne SensKonfigurations MappingScheme
																og giver den datapunkt jf. i SensKonfiguration indstillet sensor
																og vectorplads jf indstillet  i SensKonfiguration indstillet vectorplads */
																
	}	
}

void SensKonfiguration::initDataAndVector(int[] &dataArray, vector<MidiSignal> &midiVec)
{
	/*** set place in dataArray ***/
	/*** Få Felix, Mathias og Kristoffer til at lave det ***/
	
	MidiIter = MidiSignalVectorAdd(midiVec, 1)	/*	MidiIter er attribut i SensorKonfiguration
													MidiSignalVectorAdd returnerer iterator til den nye sidste plads i vector
													og modtager parametrene(vector&, #nyePladser) */
	
}


/*ISR(ved pause)
{
	pause = 1
	wakeUpFromSleep();
}

ISR(ved unpause)
{
	pause = 0;
	unMute();
}*/

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Handling of system timer tick in BodyRock3000");
MODULE_AUTHOR("LukasHedegaard"); 