/**
 * @file main.cpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Implementación de métodos de ordenación
 * @brief Cabecera de la clase SelectionSortMethod, derivada de la clase 
 * SortMethod
 * @version 1.0
 * @date 17-04-2023
 */

// Complejidad O(n²)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_185

#include "../Base_class/SortMethod.hpp"
#include "../../../lib/sortFunctions.hpp"

template<class Key>
class SelectionSortMethod : public SortMethod<Key>{

public:
    SelectionSortMethod(std::vector<Key>&, bool = true);
    ~SelectionSortMethod() override;
    void Sort() override;
};

template<class Key>
SelectionSortMethod<Key>::SelectionSortMethod(std::vector<Key>& vct_p, 
													bool manualOption) : SortMethod<Key>(vct_p) {
	this->manualValues = manualOption;
}

template<class Key>
SelectionSortMethod<Key>::~SelectionSortMethod(){}

template <class Key>
inline void SelectionSortMethod<Key>::Sort()
{
    selectionSortFunction(this->vector_,this->size_, this->manualValues);
}