#ifndef ROVERDRIVER_H
#define ROVERDRIVER_H

#include "mbed.h"
#include "ServoDriver.h"
#include "IDriver.h"

class RoverDriver : public IDriver {
public:
    // Constructor: Initializes rover with two servos/calibrated stop values
    RoverDriver(PinName leftPin, PinName rightPin, int leftStop, int rightStop, int speedStep = 100);

    // Stop both servos
    void stop() override;

    // Move rover forward
    void forward() override;

    // Move rover backward
    void reverse() override;

    // Rotate rover left in place
    void turnLeft() override;

    // Rotate rover right in place
    void turnRight() override;

    // Adjust movement speed (pulse offset)
    void setSpeed(int speedStep);

private:
    ServoDriver leftServo;
    ServoDriver rightServo;
    int speedStepUs;
};

#endif