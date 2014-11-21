class MidiMappingScheme{
	public:
		MidiMappingScheme();
		~MidiMappingScheme();
		/***** map function ***************************
		 * This function maps the given sensor data
		 * into the given signal. The function will
		 * only change the relevant parameters of the
		 * signal.If the input signal has empty fields
		 * when the process is done, the function will
		 * fill these with default values before
		 * returning.
		 **********************************************/
		void map(SensorData data, MidiSignal& signal);
} 
