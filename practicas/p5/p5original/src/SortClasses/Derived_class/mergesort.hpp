/**
 * @file main.cpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Implementación de métodos de ordenación
 * @brief Cabecera de la clase MergeSortMethod, derivada de la clase SortMethod
 * @version 1.0
 * @date 17-04-2023
 */

// Complejidad O(nk)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_562

#include "../Base_class/SortMethod.hpp"
#include "../../../lib/sortFunctions.hpp"

template<class Key>
class MergeSortMethod : public SortMethod<Key>{

public:
    MergeSortMethod(std::vector<Key>&, bool = true);
    ~MergeSortMethod() override;
    void Sort() override;
};

template<class Key>
MergeSortMethod<Key>::MergeSortMethod(std::vector<Key>& vct_p, 
	bool manualOption) : SortMethod<Key>(vct_p) {
	this->manualValues = manualOption;
}

template<class Key>
MergeSortMethod<Key>::~MergeSortMethod(){}

template <class Key>
inline void MergeSortMethod<Key>::Sort()
{
  mergeSortFunction(this->vector_,0,this->size_-1, this->manualValues);
}