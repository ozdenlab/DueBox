#ifndef sensor2_h
#define sensor2_h
#endif

#include "Arduino.h"

class sensor2
{
	public:
		sensor2(int sensorPin, int eventCodeIn, int eventCodeOut);          
		void activate(); 
        void deactivate();   
         					
	private:
		static void go_to_intfunc();  
		void sensorfunction();								
		int _sensorPin; 
		int _eventCodeIn; 
		int _eventCodeOut; 
		static sensor2* pntr;  
};

// extern double event_log[1000][6];
// extern int event_num;
extern volatile int eventCode;
extern volatile int eventStatus;
extern volatile double eventTime;