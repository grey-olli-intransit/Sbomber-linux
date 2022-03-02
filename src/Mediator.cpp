//
// Created by olli on 2/28/22.
//
#include "Mediator.h"
#include "LevelGUI.h"

void Mediator::sendMessage(std::string message) {
    this->levelGuiPtr->messages.push(message);
}
