#pragma once

#include <iostream>
#include <string>
#include <assert.h>

class Key{

public:
    virtual ~Key(){}
    virtual long getLong(void) = 0;
    
};

#include "../Derivated_class/Matricula/matricula.hpp"
#include "../Derivated_class/DNI/dni.hpp"