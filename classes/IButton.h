#ifndef IBUTTON_H
#define IBUTTON_H

class IButton {
public:
    virtual bool wasPressed() = 0;
    virtual ~IButton() {}
};

#endif