#include "RoverDriver.h"

// Constructor
RoverDriver::RoverDriver(PinName leftPin, PinName rightPin, int leftStop, int rightStop, int speedStep)
    : leftServo(leftPin, leftStop, speedStep),
      rightServo(rightPin, rightStop, speedStep),
      speedStepUs(speedStep)
{
}

// Stop both servos
void RoverDriver::stop()
{
    leftServo.stop();
    rightServo.stop();
}

// Move forward
void RoverDriver::forward()
{
    // One servo runs opposite direction
    leftServo.forward(speedStepUs + leftTrim);
    rightServo.reverse(speedStepUs + rightTrim);
}

// Move backward
void RoverDriver::reverse()
{
    leftServo.reverse(speedStepUs);
    rightServo.forward(speedStepUs);
}

// Turn left
void RoverDriver::turnLeft()
{
    leftServo.reverse(speedStepUs);
    rightServo.reverse(speedStepUs);
}

// Turn right
void RoverDriver::turnRight()
{
    leftServo.forward(speedStepUs);
    rightServo.forward(speedStepUs);
}

// Set speed
void RoverDriver::setSpeed(int speedStep)
{
    speedStepUs = speedStep;
}