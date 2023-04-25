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
#pragma once

template<class Key>
class NodoB{
	protected:
		Key dato_;
		NodoB<Key>* izdo_;
		NodoB<Key>* dcho_;

	public:
		NodoB(Key, NodoB<Key>* = nullptr,NodoB<Key>* = nullptr);
		virtual ~NodoB(){}
};

template<class Key>
NodoB<Key>::NodoB(Key value, NodoB<Key>* lhs,
									NodoB<Key>* rhs) : 
									dato_(value), izdo_(lhs), dcho_(rhs) {}