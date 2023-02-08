#include <fstream>

#include "Big_Int.h"
#include "Board.h"
#include "splitChain.h"

template <std::size_t Base>
void auxFunction(std::string fileName) {
  BigInt<Base> test(10101);
  Board<Base> myBoard(fileName);
  std::cout << myBoard;
}

int main(int argc, char *argv[]) {

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
      auxFunction<2>(fileName);
      break;

    case 8:
      auxFunction<8>(fileName);      
      break;

    case 10:
      auxFunction<10>(fileName);
      break;

    case 16:
      auxFunction<16>(fileName);
      break;
    
    default:
      throw std::domain_error("Base no válida");
      break;
  }

  return 0;
}