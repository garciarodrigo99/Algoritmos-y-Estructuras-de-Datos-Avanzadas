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
		ABB();
		~ABB();
		bool insertar(const Key&) override;
		bool buscar(const Key&) const override;
		void inorden() const;

	private:
		bool BuscarRama(NodoB<Key>*, const Key&) const;
		bool InsertarRama(NodoB<Key>*&, const Key&);
};

template <class Key>
ABB<Key>::ABB(){}

template <class Key>
inline ABB<Key>::~ABB()
{
}

template <class Key>
inline bool ABB<Key>::insertar(const Key& k)
{	
	if (BuscarRama(this->raiz_,k))
		return false;
	return InsertarRama(this->raiz_,k);
}

template <class Key>
inline bool ABB<Key>::buscar(const Key & k) const
{
  return BuscarRama(this->raiz_,k);
}

template <class Key>
inline void ABB<Key>::inorden() const
{
}

template <class Key>
inline bool ABB<Key>::BuscarRama(NodoB<Key>* nodo, const Key& k) const
{
	if (nodo == nullptr)
		return false;

	if (k == nodo->getDato())
		return true;

	if (k < nodo->getDato())
		return BuscarRama(nodo->getIzdo(), k);
	
  return BuscarRama(nodo->getDcho(), k);
}

template <class Key>
inline bool ABB<Key>::InsertarRama(NodoB<Key>*& nodo, const Key& k)
{
	if (nodo == nullptr) {
		nodo = new NodoB<Key>(k);
		return true;
	}
	if (k < nodo->getDato()) {
		InsertarRama(nodo->getIzdo(),k);
	} else if (k > nodo->getDato()){
		InsertarRama(nodo->getDcho(),k);
	}
	return true;
}
