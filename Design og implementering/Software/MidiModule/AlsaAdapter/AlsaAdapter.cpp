#include <alsa/asoundlib.h>
#include "AlsaAdapter.hpp"
#include <iostream>
#include <unistd.h> //for testing

#include <vector>

using namespace std;

//explicit constructor

AlsaAdapter::AlsaAdapter(int type)
{	
	if(type == 1)
	{
		cout << "internal midi chosen" << endl;
		_type = type;

		cout << "_type is set as: " << _type << endl;
	}

	else if(type == 2)
	{
		cout << "external midi chosen" << endl;
		_type = type;

		cout << "_type is set as: " << _type << endl;
	}

	else if(type == 3)
	{
		cout << "internal and external midi chosen" << endl;
		_type = type;

		cout << "_type is set as: " << _type << endl;
	}

	else
	{
		cout << "type not recognised, type set as internal by default." << endl << "valid types are: internal, external, both" << endl;
		_type = 1;

		cout << "_type is set as: " << _type << endl;
	}

	switch (_type)
	{
		case 2 : 	midiport_external = NULL;
							break;

		case 3 :		midiport_external = NULL;
							midiport_internal = NULL;
							break;

		default :			midiport_internal = NULL;
							break;
	}
}

/* function, der aabner midi-port */

bool AlsaAdapter::open() 
{	
	switch (_type)
	{

		case 2 :

			if (snd_rawmidi_open(NULL, &midiport_external,"hw:2,0,0", SND_RAWMIDI_SYNC) < 0) //skal det vaere sync eller append eller en anden?
			{
				cout << "Error opening external MIDI device" << endl;
				return false;
			}

			cout << "external midi opened" << endl;
			break;

		case 3	:

			if (snd_rawmidi_open(NULL, &midiport_external,"hw:2,0,0", SND_RAWMIDI_SYNC) < 0) //skal det vaere sync eller append eller en anden?
			{
				cout << "Error opening external MIDI device" << endl;
				return false;
			}

			cout << "external midi opened" << endl;

			if (snd_rawmidi_open(NULL, &midiport_internal,"hw:1,0,0", SND_RAWMIDI_SYNC) < 0) //skal det vaere sync eller append eller en anden?
			{
				cout << "Error opening internal MIDI device" << endl;
				return false;
			}

			cout << "internal and external midi opened" << endl;

			break;

		default 		:

			if (snd_rawmidi_open(NULL, &midiport_internal,"hw:1,0,0", SND_RAWMIDI_SYNC) < 0) //skal det vaere sync eller append eller en anden?
			{
				cout << "Error opening internal MIDI device" << endl;
				return false;
			}

			cout << "internal midi opened" << endl;

			break;
		}

	return true;
}


bool AlsaAdapter::send(vector<MidiSignal> signal)
{ 
	switch (_type)
	{
		case 2		:

			
			
			for(int i=0; i<signal.size(); i++) 
			{
		

					 char midiMessage[3] = {+signal[i].command + signal[i].channel, signal[i].param1, signal[i].param2}; //husk at command skal være de 4 MSB, så f.eks. 0x90 for noteon, ikke 0x9 

					

					if(snd_rawmidi_write(midiport_external, midiMessage, 3)<0) //det er egentligt en ops write, så den returner -1 ved fejl. Overvej fejlsikring ifb. med antal bytes.
						{
							cout << "Error: rawmidi write to external port failed" << endl;
							return false;
						}
					
			
			}

			break;
			
		

		case 3	:

			for(int i=0; i<signal.size(); i++) //evt noget signal.getlenght? / maxlenght i stedet for 16
			{
					char midiMessage[3] = {(signal[i].command + signal[i].channel), signal[i].param1, signal[i].param2}; //husk at command skal være de 4 MSB, så f.eks. 0x90 for noteon, ikke 0x9


					if(snd_rawmidi_write(midiport_external, midiMessage, 3)<0) //det er egentligt en ops write, så den returner -1 ved fejl. 

						{
							cout << "Error: rawmidi write to external port failed" << endl;
							return false;
						}
					if(snd_rawmidi_write(midiport_internal, midiMessage, 3)<0) //det er egentligt en ops write, så den returner -1 ved fejl. 

						{
							cout << "Error: rawmidi write to internal port failed" << endl;
							return false;
						}
			}

			
			break;
	
		

		default	:

			for(int i=0; i<signal.size(); i++) //evt noget signal.getlenght? / maxlenght i stedet for 16
			{
				char midiMessage[3] = {(signal[i].command + signal[i].channel), signal[i].param1, signal[i].param2}; //husk at command skal være de 4 MSB, så f.eks. 0x90 for noteon, ikke 0x9 
				if(snd_rawmidi_write(midiport_internal, midiMessage, 3)<0) //det er egentligt en ops write, så den returner -1 ved fejl. 

						{
							cout << "Error: rawmidi write to external port failed" << endl;
							return false;
						}
			}

			break;
		}

	return true;
}

