#include "Arduino.h"
#include "Pulses1.h"

Pulses1 pulses1;
Pulses1::Pulses1() : timer(){}

Pulses1& Pulses1::set(float frequency, float pulsedur, float duration)
{
    pmc_set_writeprotect(false);
    pmc_enable_periph_clk(TC7_IRQn);           
    TC_Configure(TC2,1,TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_TCCLKS_TIMER_CLOCK1);
    TC_SetRC(TC2,1,VARIANT_MCK/2*duration/1000);
  
    pmc_enable_periph_clk(35); //pin 11, XC2:30
    pmc_enable_periph_clk(TC8_IRQn);
    REG_PMC_PCER1 |= PMC_PCER1_PID35;                
    REG_PIOD_ABSR |= PIO_ABSR_P7;     
    REG_PIOD_PDR |= PIO_PDR_P7;          
    TC_Configure(TC2,2,TC_CMR_WAVE | TC_CMR_WAVSEL_UP_RC | TC_CMR_ACPA_CLEAR | TC_CMR_ACPC_SET | TC_CMR_ASWTRG_SET | TC_CMR_TCCLKS_TIMER_CLOCK1);  
    TC_SetRC(TC2,2, VARIANT_MCK/2/frequency);
    _pulsedur=VARIANT_MCK/2*pulsedur/1000;
    TC_SetRA(TC2,2,_pulsedur);
    
}

Pulses1& Pulses1::start()
{    
    TC2->TC_CHANNEL[2].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
    TC2->TC_CHANNEL[1].TC_IER=TC_IER_CPCS;
    TC2->TC_CHANNEL[1].TC_IDR=~TC_IER_CPCS;
    NVIC_EnableIRQ(TC7_IRQn);
	NVIC_ClearPendingIRQ(TC7_IRQn);
    TC2->TC_CHANNEL[1].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;
    return *this;
}

Pulses1& Pulses1::stop()
{
    while (TC2->TC_CHANNEL[2].TC_CV<=_pulsedur) {}     
    TC_Stop(TC2,1); 
    TC_Stop(TC2,2);
    NVIC_DisableIRQ(TC7_IRQn);
    TC2->TC_CHANNEL[1].TC_IDR=TC_IER_CPCS;  // disable interrupt   
    TC_GetStatus(TC2, 1);
    return *this;
}



void TC7_Handler() 
{   
    TC_GetStatus(TC2, 1);
    pulses1.stop();
}


void TC8_Handler() {TC_GetStatus(TC2, 2);}