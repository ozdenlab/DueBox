#ifndef Pulses2_h
#define Pulses2_h
#endif

#include "Arduino.h"

class Pulses2
{
  private:
    const unsigned short timer;
    friend void TC0_Handler(void);
    friend void TC6_Handler(void);
    float _frequency;
    float _pulsedur;
    float _duration;
    
  public:
    Pulses2(void);
    Pulses2& set(float,float,float);
    Pulses2& start();
    Pulses2& stop(); 
};

extern Pulses2 pulses2;