//destructor. midiportene lukkes og pointerne sættes til null. 

AlsaAdapter::~AlsaAdapter()
{
	switch (_type)
	{
		case 2 : 	snd_rawmidi_close(midiport_external);
							midiport_external = NULL;
							break;

		case 3 :		snd_rawmidi_close(midiport_external);
							snd_rawmidi_close(midiport_internal);
							midiport_external = NULL;
							midiport_internal = NULL;
							break;

		default :			snd_rawmidi_close(midiport_internal);
							midiport_internal = NULL;
							break;
	}
}


int main()
{

	

	MidiSignal testsignalKEY, prim, terts, kvint; 

	testsignalKEY.command = 0x90;
	testsignalKEY.channel = 0x00;
	testsignalKEY.param1 = 60;

	prim.command = 0x90;
	terts.command = 0x90;
	kvint.command = 0x90;

	prim.channel = 0x00;
	terts.channel = 0x00;
	kvint.channel = 0x00;

	prim.param2 = 100;
	terts.param2 = 100;
	kvint.param2 = 100;

	AlsaAdapter adapter1(2);

	adapter1.open();

	vector<MidiSignal> testVector;

	while(true)
	{
		for(int i = 0 ; i < 4 ; i++)
		{
			for(int key = 48; key < 85 ; key++)
				{
					testsignalKEY.param2 = key;
					testsignalKEY.param1 = key;
					testVector.push_back(testsignalKEY);	
					adapter1.send(testVector);
					testVector.pop_back();
					usleep(20000);
					

					testsignalKEY.param2 = 0;
					testVector.push_back(testsignalKEY);	
					adapter1.send(testVector);
					testVector.pop_back();
					if(key == 84)
					{
						for(int key = 83; key > 48 ; key--)
							{
								testsignalKEY.param2 = key;
								testsignalKEY.param1 = key;
								testVector.push_back(testsignalKEY);	
								adapter1.send(testVector);
								testVector.pop_back();
								usleep(20000);
								

								testsignalKEY.param2 = 0;
								testVector.push_back(testsignalKEY);	
								adapter1.send(testVector);
								testVector.pop_back();
								}

					}

				}
			}

		
			prim.param1 = 33;
			terts.param1 = 35;
			kvint.param1 = 38;
			
			testVector.push_back(prim);

			adapter1.send(testVector);

			testVector.pop_back();

			usleep(1000000);

			testVector.push_back(terts);

			adapter1.send(testVector);

			testVector.pop_back();

			usleep(1000000);

			testVector.push_back(kvint);

			adapter1.send(testVector);

			testVector.pop_back();

			usleep(1000000);
		
			prim.param2 = 0;
			terts.param2 = 0;
			kvint.param2 = 0;

			testVector.push_back(prim);
			testVector.push_back(terts);
			testVector.push_back(kvint);

			adapter1.send(testVector);

			testVector.pop_back();
			testVector.pop_back();
			testVector.pop_back();



			prim.param1 = 38;
			terts.param1 = 41;
			kvint.param1 = 33;
			
			testVector.push_back(prim);

			adapter1.send(testVector);

			testVector.pop_back();

			usleep(1000000);

			testVector.push_back(terts);

			adapter1.send(testVector);

			testVector.pop_back();

			usleep(1000000);

			testVector.push_back(kvint);

			adapter1.send(testVector);

			testVector.pop_back();

			usleep(1000000);
		
			prim.param2 = 0;
			terts.param2 = 0;
			kvint.param2 = 0;

			testVector.push_back(prim);
			testVector.push_back(terts);
			testVector.push_back(kvint);

			adapter1.send(testVector);

			testVector.pop_back();
			testVector.pop_back();
			testVector.pop_back();

		/*testsignalKEY.param2 = 100;
		testVector.push_back(testsignalKEY);	
		adapter1.send(testVector);
		testVector.pop_back();
		usleep(20000);
		

		testsignalKEY.param2 = 0;
		testVector.push_back(testsignalKEY);	
		adapter1.send(testVector);
		testVector.pop_back();*/
		
		

	}

	return 1;
}

