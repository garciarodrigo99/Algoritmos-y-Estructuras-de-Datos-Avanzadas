/**
 * @file SortMethod.hpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Implementación de métodos de ordenación
 * @brief Cabecera de la clase abstracta SortMethod
 * @version 1.0
 * @date 17-04-2023
 */

// El código 2, por otro lado, utiliza variables de instancia protegidas en la clase base, lo que permite que la clase derivada InsertionSortMethod tenga acceso a estas variables de instancia sin necesidad de almacenar una referencia en una variable miembro. Esto hace que el código sea más seguro y prevenido de posibles errores.
// En general, se recomienda utilizar variables de instancia protegidas en la clase base en lugar de variables de instancia privadas en la clase derivada, ya que esto hace que el código sea más seguro y menos propenso a errores.

#include "../../NodoB/Base_class/NodoB.hpp"
#include <vector>
#include <iostream>
#include <queue>
#pragma once

template<class Key>
class AB{
	protected:
		NodoB<Key>* raiz_ = nullptr;

	public:
		virtual ~AB(){}
		virtual bool insertar(const Key&) = 0;
		virtual bool buscar(const Key&) const = 0;
		void inorden() const;
		// d. Sobrecarga del operador de inserción en flujo para mostrar el AB<Key>
		// utilizando el recorrido por niveles: En cada nivel se muestran los nodos de
		// izquierda a derecha. El subárbol vacío se visualiza con [.].
		NodoB<Key>* getRaiz() const;
};

// #include "../Derived_class/heapsort.hpp"
// #include "../Derived_class/insertion.hpp"

template <class Key>
inline void AB<Key>::inorden() const
{
}

template <class Key>
inline NodoB<Key> *AB<Key>::getRaiz() const
{
    return raiz_;
}

template <class Key>
std::ostream& operator<<(std::ostream& os, const AB<Key>& tree) {
	int nivel = 0;
	std::queue<NodoB<Key>*> cola;
	cola.push(tree.getRaiz());

	while (!cola.empty()){
		int nodosNivel = cola.size();
		os << "Nivel " << nivel << ": ";
		for (size_t i = 0; i < nodosNivel; i++) {
			NodoB<Key>* nodoActual = cola.front();
			cola.pop();
			if (nodoActual == nullptr){
				os << "[.] ";
			} else {
				os << "[" << nodoActual->getDato() << "] ";
				cola.push(nodoActual->getIzdo());
				cola.push(nodoActual->getDcho());
			}
		}
		os << "\n";
		nivel++;
	}
	
	return os;
}