#ifndef MIDI_MODULE_HPP
#define MIDI_MODULE_HPP

#include "MidiSignal.h"
#include "MappingScheme.h"
#include "SensorConfigurationBank.hpp"
#include <linux/wait.h>
#include <linux/schedule>
#include <vector>
#include <iostream>
#include <list>
#include "AlsaAdapter.hpp"

using namespece std;

static int wqFlag = 0;						

DECLARE_WAIT_QUEUE_HEAD(wq);				//Wait queue declaration
 
class MidiModule{

	public:

		MidiModule();
		~MidiModule();

		list<SensorConfiguration>::iterator createSensorConfList();

		bool sendVector();  //Void?

		void startTimer();

		void timerFunct();

		void handleTick();

	private:

		vector<MidiSignal> midiSignalVector_;
		list<SensorConfiguration> sensorConfList_;
		unsigned int timeout_in_milliseconds_;
		struct timer_list my_timer_;
		bool stop_;	
		AlsaAdapter* alsaAdapter_;




};

#endif