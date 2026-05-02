#include "ButtonController.h"

// Constructor
ButtonController::ButtonController(PinName pin)
    : button(pin, PullUp), lastState(1)
{
}

// Detect new button press
bool ButtonController::wasPressed()
{
    bool currentState = button.read();

    bool pressed = (currentState == 0 && lastState == 1);

    lastState = currentState;

    return pressed;
}