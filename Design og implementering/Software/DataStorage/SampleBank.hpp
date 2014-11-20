#include <string>

class SampleBank
{
	public:
	Sample();
	string[] list();
	SoundPack get(); //Hvilken lydpakke vil du gerne have?
	void add(SoundPack);
	void remove(SoundPack);
	void save();
	~SampleBank{();
	
	private:
	map<SoundPack> lydPakker_;
}

class SoundPack
{
	public:
	string filepath_;
	SoundPack(filepath);
	~SoundPack();
}