#include "../Base_class/ABB.hpp"
#include "../../../../NodoB/Derived_class/NodoAVL.hpp"
#include <vector>
#pragma once

template<class Key>
class AVL : public ABB<Key>{
	private:
    int bal;

	public:
		AVL();
		~AVL();
    const bool Equilibrado();
    const int Tam();
    bool insertar(const Key&) override;

  private:
    const bool EquilibrioRama(NodoB<Key>*);
    const int TamRama(NodoB<Key>*);
    void inserta_bal(NodoAVL<Key>*&,NodoAVL<Key>*&,bool&);
		void insert_re_balancea_izda(NodoAVL<Key>*&);
    void insert_re_balancea_dcha(NodoAVL<Key>*&);
    void rotacion_II (NodoAVL<Key>* &);
    void rotacion_ID (NodoAVL<Key>* &);
    void rotacion_DD (NodoAVL<Key>* &);
    void rotacion_DI (NodoAVL<Key>* &);
};

template <class Key>
AVL<Key>::AVL()
{
  bal = 0;
}

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
  inserta_bal(nodo_raiz,nuevo,crece);
  return false;
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
void AVL<Key>::inserta_bal(NodoAVL<Key>*& nodo, NodoAVL<Key>*& nuevo, bool& crece)
{
  if (nodo == nullptr) {
    nodo = nuevo;
    crece = true;
  }
  else if (nuevo->getDato() < nodo->getDato()) {
    NodoAVL<Key>* nodoIzdoCast = dynamic_cast<NodoAVL<Key>*>(nodo->getIzdo());
    inserta_bal(nodoIzdoCast,nuevo,crece);
    if (crece) insert_re_balancea_izda(nodo);
  }
  else {
    NodoAVL<Key>* nodoDchoCast = dynamic_cast<NodoAVL<Key>*>(nodo->getDcho());
    inserta_bal(nodoDchoCast,nuevo,crece);
    if (crece)
      insert_re_balancea_dcha(nodo);
  }
}

template <class Key>
void AVL<Key>::insert_re_balancea_izda(NodoAVL<Key>*& nodo)
{
  switch (nodo->getBal()) {
    case -1: nodo->getBal() = 0;
              crece = false;
              break; 
    case  0: nodo->getBal() = 1 ;
              break; 
    case  1: {
      NodoAVL<Key>* izdoCast = dynamic_cast<NodoAVL<Key>*>(nodo->getIzdo());
      NodoAVL<Key>* nodo1 = izdoCast;
      if (nodo1->getBal() == 1)
        rotacion_II(nodo);
      else rotacion_ID(nodo);
        crece = false;
    }
  }
}

template <class Key>
void AVL<Key>::insert_re_balancea_dcha(NodoAVL<Key>*& nodo)
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
      if (nodo1->getBal() == -1)
        rotacion_DD(nodo);
      else rotacion_DI(nodo);
        crece = false;
    }
  }
}

template <class Key>
void AVL<Key>::rotacion_II(NodoAVL<Key> *& nodo) {
  NodoAVL<Key>* izdoCast = dynamic_cast<NodoAVL<Key>*>(nodo->getIzdo());
  NodoAVL<Key>* nodo1 = izdoCast;

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
inline void AVL<Key>::rotacion_ID(NodoAVL<Key> *& k) {}

template <class Key>
inline void AVL<Key>::rotacion_DD(NodoAVL<Key> *& nodo) {
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
inline void AVL<Key>::rotacion_DI(NodoAVL<Key> *& k) {}

