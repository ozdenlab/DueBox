
////////////////////////////////////////////////////////////
void wait(double time2wait)
{
    double t=millis();
    while ((millis()-t)<time2wait){}
}

////////////////////////////////////////////////////////////
void toggle(int pin)
{
    if(!!(g_APinDescription[pin].pPort -> PIO_PDSR & g_APinDescription[pin].ulPin)) g_APinDescription[pin].pPort -> PIO_CODR = g_APinDescription[pin].ulPin;
    else    g_APinDescription[pin].pPort -> PIO_SODR = g_APinDescription[pin].ulPin;
}

////////////////////////////////////////////////////////////
void trigger(int pin1, float dur1)
{
    toggle(pin1);
    delayMicroseconds(dur1*1000000);
    toggle(pin1);
}

////////////////////////////////////////////////////////////

void trigger(int pin1, float dur1, int pin2, float dur2)
{
    if (dur1==dur2)
    {
        toggle(pin1); toggle(pin2);
        delayMicroseconds(dur1*1000000);
        toggle(pin1); toggle(pin2);
    }
    else if(dur1<dur2)
    {
        toggle(pin1); toggle(pin2);
        delayMicroseconds(dur1*1000000);
        toggle(pin1); 
        delayMicroseconds((dur2-dur1)*1000000);
        toggle(pin2);
    }

    else
    {
        toggle(pin2); toggle(pin1);
        delayMicroseconds(dur2*1000000);
        toggle(pin2); 
        delayMicroseconds((dur1-dur2)*1000000);
        toggle(pin1);
    }
}

////////////////////////////////////////////////////////////

void trigger(int pin1, float dur1, int pin2, float dur2, int pin3, float dur3)
{
    if (dur1==dur2 && dur1==dur3)
    {
        toggle(pin1); toggle(pin2); toggle(pin3);
        delayMicroseconds(dur1*1000000);
        toggle(pin1); toggle(pin2); toggle(pin3);
    }
    else if(dur1==dur2 && dur1<dur3)
    {
        toggle(pin1); toggle(pin2); toggle(pin3);
        delayMicroseconds(dur1*1000000);
        toggle(pin1); toggle(pin2);
        delayMicroseconds((dur3-dur1)*1000000);
        toggle(pin3);
    }

    else if(dur1<dur2 && dur2==dur3)
    {
        toggle(pin1); toggle(pin2); toggle(pin3);
        delayMicroseconds(dur1*1000000);
        toggle(pin1); 
        delayMicroseconds((dur2-dur1)*1000000);
        toggle(pin2); toggle(pin3);
    }

    else
    {
        toggle(pin1); toggle(pin2); toggle(pin3);
        delayMicroseconds(dur1*1000000);
        toggle(pin1); 
        delayMicroseconds((dur2-dur1)*1000000);
        toggle(pin2);
        delayMicroseconds((dur3-dur2)*1000000);
        toggle(pin3);
    }
}

////////////////////////////////////////////////////////////