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

    // int alg = inputData<int>('a');//b)
    // long tam_sec = inputData<long>('t');//b)
    // char form = inputData<char>('f');
    int alg = 2;
    int tam_sec = 10;
    char form = 'a';

    system("clear");

    //std::vector<int> vect = {44,55,12,42,94,18,6,67}; //a)
    std::vector<int> vect;
    //c)
    if (form == 'a'){
        srand(time(NULL));                // Funciona sin esta línea también
        for (long i = 0; i < tam_sec; i++){
            vect.push_back(getRandom<int>(rango_inferior,rango_superior));//d)
        }
        
    } else{
        for (long i = 0; i < tam_sec; i++){
            std::cout << "Introduzca el dato " << i+1 << ": ";
            int data;
            std::cin>>data;
            vect.push_back(data); 
        }
    }

    std::cout << "Vector NO ordenado:\n";
    for (size_t i = 0; i < vect.size(); i++){
        std::cout << vect[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    std::cout << "\n";
    SortMethod<int>* m_ptr;//a)
    switch (alg){
        case 1:
            m_ptr = new InsertionSortMethod<int>(vect, tam_sec);
            break;
        case 2:
            m_ptr = new MergeSortMethod<int>(vect, tam_sec);
            break;
        case 3: {
            float alfa = inputData<float>('c');
            std::cout << "alfa = " << alfa << std::endl;
            m_ptr = new ShellShortMethod<int>(vect, tam_sec,alfa);            
            break;
        }
        case 4:
            m_ptr = new HeapSortMethod<int>(vect, tam_sec);
            break;
        case 5:
            m_ptr = new RadixSortMethod<int>(vect, tam_sec);
            break;
        case 6:
            m_ptr = new SelectionSortMethod<int>(vect, tam_sec);
            break;
        case 7:
            m_ptr = new QuickSortMethod<int>(vect, tam_sec);
            break; 

        default:
            break;
    }
    std::vector<int> nonOrderedVector = vect;
    m_ptr->Sort();
    std::cout<< "Vector ordenado:\n";
    for (size_t i = 0; i < vect.size(); i++){
        std::cout << vect[i] << "\t";
        if ((i % 25) == 24)
            std::cout << "\n";
    }
    std::cout << "\n";

    return 0;
}