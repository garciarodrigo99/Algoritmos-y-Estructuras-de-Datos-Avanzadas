/**
 * @file SortMethod.hpp
 * @author Rodrigo Garcia Jimenez (alu0101154473@ull.edu.es)
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Algoritmos y Estructuras de Datos Avanzadas
 * Curso: 2º
 * Práctica 5: Implementación de métodos de ordenación
 * @brief Cabecera de la clase abstracta SortMethod
 * @version 1.0
 * @date 17-04-2023
 */

// El código 2, por otro lado, utiliza variables de instancia protegidas en la clase base, lo que permite que la clase derivada InsertionSortMethod tenga acceso a estas variables de instancia sin necesidad de almacenar una referencia en una variable miembro. Esto hace que el código sea más seguro y prevenido de posibles errores.
// En general, se recomienda utilizar variables de instancia protegidas en la clase base en lugar de variables de instancia privadas en la clase derivada, ya que esto hace que el código sea más seguro y menos propenso a errores.

#include <vector>
#pragma once

template<class Key>
class SortMethod{
    protected:
        std::vector<Key>& vector_;
        long size_;
        bool manualValues;

    public:
        SortMethod(std::vector<Key>& vct) : vector_(vct),size_(vct.size()){}
        virtual ~SortMethod(){}
        virtual void Sort() = 0;
};

#include "../Derived_class/heapsort.hpp"
#include "../Derived_class/insertion.hpp"
#include "../Derived_class/mergesort.hpp"
#include "../Derived_class/quicksort.hpp"
#include "../Derived_class/radixsort.hpp"
#include "../Derived_class/seleccion.hpp"
#include "../Derived_class/shellsort.hpp"