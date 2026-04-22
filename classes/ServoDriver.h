#ifndef SERVODRIVER_H
#define SERVODRIVER_H

#include "mbed.h"

class ServoDriver {
public:
    ServoDriver(PinName pin, int stopPulse = 1500, int speedStep = 100);

    void setStopPulse(int stopPulse);
    int getStopPulse() const;

    void setSpeedStep(int speedStep);
    int getSpeedStep() const;

    void stop();

    void forward();
    void reverse();

    void forward(int offset);
    void reverse(int offset);

    void writePulse(int pulseWidthUs);

private:
    PwmOut servo;
    int stopPulseUs;
    int speedStepUs;
};

#endif