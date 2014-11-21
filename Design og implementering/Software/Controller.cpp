void Controller::start()
{
	pthread_create(&threadHandle, NULL, 
			Controller::eventDispatcher, NULL);
	
