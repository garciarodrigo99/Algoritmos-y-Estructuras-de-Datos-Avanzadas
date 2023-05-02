/**
 * @file AVL.hpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 6: Implementación del TDA Árbol
 * @brief Cabecera de la clase plantilla AVL(Árbol binario de búsqueda balanceado)
 * @version 1.0
 * @date 08-05-2023
 */

#include "../Base_class/ABB.hpp"
#include "../../../../NodoB/Derived_class/NodoAVL.hpp"
#include <vector>
#pragma once

template<class Key>
class AVL : public ABB<Key>{

	public:
		AVL();
		~AVL();
    bool insertar(const Key&) override;

  private:
    bool inserta_bal(NodoAVL<Key>*&,NodoAVL<Key>*&,bool&);
		void insert_re_balancea_izda(NodoAVL<Key>*&, bool&);
    void insert_re_balancea_dcha(NodoAVL<Key>*&, bool&);
    void rotacion_II (NodoAVL<Key>* &);
    void rotacion_ID (NodoAVL<Key>* &);
    void rotacion_DD (NodoAVL<Key>* &);
    void rotacion_DI (NodoAVL<Key>* &);
    void printBal();
};

template <class Key>
AVL<Key>::AVL()
{}

template <class Key>
AVL<Key>::~AVL()
{
}

template <class Key>
bool AVL<Key>::insertar(const Key& k)
{
  NodoAVL<Key>* nuevo = new NodoAVL<Key>(k);
  bool crece = false;
  NodoAVL<Key>* nodo_raiz = dynamic_cast<NodoAVL<Key>*>(this->raiz_);
  bool toReturn = inserta_bal(nodo_raiz,nuevo,crece);
  this->raiz_ = dynamic_cast<NodoB<Key>*>(nodo_raiz); // Actualizar raiz_
  #ifdef TRAZA
    printBal();
  #endif
  return toReturn;
}

template <class Key>
bool AVL<Key>::inserta_bal(NodoAVL<Key>*& nodo, NodoAVL<Key>*& nuevo, bool& crece)
{ 
  //bool rotado = false;
  if (nodo == nullptr) {
    nodo = nuevo;
    crece = true;
    return true;
  }
  if (nuevo->getDato() == nodo->getDato()){
    return false;
  } 
  if (nuevo->getDato() < nodo->getDato()) {
    NodoAVL<Key>* nodoIzdoCast = dynamic_cast<NodoAVL<Key>*>(nodo->getIzdo());
    bool insertado = inserta_bal(nodoIzdoCast,nuevo,crece);
    if (insertado) {
      nodo->getIzdo() = dynamic_cast<NodoB<Key>*>(nodoIzdoCast); // Actualizar raiz_
      if (crece) {
        insert_re_balancea_izda(nodo,crece);
      }
      return true;
    } else {
      return false;
    }
  } else {
    NodoAVL<Key>* nodoDchoCast = dynamic_cast<NodoAVL<Key>*>(nodo->getDcho());
    bool insertado = inserta_bal(nodoDchoCast,nuevo,crece);
    if (insertado){
      nodo->getDcho() = dynamic_cast<NodoB<Key>*>(nodoDchoCast); // Actualizar raiz_
      if (crece) {
        insert_re_balancea_dcha(nodo,crece);
      }
      return true;
    } else{
      return false;
    }
  }
}

template <class Key>
void AVL<Key>::insert_re_balancea_izda(NodoAVL<Key>*& nodo, bool& crece)
{
  switch (nodo->getBal()) {
    case -1: nodo->getBal() = 0;
              crece = false;
              break; 
    case  0: nodo->getBal() = 1 ;
              break; 
    case  1: {
      NodoAVL<Key>* nodo1 = dynamic_cast<NodoAVL<Key>*>(nodo->getIzdo());
      if (nodo1->getBal() == 1){
        #ifdef TRAZA
          std::cout << "Desbalanceo:\n";
          printBal();
          std::cout << *this;
      	  std::cout << "Rotación en II en [" << nodo->getDato() << "]:\n";
        #endif
        rotacion_II(nodo);
      } else { 
        if (nodo1->getBal() == -1) {
          #ifdef TRAZA
            std::cout << "Desbalanceo:\n";
            printBal();
            std::cout << *this;
            std::cout << "Rotación en ID en [" << nodo->getDato() << "]:\n";
          #endif
          rotacion_ID(nodo);
        }
      }
      crece = false;
    }
  }
}

