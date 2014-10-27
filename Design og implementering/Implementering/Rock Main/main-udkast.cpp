//#include "MIDIGen.h"

int main()
{
	/*
	- Opret en tråd (sensToMidi) for hver sensorKonfiguration.
	SensorData:
		1: Main får en struct af 'Bluetooth Rock'.
		2: Hvilken sensor er det fra? Tjekkes ved sensorID.
		3: Sendes til sensToMIDI.
	- Opret en tråd for QT GUI-modulet.
	- Opret en tråd for BluetoothRock
	- Nødvendigt med tråd for sampleLibrary? Don't think so.
	*/
	
}

MIDIOut sensToMIDI(struct sensorStruct sStruct)
{
	//En hver sensorKonfiguration har tilknyttet en MIDIgen
	//MIDIGeneratoren outputter MIDI til Linuxsampleren
}

void BluetoothRock()
{
	//BluetoothRock sender en sensorStruct til controlleren(this)
	//SensorSructen sendes videre til pågældende sensToMIDI-tråd jf. sensorID.
}

void sampleLibrary()
{
	//Står for at sende et LsSample videre til Linux Sampleren. 
	//Linux Sampleren forbinder MIDI-out med sample der giver et lyd output.
}