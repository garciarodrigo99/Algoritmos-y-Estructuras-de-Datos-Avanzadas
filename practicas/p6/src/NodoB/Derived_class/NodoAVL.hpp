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
		// virtual NodoAVL<Key>* getIzdo() const;
		// virtual NodoAVL<Key>*& getIzdo();
		// virtual NodoAVL<Key>* getDcho() const;
		// virtual NodoAVL<Key>*& getDcho();
};

template<class Key>
NodoAVL<Key>::NodoAVL(Key k, int bal, NodoB<Key>* lhs,NodoB<Key>* rhs) : NodoB<Key>(k,lhs,rhs) {
 bal_ = bal;
}

template<class Key>
NodoAVL<Key>::~NodoAVL(){}

// template<class Key>
// NodoAVL<Key>* NodoAVL<Key>::getIzdo() const {
// 		return dynamic_cast<NodoAVL<Key>*>(this->izdo_);
// }

// template<class Key>
// NodoAVL<Key>*& NodoAVL<Key>::getIzdo() {
// 	return dynamic_cast<NodoAVL<Key>*&>(this->izdo_);
// }

// template<class Key>
// NodoAVL<Key>* NodoAVL<Key>::getDcho() const {
// 	return dynamic_cast<NodoAVL<Key>*>(this->dcho_);
// }

// template<class Key>
// NodoAVL<Key>*& NodoAVL<Key>::getDcho() {
// 	NodoB<Key>*& dcho = this->dcho_;
// 	return dynamic_cast<NodoAVL<Key>*&>(dcho);
// }

template <class Key>
inline int &NodoAVL<Key>::getBal()
{
  return bal_;
}
