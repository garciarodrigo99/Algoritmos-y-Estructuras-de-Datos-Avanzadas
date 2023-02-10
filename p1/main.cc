#include <fstream>

#include "Big_Int.h"
#include "Board.h"
#include "splitChain.h"
#include "calculator.h"

template <class T>
void auxFunction(std::string fileName) {
  T aux(1010101);
  T test(10101);
  T myBoard(fileName);
  Calculator<T> calc;
}

int main(int argc, char *argv[]) {

  BigInt<10> i(-4);
  std::cout << (++i) << std::endl;
  std::cout << (++i) << std::endl;
  std::cout << (++i) << std::endl;
  std::cout << (++i) << std::endl;
  std::cout << (++i) << std::endl;
  std::cout << (++i) << std::endl;
  return 0;

  std::string fileName = argv[1];
  // --------------------------------------------------------------------------
  std::ifstream archivo_entrada(fileName);;
  std::string linea;

  int contador = 0;
  int max = 0;
  int option = 10;

  while(getline(archivo_entrada, linea)) {
    if(max == contador) {
      // Manejar excepción
      // To-Do something here

      option = std::stoi(SplitChain(linea).at(2));
      break;
    }
    contador++;
  }
  archivo_entrada.close();
  // --------------------------------------------------------------------------

  switch (option) {
    case 2:
      auxFunction<BigInt<2>>(fileName);
      break;

    case 8:
      auxFunction<BigInt<8>>(fileName);      
      break;

    case 10:
      auxFunction<BigInt<10>>(fileName);
      break;

    case 16:
      auxFunction<BigInt<16>>(fileName);
      break;
    
    default:
      throw std::domain_error("Base no válida");
      break;
  }

  return 0;
}