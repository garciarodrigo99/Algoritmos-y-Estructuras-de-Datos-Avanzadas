#include "../Base_class/ABB.hpp"
#include "../../../../NodoB/Derived_class/NodoAVL.hpp"
#include <vector>
#pragma once

template<class Key>
class AVL : public ABB<Key>{
	private:
    // int bal;

	public:
		AVL();
		~AVL();
    const bool Equilibrado();
    const int Tam();
    bool insertar(const Key&) override;

  private:
    const bool EquilibrioRama(NodoB<Key>*);
    const int TamRama(NodoB<Key>*);
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
const bool AVL<Key>::Equilibrado(){
  return EquilibrioRama(this->raiz_);
}

template <class Key>
const int AVL<Key>::Tam() { return TamRama(this->raiz_); }

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

template<class Key> const bool AVL<Key>::EquilibrioRama(NodoB<Key> *nodo)
{
  if (nodo == nullptr) return true;
  int ramI = TamRama(nodo->izdo);
  int ramD = TamRama(nodo->dcho);
  int eq = ramI - ramD;
  switch (eq) {
    case -1: 
    case  0:
    case  1:
    return EquilibrioRama(nodo->izdo) && 
           EquilibrioRama(nodo->dcho);
    default: return false;
  }
}

template <class Key>
const int AVL<Key>::TamRama(NodoB<Key>* nodo) {
  if (nodo == NULL) return 0 ;
  return (1 + TamRama(nodo->izdo) + 
              TamRama(nodo->dcho) );
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
        //crece = false;  
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
        //crece = false;
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
        crece = false;
      }

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
      NodoAVL<Key>* dchoCast = dynamic_cast<NodoAVL<Key>*>(nodo->getDcho());
      NodoAVL<Key>* nodo1 = dchoCast;
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
        crece = false;
      }
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
  // NodoAVL<Key>* nodo1 = nodo->getIzdo();
  // NodoAVL<Key>* nodo2 = nodo1->getDcho();
  //----------------------------------------------
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
  NodoAVL<Key>* dchoCast = dynamic_cast<NodoAVL<Key>*>(nodo->getDcho());
  NodoAVL<Key>* nodo1 = dchoCast;

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
