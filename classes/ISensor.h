#ifndef ISENSOR_H
#define ISENSOR_H

class ISensor {
public:
    virtual int pingCm() = 0;
    virtual ~ISensor() {}
};

#endif