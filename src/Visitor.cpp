//
// Created by olli on 2/24/22.
//
#include "Visitor.h"

void LogVisitor::log(Bomb & bomb) {
    std::pair<double,double> pair = bomb.getDirection();
    MyTools::WriteToLog("Bomb speed: ", bomb.GetSpeed());
    MyTools::WriteToLog("Bomb direction, 1st double: ", pair.first);
    MyTools::WriteToLog("Bomb direction, 2nd double: ", pair.second);
}
void LogVisitor::log(Plane & plane) {
    std::pair<double,double> pair = plane.getDirection();
    MyTools::WriteToLog("Plane speed", plane.GetSpeed());
    MyTools::WriteToLog("Plane direction, 1st double: ", pair.first);
    MyTools::WriteToLog("Plane direction, 2nd double: ", pair.second);
}