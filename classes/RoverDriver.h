#ifndef ROVERDRIVER_H
#define ROVERDRIVER_H

#include "mbed.h"
#include "ServoDriver.h"

class RoverDriver {
public:
    // Constructor: Initializes rover with two servos/calibrated stop values
    RoverDriver(PinName leftPin, PinName rightPin, int leftStop, int rightStop, int speedStep = 100);

    // Stop both servos
    void stop();

    // Move rover forward
    void forward();

    // Move rover backward
    void reverse();

    // Rotate rover left in place
    void turnLeft();

    // Rotate rover right in place
    void turnRight();

    // Adjust movement speed (pulse offset)
    void setSpeed(int speedStep);

private:
    ServoDriver leftServo;
    ServoDriver rightServo;
    int speedStepUs;
};

#endif