void Controller::start()
{
  int Ct = pthread_create(&threadHandle, NULL,Controller::eventDispatcher, NULL)
  if( Ct != 0)
  {
    BR3K_error(Ct, "Error: Couldn't create controller thread");
  }
}

void Controller::join()
{
  int Cj = pthread_join(&threadHandle, NULL);
  if( Cj != 0)
  {
    BR3K_error(Cj, "Error: Couldn't join controller thread");
  }
}
	
