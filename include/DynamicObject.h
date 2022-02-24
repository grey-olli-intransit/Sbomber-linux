#pragma once

#include <stdint.h>
#include <utility>

#include "GameObject.h"

class DynamicObject : public GameObject 
{
public:

    DynamicObject() : speed(0.0), xDirection(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline double GetSpeed() { return speed;}
    inline void SetDirection(double dx, double dy) { xDirection = dx; yDirection = dy; }
    inline std::pair<double,double> getDirection() {return std::make_pair(xDirection, yDirection);}
    virtual void Move(uint16_t time) { x += xDirection * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

protected:

    double speed;
    double xDirection, yDirection;

};