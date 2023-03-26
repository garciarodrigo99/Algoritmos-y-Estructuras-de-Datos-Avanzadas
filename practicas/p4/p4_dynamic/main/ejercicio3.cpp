/**
 * @file main.cpp
 * @author Rodrigo García Jiménez (alu0101154473@ull.edu.es)
 * @title Programa principal de la práctica 4 de Algoritmos y Estructuras de Datos Avanzadas
 * @brief 
 * @version 1.0
 * @date 07-04-2022
 * g++ -std=c++14 -g -Wall -o main main.cpp 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "../src/HashTable/hashtable.hpp"


int main(int argc, char* argv[]){
// 	// dni aux(35704589,'X');
// 	// std::cout << aux.getDni() << std::endl;


//     //a)
// //-----------------------------------------------------------------------------
//     unsigned int tam_tabla = 0;
//     do{
//         std::cout << "Introduzca el tamaño de la tabla: ";
//         std::cin >> tam_tabla;
//     }while(tam_tabla == 0);
// //-----------------------------------------------------------------------------

//     int func_disp = 0;
//     do{
//         std::cout << "\nElija la FUNCION de dispersion: \n";
//         std::cout << "[1] Modulo\n"
//         "[2] Basada en la suma\n"
//         "[3] Pseudoaleatoria\n";
//         std::cin >> func_disp;
//     } while ((func_disp < 1) || (func_disp > 3));

// //-----------------------------------------------------------------------------
//     int tec_disp = 0;
//     do{
//     std::cout << "\nElija la TECNICA de dispersion: \n";
//     std::cout << "[1] Dispersión abierta\n"
//                  "[2] Dispersión cerrada\n";
//     std::cin >> tec_disp;
//     } while ((tec_disp < 1) || (tec_disp > 2));

//     // b)
//     int func_exp = 0;
//     int tam_bloque = 0;
//     if (tec_disp == 2){
//         do{
//             std::cout << "\nElija la función de exploración: \n";
//             std::cout << "[1] Exploración lineal\n"
//             "[2] Exploración cuadrática\n"
//             "[3] Doble dispersión\n"
//             "[4] Redispersión\n";
//             std::cin >> func_exp;
//         } while ((func_exp < 1) || (func_exp > 4));

//         std::cout << "Introduzca el tamaño del bloque: ";
//         std::cin >> tam_bloque;
//     }
    //d)
    //HashTable<dni> myTable(tam_tabla,func_disp,func_exp,tam_bloque);
    HashTable<long> myTable(7,1,2,3);
    myTable.Insert(1);
    myTable.Insert(8);
    myTable.Insert(2);
    myTable.Insert(4);
    myTable.Insert(5);
    myTable.Insert(12);
    myTable.Insert(6);
    myTable.Insert(13);
    myTable.Insert(20);
    myTable.Print();
    std::cout << "\n-------------------------------------------------------\n";
    myTable.Insert(49007023);
    myTable.Print();
    std::cout << "\n-------------------------------------------------------\n";
    myTable.Insert(56070033);
    myTable.Print();
    std::cout << "\n-------------------------------------------------------\n";
    myTable.Insert(42077015);
    myTable.Print();
    std::cout << "\n-------------------------------------------------------\n";
    myTable.Insert(42007705);
    myTable.Print();
    std::cout << "\n-------------------------------------------------------\n";
    myTable.Insert(49777778);
    myTable.Print();
    std::cout << "\n-------------------------------------------------------\n";
    myTable.Insert(42000037);
    myTable.Print();
    std::cout << "\n-------------------------------------------------------\n";

	// 	// srand(time(NULL));
	// 	std::ifstream file("../input/dni.in");

    // if (!file) {
    //     std::cerr << "Error: no se pudo abrir el archivo.\n";
    //     return 1;
    // }

    // std::string line;
    // while (std::getline(file, line)) {
    //     std::stringstream ss(line);
    //     long number;
    //     char letter;
    //     char comma;
    //     if (ss >> number >> comma >> letter) {
    //       // Procesar la línea leída
    //       std::cout << "DNI: " << number << ", letra: " << letter << '\n';
	// 				dni myDni(number,letter);
	// 				if (myTable.Insert(myDni))
	// 		    	std::cout << myDni.getDni() << " insertado\n";
	// 				else
	// 		    	std::cout << myDni.getDni() << "NO insertado\n";
				
	// 				myTable.Print();
    //     } else {
    //         std::cerr << "Error: formato incorrecto de línea.\n";
    //     }
    // }
    // for (size_t i = 0; i < 10; i++){
		// 	dni dr('r');
    // 	if (myTable.Insert(dr))
    //     std::cout << dr.getDni() << " insertado\n";
    // 	else
    //     std::cout << dr.getDni() << "NO insertado\n";
			
		// 	myTable.Print();
    // }

    // dni d2(50085200,'Z');
    // std::cout << d2 << std::endl;
    // fdSum<dni> fdS(10);
    // std::cout << fdS(d2);
    // long cif = 50085200;
    // std::cout << cif << std::endl;
    // fdSum<long> fdSlong(10);
    // std::cout << fdSlong(cif);

    return 0;
}