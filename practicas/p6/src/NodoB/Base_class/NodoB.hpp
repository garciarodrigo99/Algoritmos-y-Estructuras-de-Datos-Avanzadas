/**
 * @file NodoB.hpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @brief Cabecera de la clase plantilla NodoB(nodo binario)
 * @version 1.0
 * @date 08-05-2023
 */

#include <vector>
#pragma once

template<class Key>
class NodoB{
	protected:
		Key dato_;
		NodoB<Key>* izdo_;
		NodoB<Key>* dcho_;

	public:
		NodoB(Key, NodoB<Key>* = nullptr,NodoB<Key>* = nullptr);
		virtual ~NodoB();

		NodoB<Key>* getIzdo() const;
		NodoB<Key>*& getIzdo();
		NodoB<Key>* getDcho() const;
		NodoB<Key>*& getDcho();
		Key getDato();
		Key getDato() const;
};

template<class Key>
NodoB<Key>::NodoB(Key value, NodoB<Key>* lhs,
									NodoB<Key>* rhs) : 
									dato_(value), izdo_(lhs), dcho_(rhs) {}
							
template<class Key>
NodoB<Key>::~NodoB() {}

template<class Key>
NodoB<Key>* NodoB<Key>::getIzdo() const {return izdo_;}

template<class Key>
NodoB<Key>*& NodoB<Key>::getIzdo() {return izdo_;}

template<class Key>
NodoB<Key>* NodoB<Key>::getDcho() const {return dcho_;}

template<class Key>
NodoB<Key>*& NodoB<Key>::getDcho() {return dcho_;}

template <class Key>
Key NodoB<Key>::getDato()
{
  return dato_;
}

template <class Key>
inline Key NodoB<Key>::getDato() const
{
    return dato_;
}