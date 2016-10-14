//NuMaker-PFM-NUC472 PWM0 output note to a speaker
#include "mbed.h"

#define _C5   523  // C5      =  523.25Hz
#define _D5   587  // D5      =  587.33Hz
#define _E5   659  // E5      =  659.26Hz
#define _F5   698  // F5      =  698.46Hz
#define _G5   784  // G5      =  783.99Hz
#define _A5   880  // A5      =  880.00Hz
#define _B5   988  // B5      =  987.77Hz
#define _C6   1046 // C6      = 1046.50Hz
#define _D6   1175 // D6      = 1174.66Hz
#define _E6   1319 // E6      = 1318.51Hz
#define _F6   1397 // F6      = 1396.91Hz
#define _G6   1568 // G6      = 1567.98Hz
#define _A6   1760 // A6      = 1760.00Hz
#define _B6   1976 // B6      = 1975.53Hz

PwmOut pwm0(PF_9); // PWM0 pin 

int main()
{
        int i =0;
        int note[15] = { // array of notes
        _C5, _D5, _E5, _F5, _G5, _A5, _B5,         
        _C6, _D6, _E6, _F6, _G6, _A6, _B6};
        
        for (i=0; i<14; i++) {
            pwm0.period_us(1000000/note[i]);       // set period per note
            pwm0.pulsewidth_us(1000000/note[i]/2); // set duty cycle to 50%
            Thread::wait(100);
        }
        pwm0.pulsewidth_us(0); // set dutycycle = 0% to stop
}
