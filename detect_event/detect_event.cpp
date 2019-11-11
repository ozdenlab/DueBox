#include "Arduino.h"
#include "detect_event.h"

detect_event detect;
detect_event::detect_event() : timer(){}

int detect_event::start(int sensorPin,float duration)
{
    pmc_set_writeprotect(false);
    pmc_enable_periph_clk(TC2_IRQn);           
    TC_Configure(TC0,2,TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK4);
    TC_SetRC(TC0,2, VARIANT_MCK/128*duration);
    TC0->TC_CHANNEL[2].TC_IER=TC_IER_CPCS;
    TC0->TC_CHANNEL[2].TC_IDR=~TC_IER_CPCS;
    NVIC_EnableIRQ(TC2_IRQn);
	NVIC_ClearPendingIRQ(TC2_IRQn);
    TC_GetStatus(TC0,2);
	TC_Start(TC0,2);
    eventDuration=millis();  
    eventCode=1; 
    while (eventCode!=0 && eventCode!=sensorPin)
    {  
    }
    eventDuration=millis()-eventDuration;
    stop();
	return eventCode;
}

detect_event& detect_event::stop()
{
    TC_Stop(TC0, 2);
    NVIC_DisableIRQ(TC2_IRQn);
    TC0->TC_CHANNEL[2].TC_IDR=TC_IER_CPCS;  // disable interrupt
    TC_GetStatus(TC0,2);
    return *this;
}

void TC2_Handler(void)
{
	TC_GetStatus(TC0, 2);
    eventCode=0;
}

