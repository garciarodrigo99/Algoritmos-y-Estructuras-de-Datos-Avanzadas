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

template<class Key>
void baja(std::vector<Key>& vector,long size,int iteracion){
    //std::cout << "Estás en baja()\n";
    int h = iteracion;
    int h1 = (2*iteracion); 
    int h2 = h1 + 1;
    if((h1 < size) && (vector[h1] > vector[h]))
        //std::cout << "Baja\n";
        h = h1;

    if((h2 < size) && (vector[h2] > vector[h]))
        //std::cout << "Sube\n";
        h = h2;
    
    if(h != iteracion) {
        //std::cout << "Colocado\n";
        std::swap(vector[iteracion],vector[h]);
        baja(vector,size,h);
    }
}

template<typename Key>
void heapSortFunction(std::vector<Key>& seq, unsigned size, 
                    	bool printTrace = true ) {
    //Algoritmo HeapSort
    for(int i = (size/2)-1; i >= 0; i--){
        baja(seq, size,i);
    }
    for(int i = size-1; i >= 0; i--){
        std::swap(seq[0],seq[i]);
        baja(seq,i,0);
    }
}

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