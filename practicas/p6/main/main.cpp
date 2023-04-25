/**
 * @file main.cpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Implementación de métodos de ordenación
 * @brief Programa principal
 * @version 1.0
 * @date 17-04-2023
 */

#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <string>
#include <iostream>
#include <cassert>
#include <utility>
#include "../src/AB/Base_class/AB.hpp"
#include "../src/AB/Derived_class/ABB/Base_class/ABB.hpp"
#include "../src/AB/Derived_class/ABB/Derived_class/AVL.hpp"


#define rango_inferior 1000
#define rango_superior 9999



int main() {

	AB<long>* treePtr = nullptr; // Inicializamos el puntero en nullptr
	NodoB<int> ejemplo(1);

	return 0;
	int treeType = -1;
	while ((treeType < 1) || (treeType > 2)){   
		
		std::cout << "¿Qué tipo de árbol quiere crear? (ABB o AVL)\n"
		"[1] ABB\n"
		"[2] AVL\n" << std::endl;
		std::cin >> treeType;
		
		if (treeType == 1)
			treePtr = new ABB<long>(); // Asignamos el puntero a un objeto ABB
		if (treeType == 2)
			treePtr = new AVL<long>(); // Asignamos el puntero a un objeto AVL
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
			treePtr->insertar(clave); // Usamos el puntero para llamar a la función insertar del objeto correspondiente
		} else if (opcion == 2) {
			long clave;
			std::cout << "Introduzca la clave que desea buscar:" << std::endl;
			std::cin >> clave;
			bool encontrado = treePtr->buscar(clave); // Usamos el puntero para llamar a la función buscar del objeto correspondiente
			if (encontrado) {
				std::cout << "La clave " << clave << " ha sido encontrada." << std::endl;
			} else {
				std::cout << "La clave " << clave << " no ha sido encontrada." << std::endl;
			}
		} else if (opcion == 3) {
			std::cout << "Árbol en orden:" << std::endl;
			treePtr->inorden(); // Usamos el puntero para llamar a la función mostrar_inorden del objeto correspondiente
		}
	}
	
	delete treePtr; // Liberamos la memoria al finalizar el programa
	return 0;
}