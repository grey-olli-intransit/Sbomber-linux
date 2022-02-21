#pragma once

#include "DestroyableGroundObject.h"
#include <cstdint>
#include <cstddef>

namespace {
    int houseHeight = 7;
    int houseWidth = 13;
}


class House : public DestroyableGroundObject {
public:
  char look[7][14]{}; //[высота][ширина]
  House();
  bool isInside(double x1, double x2) const override;

  inline uint16_t GetScore() const override {
    return score;
  }

  void Draw() const override;

  int getWidth();

  int getHeight();

private:
  const uint16_t score = 40;

};


