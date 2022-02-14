//
// Created by olli on 2/11/22.
//
#pragma once
#include <vector>
#include "DynamicObject.h"
#include "SBomber.h"

class SBomber;

class AbstractCommand{
protected:
    SBomber * sBomber;
public:
    virtual void execute() = 0;
    // void unDoExecute(); - в этом проекте не используется
};

class CmdRemoveDynObj : public AbstractCommand {
    DynamicObject * tmp;
public:
    CmdRemoveDynObj();
    void setOptions(DynamicObject * pBomb);
    DynamicObject * getOptions();
    CmdRemoveDynObj(std::vector<DynamicObject*> & vecDynamicObj, DynamicObject * pBomb);
    CmdRemoveDynObj(DynamicObject * pBomb);
    void execute() override;
};
