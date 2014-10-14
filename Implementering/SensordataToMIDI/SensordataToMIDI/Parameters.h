struct singleNote{
	int root; // A, A#, B, C, C#, D, D#, E, F, F#, G, G#
			  // 0,  1, 2, 3,  4, 5,  6, 7, 8,  9, 10, 11
	int octave; // -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8
	string velocity; // line�r, logaritmisk, eksponentiel, ful(?)
	unsigned char sensorData; //v�rdi fra 0-127 (anslagskraft i dette tilf�lde)
	int lowerThreshold; //t�rskelv�rdi der bestemmer hvor h�rdt man skal sl�
						//f�r v�rdien bliver anset som st�rk nok til at skulle generere en tone.
};

struct continuousNote{
	int root;
	string scale; //cromatic, major, minor
	string direction; //rising, falling
	unsigned char sensorData;
};

struct ccAbs{	//Control Change Absolute (skifter med det samme)
	int minVal; // 0-127
	int maxVal; // 0-127
	unsigned char sensorData;
};

struct ccRel{
	string speed; //SLow, Medium & Fast.
	unsigned char sensorData;
};