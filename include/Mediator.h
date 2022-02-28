//
// Created by olli on 2/28/22.
//
#pragma once

#include <string>

class Mediator {
public:
    virtual void sendMessage(std::string message) = 0;
private:
};