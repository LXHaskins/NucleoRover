#include "ServoDriver.h"

// Constructor: Initializes servo on given pin with stop pulse and speed step
ServoDriver::ServoDriver(PinName pin, int stopPulse, int speedStep)
    : servo(pin), stopPulseUs(stopPulse), speedStepUs(speedStep)
{
    servo.period_ms(20);    // Standard servo period: 20 ms
    stop();
}

// Set pulse width (microseconds) that corresponds to servo’s stop position
void ServoDriver::setStopPulse(int stopPulse)
{
    stopPulseUs = stopPulse;
}

// Returns currently configured stop pulse width (microseconds)
int ServoDriver::getStopPulse() const
{
    return stopPulseUs;
}

// Set default speed offset (microseconds) used for forward/reverse movement
void ServoDriver::setSpeedStep(int speedStep)
{
    speedStepUs = speedStep;
}

// Return current speed offset value (microseconds)
int ServoDriver::getSpeedStep() const
{
    return speedStepUs;
}

// Stop servo by sending calibrated stop pulse
void ServoDriver::stop()
{
    servo.pulsewidth_us(stopPulseUs);
}

// Move servo forward using default speed offset
void ServoDriver::forward()
{
    servo.pulsewidth_us(stopPulseUs + speedStepUs);
}

// Move servo in reverse using default speed offset
void ServoDriver::reverse()
{
    servo.pulsewidth_us(stopPulseUs - speedStepUs);
}

// Move servo forward using custom speed offset
void ServoDriver::forward(int offset)
{
    servo.pulsewidth_us(stopPulseUs + offset);
}

// Move servo in reverse using custom speed offset
void ServoDriver::reverse(int offset)
{
    servo.pulsewidth_us(stopPulseUs - offset);
}

// Directly set servo pulse width (microseconds)
void ServoDriver::writePulse(int pulseWidthUs)
{
    servo.pulsewidth_us(pulseWidthUs);
}