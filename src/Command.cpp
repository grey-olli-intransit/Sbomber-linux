//
// Created by olli on 2/11/22.
//
#include <vector>
#include <iostream>
#include "Command.h"
#include "DynamicObject.h"
#include "Bomb.h"

void CmdRemoveDynObj::execute() {
    //std::cout << "Executed CmdRemoveDynObj\n";
    if(tmp) {
    tmp = CmdRemoveDynObj::getOptions();
    sBomber->DeleteDynamicObj(tmp);
    } else {
       std::cout << "Null pointer in CmdRemoveDynObj::tmp\n";
    }
}


CmdRemoveDynObj::CmdRemoveDynObj(std::vector<DynamicObject *> &vecDynamicObj, DynamicObject *pObj) {
    auto it = vecDynamicObj.begin();
    for (; it != vecDynamicObj.end(); it++) {
        if (*it == pObj) {
            vecDynamicObj.erase(it);
            break;
        }
    }
}

void CmdRemoveDynObj::setOptions(DynamicObject * pBomb) {
    CmdRemoveDynObj::tmp = pBomb;
}

DynamicObject * CmdRemoveDynObj::getOptions() {
    return this->tmp;
}

CmdRemoveDynObj::CmdRemoveDynObj() {

}

