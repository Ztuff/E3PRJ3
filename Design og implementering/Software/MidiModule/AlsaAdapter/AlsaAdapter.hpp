#ifndef ALSAADAPTER_HPP
#define ALSAADAPTER_HPP


#include <alsa/asoundlib.h>
#include <vector>
#include "../DataBank/MidiSignal.h"
/******************************************************************************************
*bemærk at channel og command skal være chars på formen 'x', hvor x er en enkelt ciffer. */



class AlsaAdapter{
	public:

		//contructor and destructor
		AlsaAdapter(int type);
		~AlsaAdapter();
		
		/**** open function ***************************
		 * This function opens the midiport.
		 * Returns true on succes and false on error.
		 **********************************************/
		bool open();

		/**** send function ***************************
		 * This function send the signals in the null 
		 * terminated array of MidiSignal objects. The 
		 * signals are sent out in the order of the 
		 * array.
		 * Returns true on succes and false on error.
		 **********************************************/
		bool send(const std::vector<MidiSignal>&);


	private:
		/***********************************************
		*variable to determine type of desired midi-direction
		*accepted values are internal / external / both
		*default is internal
		***********************************************/
		int _type;

		/***********************************************
		*midi ports
		************************************************/
		snd_rawmidi_t* midiport_internal;
		snd_rawmidi_t* midiport_external;


};

#endif
