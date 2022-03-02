#pragma once

#include "DynamicObject.h"

class Plane : public DynamicObject {
public:

    void Draw() override;

    inline void ChangePlaneY(double dy) { yDirection += dy; }

private:

};

