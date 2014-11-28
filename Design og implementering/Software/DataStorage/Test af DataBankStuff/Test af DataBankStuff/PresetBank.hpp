class PresetBank{
	public:
	PresetBank();
	void edit();
	string[] list();
	Preset get();
	
	
	~PresetBank();
	
	private:
	Vector<Preset> presets_
};

class Preset{
	public:
	Preset();
	~Preset();
	
	private:
	Vector<SensorConfiguration*> sensorConfigs_
};
