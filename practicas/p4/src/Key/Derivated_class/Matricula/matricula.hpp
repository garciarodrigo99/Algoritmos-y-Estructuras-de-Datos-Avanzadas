#pragma once

#include "../../Base_class/Key.hpp"

class matricula: public Key{

public:
    matricula();
    matricula(long,std::string);
    ~matricula();
    long getLong() override;
    std::string getmatricula();
    //void setmatricula(long,char);

private:
    long numero;
    std::string letras;
};
