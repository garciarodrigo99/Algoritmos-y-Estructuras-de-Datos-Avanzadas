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
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 28/02/2023 - Creaci´on (primera versi´on) del c´odigo

#include <fstream>
#include <chrono>

#include "../src/BigInt/Derived_Class/Big_Int.hpp"
#include "../src/BigInt/Base_Class/Number.hpp"
#include "../lib/splitChain.hpp"
#include "../src/Calculator/calculator.hpp"
#include "../src/Exceptions/Base_Class/BigIntException.hpp"

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
  Calculator<BigInt<2>> calc;
	std::vector<std::string> splittedChain;
  while(getline(archivo_entrada, linea)) {
    std::cout << "Hola\n";
		splittedChain = SplitChain(linea);
		if (splittedChain[1] == '='){
			Board[splittedChain.at(0)] = T(splittedChain.at(2));
		} else {
			Board[splittedChain.at(0)] = T(calc.GetResult<T>(linea,Board));
		}
  }
  archivo_entrada.close();
  //std::cout << T::totalInstances();
  writeToFile(Board);
}

int main(int argc, char *argv[]) {
//488793485263218
  // std::cout << (BigInt<10>)pow(BigInt<2>(BigInt<10>(2)),BigInt<2>(BigInt<10>(100))).size() << std::endl;
  // BigInt<2> n1(BigInt<10>(442142117615672));
  // std::cout << "n1: " << (BigInt<10>)n1 << "  " << n1 << std::endl;
  // BigInt<2> n2(BigInt<10>(46651367647546));
  // std::cout << "n2: " << (BigInt<10>)n2 << "      " << n2 << std::endl;
  // BigInt<2> e1(n1+n2);
  // std::cout << "e1: " << (BigInt<10>)e1 << "  " << e1 << std::endl;
  // BigInt<2> t1(n1-n2);
  // std::cout << "t1: " << (BigInt<10>)t1 << "  " << t1 << std::endl;
  // BigInt<2> e2(t1+e1);
  // std::cout << "e2: " << (BigInt<10>)e2 << " " << e2  << ", e2.size: " << e2.size() << std::endl;
  
  // // BigInt<2> e2((BigInt<10>)(18)+(BigInt<10>)(6));
  // // std::cout << "e2: " << (BigInt<10>)e2 << "  " << e2 << std::endl;
  // return 0;

  std::string fileName = argv[1];
  // --------------------------------------------------------------------------
  std::ifstream archivo_entrada(fileName);
  std::string linea;

  // int contador = 0;
  // int max = 0;
  int option = 5;

  // while(getline(archivo_entrada, linea)) {
  //   if(max == contador) {
  //     // Manejar excepción
  //     // To-Do something here

  //     option = std::stoi(SplitChain(linea).at(2));
  //     break;
  //   }
  //   contador++;
  // }
  // archivo_entrada.close();
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
      throw BigIntBaseNotImplemented("Base no válida");
      break;
  }

  return 0;
}