#include "../../Base_class/DispersionFunction.hpp"
#pragma once

template<class Key>
class fdModule: public DispersionFunction<Key> {
    public:
        fdModule(const unsigned n): tableSize(n){}
        unsigned operator()(const Key& k) const {
            return k % tableSize;
        }
    private:
        unsigned tableSize;
};