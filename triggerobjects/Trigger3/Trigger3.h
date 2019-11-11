
#ifndef Trigger3_h
#define Trigger3_h
#endif

#include "Arduino.h"

class Trigger3
{
  private:
    const unsigned short timer;
    friend void TC5_Handler(void);
    float _duration1;
    
  public:
    Trigger3(void);
    Trigger3& set();
    Trigger3& start(int, float);
    Trigger3& start(int, int, float);
    Trigger3& start(int, int, int, float);
    Trigger3& stop(); 
};

extern Trigger3 trigger3;
extern volatile int _triggerPin31;
extern volatile int _triggerPin32;
extern volatile int _triggerPin33;

