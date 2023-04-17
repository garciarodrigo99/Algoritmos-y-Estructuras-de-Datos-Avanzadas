/**
 * @file main.cpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Implementación de métodos de ordenación
 * @brief Cabecera de la clase HeapSortMethod, derivada de la clase SortMethod
 * @version 1.0
 * @date 17-04-2023
 */

// Complejidad O(n log n)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_322
#include "../Base_class/SortMethod.hpp"
#include "../../../lib/sortFunctions.hpp"

template<class Key>
class HeapSortMethod : public SortMethod<Key>{

public:
    HeapSortMethod(std::vector<Key>&, bool = true);
    ~HeapSortMethod() override;
    void Sort() override;
};

template<class Key>
HeapSortMethod<Key>::HeapSortMethod(std::vector<Key>& vct_p, 
					bool manualOption) : SortMethod<Key>(vct_p) {
	this->manualValues = manualOption;
}

template<class Key>
HeapSortMethod<Key>::~HeapSortMethod(){}

template <class Key>
inline void HeapSortMethod<Key>::Sort()
{
    heapSortFunction(this->vector_,this->size_,this->manualValues);
}