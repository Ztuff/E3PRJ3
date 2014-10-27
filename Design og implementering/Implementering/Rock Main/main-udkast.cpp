//#include "MIDIGen.h"
#include <pthread.h>
int main()
{
	//- Opret en tråd (sensToMidi) for hver sensorKonfiguration.
	amountOfSensors = 16 //Denne værdi skal assignes fra et preset
	pthread_t sensorThread[amountOfSensors];
	for (int i = 0; i < amountOfSensors; i++)
	{
		pthread_create(&sensorThread[i], NULL, sensToMidi);//, sidste argument?? struct? preset?);
	}
	
	//SensorData:
	//	1: Main får en struct af 'Bluetooth Rock'.
	//	2: Hvilken sensor er det fra? Tjekkes ved sensorID.
	//	3: Sendes til sensToMIDI.
	
	//- Opret en tråd for QT GUI-modulet.
	
	//- Opret en tråd for BluetoothRock
	pthread_t BTRockThread;
	pthread_create(&BTRockThread, NULL, BluetoothRock); // Argument?
	//- Nødvendigt med tråd for sampleLibrary? Don't think so.
	
	//Join tråde
	pthread_join(BTRockThread, NULL, BluetoothRock); //Argument?
	for (int i = 0; i < amountOfSensors; i++)
	{
		pthread_join(sensorThread[i], NULL, sensToMidi);//, sidste argument);
	}
	return 0;
}

void sensToMIDI(struct sensorStruct sStruct)
{
	//En hver sensorKonfiguration har tilknyttet en MIDIgen
	//MIDIGeneratoren outputter MIDI til Linuxsampleren
	//Tænker at denne metode køres og kalder Linuxsampleren til sidst.
	//Fx:
	
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

//Noget med GUI?