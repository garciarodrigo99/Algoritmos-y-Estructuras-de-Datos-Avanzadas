/**
 * @file testAVL.cpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @brief Programa para comprobar las (todas)rotaciones y balanceo de un AVL 
 * dada una entrada
 * @version 1.0
 * @date 08-05-2023
 */

#include <string>
#include <iostream>
#include <cassert>
#include <utility>
#include "../src/AB/Base_class/AB.hpp"
#include "../src/AB/Derived_class/ABB/Base_class/ABB.hpp"
#include "../src/AB/Derived_class/ABB/Derived_class/AVL.hpp"


int main() {

	AB<long>* treePtr = new AVL<long>();

  std::vector<int> vct = {84, 19, 91, 69, 47, 79, 78, 77, 48, 68, 58, 49, 99, 50, 98, 59, 51, 97, 52, 96, 53, 95, 94, 93, 92};
	for (size_t i = 0; i < vct.size(); i++) {
		if (treePtr->insertar(vct[i]))
      std::cout << "La clave " << i << " ha sido insertada." << std::endl;
    else
      std::cout << "La clave " << i << " NO ha sido insertada." << std::endl;
    std::cout << *treePtr;
	}
	
	delete treePtr;
	return 0;
}