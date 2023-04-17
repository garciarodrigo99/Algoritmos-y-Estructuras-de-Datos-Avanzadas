/**
 * @file main.cpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Implementación de métodos de ordenación
 * @brief Cabecera de la clase ShellShortMethod, derivada de la clase 
 * SortMethod
 * @version 1.0
 * @date 17-04-2023
 */

// Complejidad O(n^(alfa))
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_600
#include "../Base_class/SortMethod.hpp"

template<typename Key>
void deltaSort(std::vector<Key>& seq, unsigned size, float delta) {
    for (unsigned i = delta; i < size; i++){
        Key x = seq[i];
        int j = i;
        while ((j >= delta) && (x<seq[j-delta])){
            seq[j]=seq[j-delta];
            j=j-delta;
        }
        seq[j]=x;
    }
}

template<typename Key>
void shellSortFunction(std::vector<Key>& seq, unsigned size, float alfa = 0.5,
											bool printTrace = true) {
	// float delta = size * alfa;
	float delta = size;
	int contador = 0;
	while (delta > 1.0){
			delta *= alfa;
			deltaSort(seq,size,delta);
			contador++;
	}
}

template<class Key>
class ShellShortMethod : public SortMethod<Key>{

public:
    ShellShortMethod(std::vector<Key>&,float = 0.5,bool = true);
    ~ShellShortMethod() override;
    void Sort() override;

private:
    float alfa_ = 0.5;
};

template<class Key>
ShellShortMethod<Key>::ShellShortMethod(std::vector<Key>& vct_p, float alfa_p, 
	bool manualOption) : SortMethod<Key>(vct_p), alfa_(alfa_p) {
	this->manualValues = manualOption;
}

template<class Key>
ShellShortMethod<Key>::~ShellShortMethod(){}

template <class Key>
inline void ShellShortMethod<Key>::Sort()
{
    shellSortFunction(this->vector_,this->size_,alfa_,this->manualValues);
}