template <class Key>
void AVL<Key>::insert_re_balancea_dcha(NodoAVL<Key>*& nodo, bool& crece)
{
  switch (nodo->getBal()) {
    case  1: nodo->getBal() = 0;
            crece = false;
            break; 
    case  0: nodo->getBal() = -1;
            break; 
    case -1: {
      NodoAVL<Key>* nodo1 = dynamic_cast<NodoAVL<Key>*>(nodo->getDcho());
      if (nodo1->getBal() == -1){
        #ifdef TRAZA
          std::cout << "Desbalanceo:\n";
          printBal();
          std::cout << *this;
      	  std::cout << "Rotación en DD en [" << nodo->getDato() << "]:\n";
        #endif
        rotacion_DD(nodo);
      }else {
        if (nodo1->getBal() == 1){
          #ifdef TRAZA
            std::cout << "Desbalanceo:\n";
            printBal();
            std::cout << *this;
            std::cout << "Rotación en DI en [" << nodo->getDato() << "]:\n";
          #endif
          rotacion_DI(nodo);
        }
      }
      crece = false;
    }
  }
}

template <class Key>
void AVL<Key>::rotacion_II(NodoAVL<Key> *& nodo) {
  NodoAVL<Key>* nodo1 = dynamic_cast<NodoAVL<Key>*>(nodo->getIzdo());

  nodo->getIzdo() = nodo1->getDcho();

  nodo1->getDcho() = nodo;

  if (nodo1->getBal() == 1) {
     nodo->getBal() = 0;
     nodo1->getBal() = 0;
  }
  else { // nodo1->getBal() == 0
    nodo->getBal() = 1;
    nodo1->getBal() = -1;
  }
  nodo = nodo1;

}

template <class Key>
void AVL<Key>::rotacion_ID(NodoAVL<Key>*& nodo) {
  NodoAVL<Key>* nodo1 = dynamic_cast<NodoAVL<Key>*>(nodo->getIzdo());
  NodoAVL<Key>* nodo2 = dynamic_cast<NodoAVL<Key>*>(nodo1->getDcho());
  //----------------------------------------------
  nodo->getIzdo() = nodo2->getDcho();
  nodo2->getDcho() = nodo;
  nodo1->getDcho() = nodo2->getIzdo();
  nodo2->getIzdo() = nodo1;
  if (nodo2->getBal() == -1) 
    nodo1->getBal() = 1;
  else nodo1->getBal() = 0;
  if (nodo2->getBal() == 1)
    nodo->getBal() = -1;
  else nodo->getBal() = 0;
  nodo2->getBal() = 0;
  nodo = nodo2;
}

template <class Key>
void AVL<Key>::rotacion_DD(NodoAVL<Key> *& nodo) {
  NodoAVL<Key>* nodo1 = dynamic_cast<NodoAVL<Key>*>(nodo->getDcho());

  nodo->getDcho() = nodo1->getIzdo();

  nodo1->getIzdo() = nodo;

  if (nodo1->getBal() == -1) {
     nodo->getBal() = 0;
     nodo1->getBal() = 0;
  }
  else { // nodo1->getBal() == 0
    nodo->getBal() = -1;
    nodo1->getBal() = 1;
  }
  nodo = nodo1;
}

template <class Key>
inline void AVL<Key>::rotacion_DI(NodoAVL<Key> *& nodo) {
  NodoAVL<Key>* nodo1 = dynamic_cast<NodoAVL<Key>*>(nodo->getDcho());
  NodoAVL<Key>* nodo2 = dynamic_cast<NodoAVL<Key>*>(nodo1->getIzdo());
  nodo->getDcho() = nodo2->getIzdo();
  nodo2->getIzdo() = nodo;
  nodo1->getIzdo() = nodo2->getDcho();
  nodo2->getDcho() = nodo1;
  if (nodo2->getBal() == 1) 
    nodo1->getBal() = -1;
  else nodo1->getBal() = 0;
  if (nodo2->getBal() == -1)
    nodo->getBal() = 1;
  else nodo->getBal() = 0;
  nodo2->getBal() = 0;
  nodo = nodo2;
}

template <class Key>
inline void AVL<Key>::printBal()
{
  int nivel = 0;
	std::queue<NodoAVL<Key>*> cola;
	cola.push(dynamic_cast<NodoAVL<Key>*>(this->raiz_));

	while (!cola.empty()){
		int nodosNivel = cola.size();
		std::cout << "Nivel " << nivel << ": ";
		for (int i = 0; i < nodosNivel; i++) {
			NodoAVL<Key>* nodoActual = cola.front();
			cola.pop();
			if (nodoActual == nullptr){
				std::cout << "{.} ";
			} else {
				std::cout << "{" << nodoActual->getBal() << "} ";
				cola.push(dynamic_cast<NodoAVL<Key>*>(nodoActual->getIzdo()));
				cola.push(dynamic_cast<NodoAVL<Key>*>(nodoActual->getDcho()));
			}
		}
		std::cout << "\n";
		nivel++;
	}
}
