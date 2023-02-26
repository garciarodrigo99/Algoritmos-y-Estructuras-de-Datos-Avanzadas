// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS
// Curso: 2º
// Práctica 1: Representación de números grandes en notación posicional
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 13/02/2023
// Archivo main.cpp: Programa principal
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo

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
  //std::cout << T::totalInstances();
  writeToFile(Board);
}

int main(int argc, char *argv[]) {

  BigInt<2> a("01");
  std::cout << (BigInt<10>)a << " + ";
  BigInt<2> b("0111111");
  std::cout << (BigInt<10>)b << " = ";
  BigInt<2> c(a+b);
  std::cout << (BigInt<10>)c << std::endl;
  
  //std::cout << pow(BigInt<10>(2),BigInt<10>(15)) << std::endl;

  return 0;

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

    case 7:
      auxFunction<BigInt<7>>(fileName);      
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