//
// Created by olli on 2/24/22.
//
#include "Visitor.h"

void LogVisitor::log(Bomb & bomb) { MyTools::WriteToLog("Bomb speed", bomb.GetSpeed());}
void LogVisitor::log(Plane & plane) { MyTools::WriteToLog("Plane speed", bomb.GetSpeed());}