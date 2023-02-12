#include <fstream>
#include <chrono>

#include "../src/BigInt/Big_Int.hpp"
// #include "Board.h"
#include "../lib/splitChain.hpp"
#include "../src/Calculator/calculator.hpp"

template <class T>
void writeToFile(std::map<std::string, T> board, std::string fileName = "a.out") {
  std::string outputFilePath = "output/";
  // std::string outputFilePath = "";
  outputFilePath.append(fileName);
  std::ofstream archivo(outputFilePath);
  if (archivo.is_open()) {
    for (auto i : board)
      archivo << i.first << " = " << i.second << std::endl;
    archivo.close();
  } else {
    std::cout << "No se pudo abrir el archivo." << std::endl;
  }
}

template <class T>
void auxFunction(std::string fileName) {

  std::map<std::string, T> Board;
  std::ifstream archivo_entrada(fileName);
  std::string linea;

	getline(archivo_entrada, linea);

	//int i = 0;
  Calculator<T> calc;
	std::vector<std::string> splittedChain;
  while(getline(archivo_entrada, linea)) {
		splittedChain = SplitChain(linea);
		if (splittedChain.size() == 3){
			Board[splittedChain.at(0)] = T(splittedChain.at(2));
		} else {
			Board[splittedChain.at(0)] = T(calc.GetResult(linea,Board));
		}
  }
  archivo_entrada.close();
  writeToFile(Board);
}

int main(int argc, char *argv[]) {

  // // BigInt<10> b1(3);
  // // BigInt<10> b2(-3);
  // BigInt<10> n1("442142117615672");
  // BigInt<10> n2("46651367647546");
  // BigInt<10> e1(n1+n2);
  // BigInt<10> e2(e1+(n1-n2));
  // auto start = std::chrono::system_clock::now();
  // std::cout << e2 << std::endl;
  // auto end = std::chrono::system_clock::now();
  // std::chrono::duration<float> duration = end - start;
  // std::cout << duration.count() << "s" << std::endl;
  // std::map<std::string, BigInt<10>> numeros;
  // numeros["n1"] = n1;
  // numeros["n2"] = n2;
  // numeros["e1"] = e1;
  // Calculator<BigInt<10>> calc;
  // std::cout << calc.GetResult("e2 = e1 n1 n2 - +",numeros) << std::endl;

  // return 0;

  std::string fileName = argv[1];
  // --------------------------------------------------------------------------
  std::ifstream archivo_entrada(fileName);
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