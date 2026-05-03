#ifndef IDRIVER_H
#define IDRIVER_H

class IDriver {
public:
    virtual void stop() = 0;
    virtual void forward() = 0;
    virtual void reverse() = 0;
    virtual void turnLeft() = 0;
    virtual void turnRight() = 0;

    virtual ~IDriver() {}
};

#endif