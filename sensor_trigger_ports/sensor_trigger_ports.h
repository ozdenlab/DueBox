
#ifndef sensor_trigger_ports_h
#define sensor_trigger_ports_h
#endif

#include "Arduino.h"

// SENSORS
#define pinOdorPortSensor 31
#define pinWaterPortSensorLeft 32 
#define pinWaterPortSensorRight 33 

//CONTROLS
#define pinAirValve 52 
#define pinOdor1Valve 51 
#define pinOdor2Valve 50 
#define pinOdor3Valve 49 
#define pinOdor4Valve 48
#define pinFinalValve 44
#define pinWaterDeliveryLeft 47 
#define pinWaterDeliveryRight 46
#define pinBeep 34 
#define pinBuzz 35
#define pinLaser 36 


volatile int air=pinAirValve;
volatile int odor1=pinOdor1Valve;
volatile int odor2=pinOdor2Valve;
volatile int odor3=pinOdor3Valve;
volatile int odor4=pinOdor4Valve;
volatile int finalValve=pinFinalValve;
volatile int waterDeliveryRight=pinWaterDeliveryRight;
volatile int waterDeliveryLeft=pinWaterDeliveryLeft;
volatile int beep=pinBeep;
volatile int buzz=pinBuzz;


void set_all()
{
    pinMode(air, INPUT);
    pinMode(odor1, INPUT);
    pinMode(odor2, INPUT);
    pinMode(odor3, INPUT);
    pinMode(odor4, INPUT);
    pinMode(finalValve, INPUT);
    pinMode(waterDeliveryRight, INPUT);
    pinMode(waterDeliveryLeft, INPUT);
    pinMode(beep, INPUT);
    pinMode(buzz, INPUT);
    
    pinMode(air, OUTPUT);
    pinMode(odor1, OUTPUT);
    pinMode(odor2, OUTPUT);
    pinMode(odor3, OUTPUT);
    pinMode(odor4, OUTPUT);
    pinMode(finalValve, OUTPUT);
    pinMode(waterDeliveryRight, OUTPUT);
    pinMode(waterDeliveryLeft, OUTPUT);
    pinMode(beep, OUTPUT);
    pinMode(buzz, OUTPUT);
}
