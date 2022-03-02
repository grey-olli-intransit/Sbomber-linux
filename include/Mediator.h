//
// Created by olli on 2/28/22.
//
#pragma once

#include <string>
#include "LevelGUI.h"


class Mediator {
public:
    Mediator(LevelGUI * lvlGUIPtr) : levelGuiPtr(lvlGUIPtr){};
    ~Mediator() = default;
    void sendMessage(std::string message);
private:
    LevelGUI * levelGuiPtr;
};