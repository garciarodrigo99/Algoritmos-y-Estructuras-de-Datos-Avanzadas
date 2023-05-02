/**
 * @file NodoAVL.hpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @brief Cabecera de la clase plantilla NodoAVL
 * @version 1.0
 * @date 08-05-2023
 */

#include <vector>
#include "../Base_class/NodoB.hpp"
#pragma once

template<class Key>
class NodoAVL : public NodoB<Key>{
	private:
		int bal_;

	public:
		NodoAVL(Key, int = 0, NodoB<Key>* = nullptr,NodoB<Key>* = nullptr);
		~NodoAVL();
		int& getBal();
};

template<class Key>
NodoAVL<Key>::NodoAVL(Key k, int bal, NodoB<Key>* lhs,NodoB<Key>* rhs) : NodoB<Key>(k,lhs,rhs) {
 bal_ = bal;
}

template<class Key>
NodoAVL<Key>::~NodoAVL(){}

template <class Key>
inline int &NodoAVL<Key>::getBal()
{
  return bal_;
}
