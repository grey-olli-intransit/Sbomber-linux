//
// Created by olli on 2/11/22.
//
#pragma once
#include <vector>
#include "DynamicObject.h"

class AbstractCommand{

public:
    virtual void execute() = 0;
    // void unDoExecute(); - в этом проекте не используется
};

class CmdRemoveDynObj : public AbstractCommand {
private:
    DynamicObject * tmp;
    std::vector<DynamicObject*> & vecDynamicObj
public:
    CmdRemoveDynObj(std::vector<DynamicObject*> & vecDynamicObj, DynamicObject * pSamltOrBomb);
    CmdRemoveDynObj(DynamicObject * pBomb);
    void execute() override;
};
