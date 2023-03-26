#include "../../Base_class/DispersionFunction.hpp"
#pragma once

template<class Key>
class fdSRand: public DispersionFunction<Key> {
    public:
        fdSRand(const unsigned n): tableSize(n){}
        unsigned operator()(const Key& k) const {
            srand(k);
            return (rand() % tableSize);
        }
    private:
        unsigned tableSize;
};