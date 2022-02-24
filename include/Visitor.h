//
// Created by olli on 2/24/22.
//
#pragma once

#include "Plane.h"
#include "Bomb.h"
#include "MyTools.h"

class Visitor {
public:
   virtual void log(Bomb & bomb) = 0;
   virtual void log(Plane & plain) = 0;

};

class LogVisitor final: public Visitor {
private:
public:
    LogVisitor() = default;
    ~LogVisitor() = default;
    void log(Bomb & bomb) override;
    void log(Plane & plane) override;
};

