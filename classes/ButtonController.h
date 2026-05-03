#ifndef BUTTONCONTROLLER_H
#define BUTTONCONTROLLER_H

#include "mbed.h"
#include "IButton.h"

class ButtonController : public IButton {
public:
    // Constructor
    ButtonController(PinName pin);

    // Returns true once when button is newly pressed
    bool wasPressed() override;

private:
    DigitalIn button;
    bool lastState;
};

#endif