struct MidiSignal{
	uint8_t channel;
	uint8_t command;
	uint8_t param1;
	uint8_t param2;
};

class AlsaAdapter{
	public:
		//contructor and destructor
		AlsaAdapter();
		~AlsaAdapter();
		
		/**** send function ***************************
		 * This function send the signals in the null 
		 * terminated array of MidiSignal objects. The 
		 * signals are sent out in the order of the 
		 * array.
		 * Returns true on succes and false on error.
		 **********************************************/
		bool send(MidiSignal[] signals);
};

