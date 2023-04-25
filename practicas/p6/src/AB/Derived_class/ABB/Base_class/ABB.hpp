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

#include "../../../Base_class/AB.hpp"
#include <vector>
#pragma once

template<class Key>
class ABB : public AB<Key>{
	protected:

	public:
		ABB(){}
		~ABB(){}
		bool insertar(const Key&) override;
		bool buscar(const Key&) const override;
		void inorden() const;
};

// #include "../Derived_class/heapsort.hpp"
// #include "../Derived_class/insertion.hpp"

template <class Key>
inline bool ABB<Key>::insertar(const Key &)
{
    return false;
}

template <class Key>
inline bool ABB<Key>::buscar(const Key &) const
{
    return false;
}

template <class Key>
inline void ABB<Key>::inorden() const
{
}