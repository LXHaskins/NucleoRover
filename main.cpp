#include "mbed.h"
#include <chrono>

DigitalOut trig(PA_9);
DigitalIn echo(PA_8);

Timer timer;

int main() {
    printf("Ultrasonic Sensor Test\r\n");

    while (true) {
        // Ensure trigger is low
        trig = 0;
        wait_us(2);

        // Send 10us pulse
        trig = 1;
        wait_us(10);
        trig = 0;

        // Wait for echo to go HIGH
        while (echo == 0);

        timer.reset();
        timer.start();

        // Wait for echo to go LOW
        while (echo == 1);

        timer.stop();

        float time = timer.read(); // seconds
        float distance = (time * 34300.0f) / 2.0f;

        printf("Distance: %.2f cm\r\n", distance);

        ThisThread::sleep_for(500);
    }
}