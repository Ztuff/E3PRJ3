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

using namespece std;

static int wqFlag = 0;						

DECLARE_WAIT_QUEUE_HEAD(wq);				//Wait queue declaration
 
class MidiModule{

	public:

		MidiModule();
		~MidiModule();

		list<SensorConfiguration>::iterator createSensorConfList();

		bool send();  //Void?

		void startTimer();

		void timerFunct();

		void handleTick();

	private:

		vector<MidiSignal> midiSignalVector_;
		list<SensorConfiguration> sensorConfList;
		unsigned int timeout_in_milliseconds;
		struct timer_list my_timer;
		bool stop;	



};

#endif