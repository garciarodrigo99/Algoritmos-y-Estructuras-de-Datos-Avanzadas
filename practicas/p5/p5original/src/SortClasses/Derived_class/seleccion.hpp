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
template<typename Key>
void selectionSortFunction(std::vector<Key>& seq, unsigned size,
													bool printTrace = true) {
    for (size_t i = 0; i < seq.size() - 1; i++){
        int indice_menor = i;
        Key valor_menor = seq[i];
        for (size_t j = i + 1; j < seq.size(); j++){
            if (seq[j] < valor_menor){
                valor_menor = seq[j];
                indice_menor = j;
            }
        }
        std::swap(seq[i],seq[indice_menor]);
    }
};

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