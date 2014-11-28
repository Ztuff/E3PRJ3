#ifndef CAR_HPP
#define CAR_HPP

#include <osapi/ThreadFunctor.hpp>
#include <osapi/MsgQueue.hpp>
#include <osapi/Utility.hpp>
#include "SyncPrint.hpp"
#include "Guard.hpp"

class Guard;

class Car : public osapi::ThreadFunctor
{
	public:
		Car(int id, Guard* entryG, Guard* exitG, 
				SyncPrint* sPrint, int numTimesToShop = 2, int waitTime = 5);
		~Car();
		osapi::MsgQueue* getMsgQueue();
		virtual void run();
		
		enum TypeId{
			ENTRY_GRANTED,
			EXIT_GRANTED
		};
		
	private:
		void handleEntryGranted();
		void handleExitGranted();
		
		int id;
		osapi::MsgQueue msgQ;
		osapi::MsgQueue* entryMsgQ;
		osapi::MsgQueue* exitMsgQ;
		SyncPrint* sPrint;
		int timesShopped;
		bool active;
		const int numTimesToShop;
		const int waitTime;
};

#endif
