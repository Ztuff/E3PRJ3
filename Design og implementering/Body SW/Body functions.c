#define MAXREGNUM 144

int numOfRegToRead = 0;	//current number of initialized sensors

int sensArray[MAXSENSKONFNUM][3];	//Array containing {sensNum, I2CAdress, RegisterToRead}

int main()
{
	initSensors();
	
	while(1)
		readAllSensors();
		
	return 0;
}

void initSensors()
{	
	/***** INIT INDIVIDUAL SENSORS *****/
	initMPU6050();	//Gyroscope
	initADXL345();	//Accellerometer
	// ..osv
}

void setSensArray(int deviceAdress, int registerToRead, int &dataTarget)
{
	sensArray[numOfRegToRead][0]=deviceAdress;		//set device adress
	sensArray[numOfRegToRead][1]=registerToRead;	//set register for future read
	sensArray[numOfRegToRead][2]=dataTarget;		//set where to save read data
	++numOfRegToRead;								//increment current number of places in array that are set
}

int readAllSensors()
{
	for (int i = 0; i < numOfRegToRead; i++)
	{
		readSensor(i);
	}
}

int readSensor(int i)
{
	sendI2C(sensArray[i][0], sensArray[i][1]);	// (DeviceAdress, RegisterToRead)
}

int sendI2C(int deviceAdress, int registerToRead, int dataTarget)
{
	
}

