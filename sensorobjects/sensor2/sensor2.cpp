#include "Arduino.h"
#include "sensor2.h"

sensor2* sensor2::pntr = NULL;

sensor2::sensor2(int sensorPin, int eventCodeIn, int eventCodeOut)
{
	_sensorPin=sensorPin; 
    _eventCodeIn=eventCodeIn;
    _eventCodeOut=eventCodeOut;
    pinMode(_sensorPin, INPUT);
    pntr = this;	   
}

void sensor2::activate()  
{   
    attachInterrupt(digitalPinToInterrupt(_sensorPin), sensor2::go_to_intfunc, CHANGE);
    eventStatus=0; 
}

void sensor2::deactivate()  
{  
    detachInterrupt(_sensorPin); 
}

void sensor2::go_to_intfunc()
{
	pntr->sensorfunction();
}
					

void sensor2::sensorfunction()	
{  
    eventTime=millis();
    if (!!(g_APinDescription[_sensorPin].pPort -> PIO_PDSR & g_APinDescription[_sensorPin].ulPin)==HIGH){eventStatus=_eventCodeOut; eventCode=_sensorPin;}
	if (!!(g_APinDescription[_sensorPin].pPort -> PIO_PDSR & g_APinDescription[_sensorPin].ulPin)==LOW){eventStatus=_eventCodeIn; eventCode=_sensorPin;}
}

