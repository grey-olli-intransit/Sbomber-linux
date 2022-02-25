#include <iostream>
#include "ScreenSingleton.h"
#include "Bomb.h"
#include "Visitor.h"

void Bomb::Draw() const {
  //ScreenSingleton::getInstance().SetColor(CC_LightMagenta);
  ScreenSingleton::getInstance().GotoXY(x, y);
  std::cout << "*";
}

void  Bomb::Accept(Visitor & v)
{
    v.log(*this);
}