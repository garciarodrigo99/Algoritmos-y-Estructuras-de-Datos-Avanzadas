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
#include "../../../lib/sortFunctions.hpp"

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