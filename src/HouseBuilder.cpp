#include "HouseBuilder.h"
#include "House.h"

void HouseBuilder1::buildOutline(House &house)
{
    for (int i = 4; i < house.getHeight() - 1; ++i)
    {
        house.look[i][0] = '#';
        house.look[i][house.getWidth() - 1] = '#';
    }
    for (int i = 0; i < house.getWidth(); ++i)
    {
        house.look[house.getHeight() - 1][i] = '#';
    }
}

void HouseBuilder1::buildCeil(House& house)
{
   for (int i = 0; i < house.getWidth(); ++i)
   {
      house.look[3][i] = '#';
   }
}

void HouseBuilder1::buildRoof(House& house)
{
   int j = 1;
   for (int i = 2; i > 0; --i)
   {
      house.look[i][j] = '#';
      house.look[i][house.getWidth() - j - 1] = '#';
      j++;
   }
   for (int j = 3; j < house.getWidth() - 3; j++)
   {
      house.look[1][j] = '#';
   }
}

void HouseBuilder1::buildWindow(House& house)
{
   for (int j = 2; j < 5; ++j)
   {
      house.look[5][j] = '#';
      house.look[7][j] = '#';
   }
   house.look[6][2] = '#';
   house.look[6][4] = '#';
}

void HouseBuilder1::buildDoor(House& house)
{
   for (int i = 5; i < 9; ++i)
   {
      house.look[i][7] = '#';
      house.look[i][9] = '#';
   }
   house.look[5][8] = '#';
}

void HouseBuilder1::buildPipe(House& house)
{
   house.look[0][7] = '#';
}

void HouseBuilder2::buildOutline(House &house)
{
    for (int i = 4; i < house.getHeight() - 1; ++i)
    {
        house.look[i][0] = '#';
        house.look[i][house.getHeight() - 1] = '#';
    }

    for (int i = 0; i < house.getHeight(); ++i)
    {
        house.look[house.getHeight() - 1][i] = '#';
    }
}


void HouseBuilder2::buildCeil(House& house)
{
   for (int i = 0; i < house.getWidth(); ++i)
   {
      house.look[3][i] = '#';
   }
}

void HouseBuilder2::buildRoof(House& house)
{
   int j = 1;
   for (int i = 2; i > 0; --i)
   {
      house.look[i][j] = '#';
      house.look[i][house.getWidth() - j - 1] = '#';
      j++;
   }
   for (int j = 3; j < house.getWidth() - 3; j++)
   {
      house.look[1][j] = '#';
   }
}

void HouseBuilder2::buildDoor(House& house)
{
   for (int i = 5; i < 9; ++i)
   {
      house.look[i][4] = '#';
      house.look[i][7] = '#';
   }
   house.look[5][5] = '#';
   house.look[5][6] = '#';
}