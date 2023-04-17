/**
 * @file main.cpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Implementación de métodos de ordenación
 * @brief Cabecera de la clase QuickSortMethod, derivada de la clase 
 * SortMethod
 * @version 1.0
 * @date 17-04-2023
 */

// Complejidad Promedio: O(n log n),
//            peor caso: O(n²)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_504

#include "../Base_class/SortMethod.hpp"
#include "../../../lib/sortFunctions.hpp"

template<class Key>
class QuickSortMethod : public SortMethod<Key>{

public:
    QuickSortMethod(std::vector<Key>&, bool = true);
    ~QuickSortMethod() override;
    void Sort() override;
};

template<class Key>
QuickSortMethod<Key>::QuickSortMethod(std::vector<Key>& vct_p, 
					bool manualOption) : SortMethod<Key>(vct_p) {
	this->manualValues = manualOption;
}

template<class Key>
QuickSortMethod<Key>::~QuickSortMethod(){}


template <class Key>
inline void QuickSortMethod<Key>::Sort()
{
    quickSortFunction(this->vector_,0,this->size_-1,this->manualValues);
}