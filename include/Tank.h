#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"
#include "Mediator.h"

class Tank : public DestroyableGroundObject
{
public:

    Tank(Mediator * m);

	bool  isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() override;

private:
    Mediator * mediator;
	const uint16_t score = 30;
};

