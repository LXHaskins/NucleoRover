#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include "mbed.h"

class UltrasonicSensor {
public:
    // Constructor
    UltrasonicSensor(PinName trigPin, PinName echoPin, int maxDistanceCm = 200);

    // Send ping and return echo time (microseconds), or -1 on timeout
    int pingUs();

    // Send ping and return measured distance (centimeters), or -1 on timeout
    int pingCm();

private:
    DigitalOut trig;
    DigitalIn echo;
    Timer timer;
    int maxDistance;
};

#endif