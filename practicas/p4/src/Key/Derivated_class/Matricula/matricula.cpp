#include "matricula.hpp"

matricula::matricula() : matricula(0000,"ZZZ") {}

matricula::matricula(long n, std::string s){
    numero = n;
    assert(s.size() == 3);
    for(size_t i=0; i < s.size(); i++){
        if((s.at(i) >= 'a') && (s.at(i) <='z')){
            if ((s.at(i) == 'a') || (s.at(i) == 'e') || (s.at(i) == 'i') || 
                (s.at(i) == 'o') || (s.at(i) == 'u'))
                throw std::invalid_argument("Solo letras consonantes.");
            else 
                letras.push_back(s.at(i) - 32);         // Pasar de minúscula a mayúsucla
        } else if ((s.at(i) >= 'A') && (s.at(i) <='Z')){
            if ((s.at(i) == 'A') || (s.at(i) == 'E') || (s.at(i) == 'I') || 
                (s.at(i) == 'O') || (s.at(i) == 'U'))
                throw std::invalid_argument("Solo letras consonantes.");
            else 
                letras.push_back(s.at(i));
        } else
            throw std::invalid_argument("Caracter no válido. Solo letras permitidas");
    }
}

matricula::~matricula(){}

long matricula::getLong(){
    long l = numero * 100 * 100 * 100;
    for (size_t i = 0, mult = 10000; i < letras.size(); i++){
        l += (letras.at(i) - 65) * mult;// El valor de la letra va a ser el indice que ocupe en el abecedario
        mult = mult / 100;
    }
    return l;
}

std::string matricula::getmatricula(){
    std::string s = std::to_string(numero);
    s += letras;
    return s;
}

//void setmatricula(long n, char c){
//     numero = n;
//     letra = c;
// }