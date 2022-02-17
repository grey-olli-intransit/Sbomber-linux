//
// Created by olli on 2/16/22.
//
#pragma once

#include <vector>
#include "Bomb.h"

class BombIterator {
private:
    std::vector<Bomb *> * refVector;
    Bomb *ptr;
    unsigned int index;
public:

    explicit BombIterator(std::vector<Bomb *> &allBombs);

    BombIterator(const BombIterator& rhs);

    void reset();

    BombIterator & operator++(); // префиксный инкремент

    BombIterator &operator--(); // префиксный декремент

    Bomb & operator*(); // операция разыменования итератора

    bool operator==(const BombIterator & it); // проверка на логическое равенство итераторов

    bool operator!=(const BombIterator & it); // проверка на логическое неравенство

    BombIterator &operator=(const BombIterator & it); // кастомный оператор присваивания

};