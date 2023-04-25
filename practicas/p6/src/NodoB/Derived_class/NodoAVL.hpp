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
class NodoAVL : public NodoB{
	private:
		int bal;

	public:
		SortMethod(std::vector<Key>& vct) : vector_(vct),size_(vct.size()){}
		virtual ~SortMethod(){}
		virtual void Sort() = 0;
};