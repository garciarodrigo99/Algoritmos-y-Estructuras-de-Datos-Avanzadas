#include <vector>
#pragma once

template<class Key>
class SortMethod{

public:
    virtual ~SortMethod(){}
    virtual void Sort() = 0;
};

#include "../Derived_class/heapsort.hpp"
#include "../Derived_class/insertion.hpp"
#include "../Derived_class/mergesort.hpp"
#include "../Derived_class/quicksort.hpp"
#include "../Derived_class/radixsort.hpp"
#include "../Derived_class/seleccion.hpp"
#include "../Derived_class/shellsort.hpp"