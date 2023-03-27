// https://www.businessinsider.es/significado-letra-viene-dni-791661

#include "dni.hpp"

dni::dni() : dni(99999999,'Z'){
}

dni::dni(char c){
    assert (c == 'r' || c == 'R');
    //srand(time(NULL));
    numero = (rand() % 89999999) + 10000000;
    letra = generateChar(numero);
}

dni::dni(long n, char c){
    numero = n;
    if((c >= 'a') && (c <='z')){
        letra = c - 32;         // Pasar de minúscula a mayúsucla
    } else if ((c >= 'A') && (c <='Z')){
        letra = c;
    } else
        throw std::invalid_argument("Caracter no válido. Solo letras permitidas");
}

dni::~dni(){}

long dni::getLong(){
    // El valor de la letra va a ser el indice que ocupe en el abecedario
    long l = numero * 100;
    // El valor de la letra va a ser el indice que ocupe en el abecedario
    l += ((int)(letra - 65));
    return l;
}

dni::operator unsigned long (void) const {
    // El valor de la letra va a ser el indice que ocupe en el abecedario
    long l = numero * 100;
    // El valor de la letra va a ser el indice que ocupe en el abecedario
    l += ((int)(letra - 65));
    return l;
}

dni::operator unsigned long (void){
    return getLong();
}

std::string dni::getDni(){
    std::string s = std::to_string(numero);
    s.push_back(letra);
    return s;
}

long dni::getNum(){
    return numero;
}

char dni::getLetra(){
    return letra;
}

char dni::generateChar(long dni){
    const std::string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
    int modulo = dni % 23;
    return letras[modulo];
}