#ifndef Pulses1_h
#define Pulses1_h
#endif

#include "Arduino.h"

class Pulses1
{
  private:
    const unsigned short timer;
    friend void TC7_Handler(void);
    friend void TC8_Handler(void);
    float _frequency;
    float _pulsedur;
    float _duration;
    
  public:
    Pulses1(void);
    Pulses1& set(float,float,float);
    Pulses1& start();
    Pulses1& stop(); 
};

extern Pulses1 pulses1;


