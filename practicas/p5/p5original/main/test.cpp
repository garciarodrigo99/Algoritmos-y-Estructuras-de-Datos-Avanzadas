/**
 * @file main.cpp
 * @author Rodrigo García Jiménez (alu0101154473@ull.edu.es)
 * @title Programa principal de la práctica 5 de Algoritmos y Estructuras de Datos Avanzadas
 * @brief 
 * @version 1.0
 * @date 25-04-2022
 * g++ -std=c++14 -g -Wall -o main main.cpp 
 */



#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <string>
#include <iostream>
#include <cassert>
#include <utility>
#include "../src/SortClasses/Base_class/SortMethod.hpp"

#define rango_inferior 1000
#define rango_superior 9999



/** @fn inputData
 *  @brief Funcion para externalizar la recogida de datos(algoritmo,forma de 
 *         rellenar el vector, tamaño y alfa si hiciera falta). 
 *  @param option Inicial en inglés del dato que queremos rellenar.
 *  @return value Cantidad del tipo de dato introducido por pantalla 
 */
template<typename T>
T inputData(char option){
    switch (option){
        case 'a': {
            int aux = 0;
            do{
                std::cout << "\nElija el algoritmo a ejecutar: \n";
                std::cout << "[1] Selección\n"
                "[2] Inserción\n"
                "[3] QuickSort\n"
                "[4] ShellSort\n"
                "[5] HeapSort\n"
                "[6] RadixSort\n";
                std::cin >> aux;
            } while ((aux < 1) || (aux > 6));
            return aux;
        } break;
        
        case 'f': {
            char aux = '0';
            do{
                std::cout << "\n¿Desea introducir los numeros de forma aleatoria o manual?[a/m]: ";
                std::cin>>aux;
            }while ((aux != 'a') && (aux != 'A') && (aux != 'm') && (aux != 'M'));
            if ((aux == 'M') || (aux == 'A'))
                aux += aux + 32;
            return aux;
        }break;

        case 't': {
            long aux = 0;
            do{
                std::cout << "\nIntroduzca el tamaño de la secuencia: ";
                std::cin >> aux;
            }while(aux <= 0);
            return aux;
        }break;

        case 'c': {
            float aux = 0.0;
            do{
                std::cout << "\nSeleccione el valor de la constante de reducción"
                "(flotante entre 0 y 1) para el algoritmo seleccionado(ShellSort): ";
                std::cin>>aux;
            }while ((aux <= 0.0) && (aux >= 1.0));
            return aux;
        }break;

        default:
            throw std::invalid_argument("Parametro no valido");
            return -1;
    }
}



/** @fn getRandom
 *  @brief Funcion que calcula un numero aleatorio
 *  @param  inf_num Rango inferior
 *  @param  sup_num Rango superior
 *  @return value Valor aleatorio calculado
 */
template<typename T>
T getRandom(T inf_num, T sup_num){
    assert(sup_num >= inf_num);
    //srand(time(NULL));
    return ((rand() % (sup_num - inf_num)) + inf_num);
}



/** @fn main
 *  @brief Programa principal
 *  @param void
 *  @return 0
 */
int main(int argc, char* argv[]){

    std::vector<int> originalVector = {44,55,12,42,94,18,6,67}; //a)
    SortMethod<int>* m_ptr;//a)
    std::cout << "Hola\n";
//-----------------------------------------------------------------------------
    // Módulo Inserción
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\t\tInserción\n";
    std::vector<int> insercionVector = originalVector;
    m_ptr = new InsertionSortMethod<int>(insercionVector, insercionVector.size());
    std::cout << "Vector NO ordenado:\n";
    for (size_t i = 0; i < insercionVector.size(); i++){
        std::cout << insercionVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    m_ptr->Sort();
    std::cout<< "\nVector ordenado:\n";
    for (size_t i = 0; i < insercionVector.size(); i++){
        std::cout << insercionVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    std::cout << "\n-------------------------------------------------------\n";
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
    // Módulo Merge
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\t\tMerge\n";
    std::vector<int> mergeVector = originalVector;
    m_ptr = new MergeSortMethod<int>(mergeVector, mergeVector.size());
    std::cout << "Vector NO ordenado:\n";
    for (size_t i = 0; i < mergeVector.size(); i++){
        std::cout << mergeVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    m_ptr->Sort();
    std::cout<< "\nVector ordenado:\n";
    for (size_t i = 0; i < mergeVector.size(); i++){
        std::cout << mergeVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    std::cout << "\n-------------------------------------------------------\n";
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
    // Módulo ShellSort
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\t\tShellSort\n";
    std::vector<int> ShellSortVector = originalVector;
    m_ptr = new ShellShortMethod<int>(ShellSortVector, ShellSortVector.size());
    std::cout << "Vector NO ordenado:\n";
    for (size_t i = 0; i < ShellSortVector.size(); i++){
        std::cout << ShellSortVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    m_ptr->Sort();
    std::cout<< "\nVector ordenado:\n";
    for (size_t i = 0; i < ShellSortVector.size(); i++){
        std::cout << ShellSortVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    std::cout << "\n-------------------------------------------------------\n";
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
    // Módulo HeapSort
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\t\tHeapSort\n";
    std::vector<int> HeapSortVector = originalVector;
    m_ptr = new HeapSortMethod<int>(HeapSortVector, HeapSortVector.size());
    std::cout << "Vector NO ordenado:\n";
    for (size_t i = 0; i < HeapSortVector.size(); i++){
        std::cout << HeapSortVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    m_ptr->Sort();
    std::cout<< "\nVector ordenado:\n";
    for (size_t i = 0; i < HeapSortVector.size(); i++){
        std::cout << HeapSortVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    std::cout << "\n-------------------------------------------------------\n";
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
    // Módulo Radix
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\t\tRadix\n";
    std::vector<int> radixVector = originalVector;
    m_ptr = new RadixSortMethod<int>(radixVector, radixVector.size());
    std::cout << "Vector NO ordenado:\n";
    for (size_t i = 0; i < radixVector.size(); i++){
        std::cout << radixVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    m_ptr->Sort();
    std::cout<< "\nVector ordenado:\n";
    for (size_t i = 0; i < radixVector.size(); i++){
        std::cout << radixVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    std::cout << "\n-------------------------------------------------------\n";
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
    // Módulo Selection
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\t\tSelection\n";
    std::vector<int> selectionVector = originalVector;
    m_ptr = new SelectionSortMethod<int>(selectionVector, selectionVector.size());
    std::cout << "Vector NO ordenado:\n";
    for (size_t i = 0; i < selectionVector.size(); i++){
        std::cout << selectionVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    m_ptr->Sort();
    std::cout<< "\nVector ordenado:\n";
    for (size_t i = 0; i < selectionVector.size(); i++){
        std::cout << selectionVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    std::cout << "\n-------------------------------------------------------\n";
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
    // Módulo Quicksort
    std::cout << "\n-------------------------------------------------------\n";
    std::cout << "\t\tQuicksort\n";
    std::vector<int> QuicksortVector = originalVector;
    m_ptr = new QuickSortMethod<int>(QuicksortVector, QuicksortVector.size());
    std::cout << "Vector NO ordenado:\n";
    for (size_t i = 0; i < QuicksortVector.size(); i++){
        std::cout << QuicksortVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    m_ptr->Sort();
    std::cout<< "\nVector ordenado:\n";
    for (size_t i = 0; i < QuicksortVector.size(); i++){
        std::cout << QuicksortVector[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    std::cout << "\n-------------------------------------------------------\n";
//-----------------------------------------------------------------------------


    return 0;
}