#include "Arduino.h"
#include "Trigger3.h"

Trigger3 trigger3;
Trigger3::Trigger3() : timer(){}

Trigger3& Trigger3::set()
{
    pmc_set_writeprotect(false);
    pmc_enable_periph_clk(TC5_IRQn);           
    TC_Configure(TC1,2,TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK1);
    return *this;
}

Trigger3& Trigger3::start(int triggerPin31,float duration1)
{    
    TC_SetRC(TC1,2,VARIANT_MCK/2*duration1);
    TC1->TC_CHANNEL[2].TC_IER=TC_IER_CPCS;
    TC1->TC_CHANNEL[2].TC_IDR=~TC_IER_CPCS;
    NVIC_EnableIRQ(TC5_IRQn);
	NVIC_ClearPendingIRQ(TC5_IRQn);
    TC1->TC_CHANNEL[2].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
    g_APinDescription[triggerPin31].pPort -> PIO_SODR = g_APinDescription[triggerPin31].ulPin;  
    _triggerPin31=triggerPin31; 
    _triggerPin32=triggerPin31; 
    _triggerPin33=triggerPin31; 
    return *this;
}

Trigger3& Trigger3::start(int triggerPin31,int triggerPin32, float duration1)
{
    TC_SetRC(TC1,2,VARIANT_MCK/2*duration1);
    TC1->TC_CHANNEL[2].TC_IER=TC_IER_CPCS;
    TC1->TC_CHANNEL[2].TC_IDR=~TC_IER_CPCS;
    NVIC_EnableIRQ(TC5_IRQn);
	NVIC_ClearPendingIRQ(TC5_IRQn);  
    g_APinDescription[triggerPin31].pPort -> PIO_SODR = g_APinDescription[triggerPin31].ulPin;  
    g_APinDescription[triggerPin32].pPort -> PIO_SODR = g_APinDescription[triggerPin32].ulPin;  
    TC1->TC_CHANNEL[2].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
    _triggerPin31=triggerPin31; 
    _triggerPin32=triggerPin32;  
    _triggerPin33=triggerPin32;   
    return *this;
}

Trigger3& Trigger3::start(int triggerPin31,int triggerPin32, int triggerPin33, float duration1)
{
    TC_SetRC(TC1,2,VARIANT_MCK/2*duration1);
    TC1->TC_CHANNEL[2].TC_IER=TC_IER_CPCS;
    TC1->TC_CHANNEL[2].TC_IDR=~TC_IER_CPCS;
    NVIC_EnableIRQ(TC5_IRQn);
	NVIC_ClearPendingIRQ(TC5_IRQn);  
    g_APinDescription[triggerPin31].pPort -> PIO_SODR = g_APinDescription[triggerPin31].ulPin;  
    g_APinDescription[triggerPin32].pPort -> PIO_SODR = g_APinDescription[triggerPin32].ulPin;  
    g_APinDescription[triggerPin33].pPort -> PIO_SODR = g_APinDescription[triggerPin33].ulPin;  
    TC1->TC_CHANNEL[2].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
    _triggerPin31=triggerPin31; 
    _triggerPin32=triggerPin32;
    _triggerPin33=triggerPin33;     
    return *this;
}

Trigger3& Trigger3::stop()
{
    g_APinDescription[_triggerPin31].pPort -> PIO_CODR = g_APinDescription[_triggerPin31].ulPin;
    g_APinDescription[_triggerPin32].pPort -> PIO_CODR = g_APinDescription[_triggerPin32].ulPin;
    g_APinDescription[_triggerPin33].pPort -> PIO_CODR = g_APinDescription[_triggerPin33].ulPin;
    TC1->TC_CHANNEL[2].TC_CCR = TC_CCR_CLKDIS;
    NVIC_DisableIRQ(TC5_IRQn);
    TC1->TC_CHANNEL[2].TC_IDR=TC_IER_CPCS;  // disable interrupt
    TC_GetStatus(TC1,2);
    return *this;
}

void TC5_Handler(void)
{
    g_APinDescription[_triggerPin31].pPort -> PIO_CODR = g_APinDescription[_triggerPin31].ulPin;
    g_APinDescription[_triggerPin32].pPort -> PIO_CODR = g_APinDescription[_triggerPin32].ulPin;
    g_APinDescription[_triggerPin33].pPort -> PIO_CODR = g_APinDescription[_triggerPin33].ulPin;
    TC_Stop(TC1, 2);
    NVIC_DisableIRQ(TC5_IRQn);
    TC1->TC_CHANNEL[2].TC_IDR=TC_IER_CPCS;  // disable interrupt
    TC_GetStatus(TC1, 2);
}

