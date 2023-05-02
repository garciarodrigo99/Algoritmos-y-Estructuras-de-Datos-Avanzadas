/**
 * @file AB.hpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @brief Cabecera de la clase plantilla AB(Árbol binario)
 * @version 1.0
 * @date 08-05-2023
 */

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
		NodoB<Key>* getRaiz() const;

	private:
		void inorden_rec(NodoB<Key>*) const;
};

template <class Key>
inline void AB<Key>::inorden() const
{
	inorden_rec(raiz_);
}

template <class Key>
void AB<Key>::inorden_rec(NodoB<Key>* nodo) const {
  if (nodo != nullptr) {
    inorden_rec(nodo->getIzdo());
    std::cout << nodo->getDato() << " ";
    inorden_rec(nodo->getDcho());
  }
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
		for (int i = 0; i < nodosNivel; i++) {
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