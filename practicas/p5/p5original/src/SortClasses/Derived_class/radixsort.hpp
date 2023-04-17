/**
 * @file main.cpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Implementación de métodos de ordenación
 * @brief Cabecera de la clase RadixSortMethod, derivada de la clase SortMethod
 * @version 1.0
 * @date 17-04-2023
 */

// Complejidad O(nk)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_742

#include "../Base_class/SortMethod.hpp"
#include "../../../lib/sortFunctions.hpp"

template<class Key>
class RadixSortMethod : public SortMethod<Key>{

public:
    RadixSortMethod(std::vector<Key>&, bool = true);
    ~RadixSortMethod() override;
    void Sort() override;
};

template<class Key>
RadixSortMethod<Key>::RadixSortMethod(std::vector<Key>& vct_p, 
					bool manualOption) : SortMethod<Key>(vct_p) {
	this->manualValues = manualOption;
}

template<class Key>
RadixSortMethod<Key>::~RadixSortMethod(){}

template <class Key>
inline void RadixSortMethod<Key>::Sort()
{
    radixSortFunction(this->vector_,this->size_, this->manualValues);
}