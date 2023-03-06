// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS
// Curso: 2º
// Práctica 3: Calculadora universal para números enteros grandes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 06/03/2023
// Archivo main.cpp: Programa principal
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 28/02/2023 - Creación (primera versión) del código

#include <fstream>
#include <chrono>

#include "../src/BigInt/Derived_Class/Big_Int.hpp"
#include "../src/BigInt/Base_Class/Number.hpp"
#include "../lib/auxFunctions.hpp"
#include "../src/Calculator/calculator.hpp"
#include "../src/Exceptions/Base_Class/BigIntException.hpp"

void writeToFile(std::map<std::string, Number*> board, 
                std::string fileName = "a.out") {
  std::string outputFilePath = "output/";
  outputFilePath.append(fileName);
  std::ofstream archivo(outputFilePath);
  if (archivo.is_open()) {
    for (auto i : board)
      archivo << i.first << " = " << *i.second << std::endl;
    archivo.close();
  } else {
    std::cout << "No se pudo abrir el archivo." << std::endl;
  }
}

int main(int argc, char *argv[]) {

//   // Number* a = new BigInt<2>("0111");
//   // Number* b = new BigInt<10>(7);
//   // std::cout << *(a->add(b)) << std::endl;
//   // std::cout << *(b->add(a)) << std::endl;
//   // std::cout << *b->power(a) << std::endl;

// Number* num = new BigInt<10>();
// std::cin >> *num;

// // También podrías leer números de una base específica
// Number* num2 = new BigInt<2>();
// std::cin >> *num2;


//   return 0;

  std::string fileName = argv[1];
  std::map<std::string, Number*> Board;
  Calculator calc;
	std::vector<std::string> splittedChain;
  std::ifstream archivo_entrada(fileName);
  if (!archivo_entrada.fail()) {
      std::cout << "El archivo se abrió correctamente\n";
  } else {
      std::cout << "El archivo NO se abrió correctamente\n";
      return 1;
  }
  std::string linea;
  while(getline(archivo_entrada, linea)) {
		splittedChain = SplitChain(linea);
    //std::cout << linea << std::endl;
		if (splittedChain[1][0] == '='){
			Board[splittedChain.at(0)] = Number::create(
        std::stoul(splittedChain.at(2)),splittedChain.at(3));
		} else {
			Board[splittedChain.at(0)] = calc.GetResult(linea,Board);
		}
  }
  archivo_entrada.close();
  writeToFile(Board);

  return 0;
}