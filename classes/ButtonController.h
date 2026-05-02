#ifndef BUTTONCONTROLLER_H
#define BUTTONCONTROLLER_H

#include "mbed.h"

class ButtonController {
public:
    // Constructor
    ButtonController(PinName pin);

    // Returns true once when button is newly pressed
    bool wasPressed();

private:
    DigitalIn button;
    bool lastState;
};

#endif