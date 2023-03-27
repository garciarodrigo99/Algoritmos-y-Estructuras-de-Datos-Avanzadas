#pragma once

#include "../../Base_class/Key.hpp"
#include <string>

class dni: public Key{

public:
    dni();
    dni(long,char);
    dni(char);
    ~dni();
    long getLong() override;
    std::string getDni();
    long getNum();
    char getLetra();
    operator unsigned long (void) const;
    operator unsigned long (void);

private:
    long numero;
    char letra;
    std::string nombre;
    char generateChar(long);
};
