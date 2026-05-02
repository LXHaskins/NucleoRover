#include "mbed.h"
#include "classes/RoverDriver.h"
#include "classes/UltrasonicSensor.h"
#include "classes/ButtonController.h"

RoverDriver rover(D10, D9, 1445, 1460, 60);
UltrasonicSensor sensor(D7, D6, 200);
ButtonController button(D8);

const int OBSTACLE_THRESHOLD_CM = 15;
bool running = false;

int main()
{
    printf("Rover starting...\n");

    rover.stop();
    ThisThread::sleep_for(2s);

    while (true) {

        if (button.wasPressed()) {
            running = !running;
            printf("Running: %d\n", running);
            ThisThread::sleep_for(200ms);
        }

        if (!running) {
            rover.stop();
            ThisThread::sleep_for(50ms);
            continue;
        }

        int distance = sensor.pingCm();

        if (distance < 0) {
            printf("Sensor timeout\n");
            rover.stop();
            ThisThread::sleep_for(300ms);
        }
        else {
            printf("Distance: %d cm\n", distance);

            if (distance > OBSTACLE_THRESHOLD_CM) {
                rover.forward();
            }
            else {
                rover.stop();
                ThisThread::sleep_for(300ms);

                rover.reverse();
                ThisThread::sleep_for(700ms);

                rover.stop();
                ThisThread::sleep_for(300ms);

                rover.turnRight();
                ThisThread::sleep_for(700ms);

                rover.stop();
                ThisThread::sleep_for(300ms);
            }
        }

        ThisThread::sleep_for(100ms);
    }
}