//
// Created by olli on 2/16/22.
//
#pragma once

#include <vector>
#include "Bomb.h"

class BombIterator {
private:
    unsigned int index;
    std::vector<Bomb *> & refVector;
    Bomb *ptr;
public:
    explicit BombIterator(std::vector<Bomb *> &allBombs);

    void reset();

    BombIterator & operator++(); // префиксный инкремент

    BombIterator &operator--(); // префиксный декремент

    Bomb & operator*(); // операция разыменования итератора

    bool operator==(BombIterator it); // проверка на логическое равенство итераторов

    bool operator!=(BombIterator it); // проверка на логическое неравенство

    // получаем итератор настроенный на начало массива
    BombIterator begin();

    // итератор в конечном состоянии
    BombIterator end();

};