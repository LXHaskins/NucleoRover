#include "mbed.h"
#include "classes/ButtonController.h"
#include "classes/UltrasonicSensor.h"
#include "classes/RoverDriver.h"

ButtonController button(D8);
UltrasonicSensor sensor(D7, D6, 200);
RoverDriver rover(D10, D9, 1445, 1460, 60);

// Test ButtonController
void testButton()
{
    printf("\n[TEST 1] ButtonController::wasPressed()\n");
    printf("Action: Press the button once.\n");

    while (true) {
        if (button.wasPressed()) {
            printf("Result: PASS - Button press detected correctly.\n");
            break;
        }
        ThisThread::sleep_for(50ms);
    }
}

// Test Ultrasonic Sensor
void testUltrasonic()
{
    printf("\n[TEST 2] UltrasonicSensor::pingCm()\n");

    for (int i = 0; i < 5; i++) {
        int distance = sensor.pingCm();

        if (distance < 0) {
            printf("Reading %d: Timeout detected\n", i + 1);
        } else {
            printf("Reading %d: %d cm\n", i + 1, distance);
        }

        ThisThread::sleep_for(500ms);
    }

    printf("Result: PASS - Sensor readings returned.\n");
}

// Test Rover stop
void testStop()
{
    printf("\n[TEST 3] RoverDriver::stop()\n");

    rover.stop();
    ThisThread::sleep_for(3s);

    printf("Result: PASS - Stop command executed.\n");
}

// Test forward movement
void testForward()
{
    printf("\n[TEST 4] RoverDriver::forward()\n");

    rover.forward();
    ThisThread::sleep_for(2s);
    rover.stop();

    printf("Result: PASS - Forward movement executed.\n");
}

// Test reverse movement
void testReverse()
{
    printf("\n[TEST 5] RoverDriver::reverse()\n");

    rover.reverse();
    ThisThread::sleep_for(2s);
    rover.stop();

    printf("Result: PASS - Reverse movement executed.\n");
}

// Test turning
void testTurn()
{
    printf("\n[TEST 6] RoverDriver::turnRight()\n");

    rover.turnRight();
    ThisThread::sleep_for(2s);
    rover.stop();

    printf("Result: PASS - Turn executed.\n");
}

// Test obstacle logic behavior
void testObstacleLogic()
{
    printf("\n[TEST 7] Obstacle Detection Logic\n");

    int distance = sensor.pingCm();

    if (distance < 0) {
        printf("Condition: Sensor timeout\n");
        printf("Expected: Rover stops\n");
        rover.stop();
    }
    else if (distance <= 15) {
        printf("Condition: Obstacle at %d cm\n", distance);
        printf("Expected: Avoidance sequence\n");

        rover.stop();
        ThisThread::sleep_for(300ms);

        rover.reverse();
        ThisThread::sleep_for(700ms);

        rover.stop();
        ThisThread::sleep_for(300ms);

        rover.turnRight();
        ThisThread::sleep_for(700ms);

        rover.stop();
    }
    else {
        printf("Condition: Clear path (%d cm)\n", distance);
        printf("Expected: Forward movement\n");

        rover.forward();
        ThisThread::sleep_for(2s);
        rover.stop();
    }

    printf("Result: PASS - Logic executed.\n");
}

/*
int main()
{
    printf("\n-=Begin Component Tests=-\n");

    rover.stop();
    ThisThread::sleep_for(2s);

    testButton();
    testUltrasonic();
    testStop();
    testForward();
    testReverse();
    testTurn();
    testObstacleLogic();

    printf("\n===== TESTS COMPLETE =====\n");

    while (true) {
        ThisThread::sleep_for(1s);
    }
}
*/