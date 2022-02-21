#pragma once

#include "House.h"

class HouseBuilder
{
public:
   virtual ~HouseBuilder() = default;
   virtual void buildOutline(House & house) {};

   virtual void buildCeil(House& house) {};
   virtual void buildRoof(House& house) {};
   virtual void buildWindow(House& house) {};
   virtual void buildDoor(House& house) {};
   virtual void buildPipe(House& house) {};
};

// a house with pipe and with window 
class HouseBuilder1 final : public HouseBuilder
{
public:
   void buildOutline(House & house) override;

   void buildCeil(House& house) override;
   void buildRoof(House& house) override;
   void buildWindow(House& house) override;
   void buildDoor(House& house) override;
   void buildPipe(House& house) override;
};

/// a house without pipe and without window
class HouseBuilder2 final : public HouseBuilder
{
public:
   void buildOutline(House & house) override;

   void buildCeil(House& house) override;
   void buildRoof(House& house) override;
   void buildDoor(House& house) override;
};

class Director
{
public:
   static void makeHouse(HouseBuilder& builder, House& house)
   {
      builder.buildCeil(house);
      builder.buildDoor(house);

      builder.buildOutline(house);

      builder.buildRoof(house);
      builder.buildPipe(house);
      builder.buildWindow(house);
   }
};