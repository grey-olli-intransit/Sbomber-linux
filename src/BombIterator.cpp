//
// Created by olli on 2/16/22.
//
#include "BombIterator.h"
#include <vector>
#include "Bomb.h"

BombIterator::BombIterator(std::vector<Bomb *> &allBombs) : index(-1), refVector(allBombs), ptr(nullptr) {
    ++(*this);
}

void BombIterator::reset() {
    index = -1;
    ptr = nullptr;
}

BombIterator & BombIterator::operator++() // префиксный инкремент
{
    index = index + 1;
    if (index == -1)
        index = 0;
    if(index == refVector.size()) {
        index = -1;
        ptr = nullptr;
        return *this;
    }
    ptr = refVector[index];
    return *this;
}

BombIterator &BombIterator::operator--() // префиксный декремент
{
    if (index == -1) {
        index = refVector.size() - 1;
        ptr = refVector[index];
        return *this;
    }
    index = index - 1;
    if(index == -1) {
        index = -1;
        ptr = nullptr;
        return *this;
    }
    ptr = refVector[index];
    return *this;
}

Bomb & BombIterator::operator*() // операция разыменования итератора
{
        return *refVector.at(index);
}

bool BombIterator::operator==(BombIterator it) // проверка на логическое равенство итераторов
{
    if (index == it.index &&
        ptr == it.ptr &&
        refVector == it.refVector)
    {
        return true;
    }
    return false;
}

bool BombIterator::operator!=(BombIterator it) // проверка на логическое неравенство
{
    return !(*this == it);
}

// получаем итератор настроенный на начало массива
BombIterator BombIterator::begin() { BombIterator it(refVector); return it; }

// итератор в конечном состоянии
BombIterator BombIterator::end() { BombIterator it(refVector); it.reset(); return it; }