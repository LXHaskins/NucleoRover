#include "UltrasonicSensor.h"
using namespace std::chrono;

UltrasonicSensor::UltrasonicSensor(PinName trigPin, PinName echoPin, int maxDistanceCm)
    : trig(trigPin), echo(echoPin), maxDistance(maxDistanceCm)
{
    trig = 0;
}

int UltrasonicSensor::pingUs()
{
    bool timeout = false;

    // Send 10 us trigger pulse
    trig = 0;
    wait_us(2);
    trig = 1;
    wait_us(10);
    trig = 0;

    // Compute timeout from max distance; use round-trip time
    int timeoutUs = maxDistance * 58 * 2;

    timer.reset();
    timer.start();

    // Wait for echo high
    while (echo == 0) {
        if (duration_cast<microseconds>(timer.elapsed_time()).count() > timeoutUs) {
            timeout = true;
            break;
        }
    }

    if (timeout) {
        timer.stop();
        return -1;
    }

    timer.reset();

    // Measure high pulse width
    while (echo == 1) {
        if (duration_cast<microseconds>(timer.elapsed_time()).count() > timeoutUs) {
            timeout = true;
            break;
        }
    }

    timer.stop();

    if (timeout) {
        return -1;
    }

    return duration_cast<microseconds>(timer.elapsed_time()).count();
}

int UltrasonicSensor::pingCm()
{
    int pulseUs = pingUs();

    if (pulseUs < 0) {
        return -1;
    }

    return pulseUs / 58;
}