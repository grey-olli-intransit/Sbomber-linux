//
// Created by olli on 2/24/22.
//
#pragma once

#include "Bomb.h"
#include "Plane.h"
#include "MyTools.h"

class Bomb;

class Visitor {
public:
   virtual void log(Bomb & bomb) = 0;
   virtual void log(Plane & plain) = 0;
   virtual ~Visitor() = default;
};

class LogVisitor final: public Visitor {
private:
public:
    LogVisitor() = default;
    ~LogVisitor() = default;
    void log(Bomb & bomb) override;
    void log(Plane & plane) override;
};

