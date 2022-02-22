#include "House.h"
#include <iostream>
#include "MyTools.h"
#include "ScreenSingleton.h"

House::House() {
    memset((char*)look, ' ', houseWidth * houseHeight - 1);
}

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
    ScreenSingleton::getInstance().SetColor(CC_Yellow);
    for (size_t i = 0; i < houseHeight; ++i)
    {
        ScreenSingleton::getInstance().GotoXY(x, y - i);
        for (size_t j = 0; j < houseWidth; ++j)
        {
            std::cout << look[houseHeight - i - 1][j];
        }
    }
}

int House::getWidth() {
    return houseWidth;
}

int House::getHeight() {
    return houseHeight;
}
