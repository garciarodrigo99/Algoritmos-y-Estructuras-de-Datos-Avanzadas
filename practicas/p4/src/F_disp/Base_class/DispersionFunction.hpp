#include "../../Key/Base_class/Key.hpp"
#pragma once

template<class Key>
class DispersionFunction {
    public:
        virtual unsigned operator()(const Key& k) const = 0;
};

#include "../Der_classes/FdModule/fdModule.hpp"
#include "../Der_classes/FdSRand/fdSRand.hpp"
#include "../Der_classes/FdSum/fdSum.hpp"