#include "SampleBank.hpp"
#include <vector>
#include <string>

using namespace std; 
int main()
{
	SampleBank sb;
	sb.add("test.mp3");
	SoundPack testSoundPack = sb.get("test.mp3");
	vector<string> testVector = sb.list();
	return 0;
}