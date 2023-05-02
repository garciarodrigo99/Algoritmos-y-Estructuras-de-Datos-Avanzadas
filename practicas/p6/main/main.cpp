/**
 * @file main.cpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @brief Programa principal
 * @version 1.0
 * @date 08-05-2023
 */

#include <string>
#include <iostream>
#include <utility>
#include "../src/AB/Base_class/AB.hpp"
#include "../src/AB/Derived_class/ABB/Base_class/ABB.hpp"
#include "../src/AB/Derived_class/ABB/Derived_class/AVL.hpp"


int main() {

	AB<long>* treePtr = nullptr;

	int treeType = -1;
	while ((treeType < 1) || (treeType > 2)){   
		
		std::cout << "¿Qué tipo de árbol quiere crear? (ABB o AVL)\n"
		"[1] ABB\n"
		"[2] AVL\n" << std::endl;
		std::cin >> treeType;
		
		if (treeType == 1)
			treePtr = new ABB<long>();
		if (treeType == 2)
			treePtr = new AVL<long>();
	}
	
	int opcion = -1;
	while (opcion != 0) {
		std::cout << std::endl;
		std::cout << "[0] Salir\n"
		"[1] Insertar clave\n"
		"[2] Buscar clave\n"
		"[3] Mostrar árbol inorden\n"
		
		"¿Qué opción desea elegir?: ";
		std::cin >> opcion;
		
		if (opcion == 1) {
			long clave;
			std::cout << "Introduzca la clave que desea insertar:" << std::endl;
			std::cin >> clave;
			if (treePtr->insertar(clave))
				std::cout << "La clave " << clave << " ha sido insertada." << std::endl;
			else
				std::cout << "La clave " << clave << " NO ha sido insertada." << std::endl;
			std::cout << *treePtr;
		} else if (opcion == 2) {
			long clave;
			std::cout << "Introduzca la clave que desea buscar:" << std::endl;
			std::cin >> clave;
			if (treePtr->buscar(clave))
				std::cout << "La clave " << clave << " ha sido encontrada." << std::endl;
			else
				std::cout << "La clave " << clave << " NO ha sido encontrada." << std::endl;
		} else if (opcion == 3) {
			std::cout << "Árbol en inorden:" << std::endl;
			treePtr->inorden();
		}
	}
	
	delete treePtr;
	return 0;
}