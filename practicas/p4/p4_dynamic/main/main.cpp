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
	// dni aux(35704589,'X');
	// std::cout << aux.getDni() << std::endl;


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
    HashTable<dni> myTable(7,1,0,0);
    //HashTable<dni> myTable(10,1,1,2);

    // e) A continuación implementa un menú que permite insertar y buscar los
    // valores de clave indicados por el usuario, y muestra el resultado de la 
    // operación.
    // dni d1(78850941,'H');
    // if (myTable.Insert(d1)){
    //     std::cout << d1.getDni() << " insertado\n";
    // } else
    //     std::cout << d1.getDni() << "NO insertado\n";

    // dni d2(50085200,'F');
    // if (myTable.Insert(d2)){
    //     std::cout << d2.getDni() << " insertado\n";
    // } else
    //     std::cout << d2.getDni() << "NO insertado\n";

    // dni d3;
    // if (myTable.Insert(d3)){
    //     std::cout << d3.getDni() << " insertado\n";
    // } else
    //     std::cout << d3.getDni() << "NO insertado\n";
    
    myTable.Print();

    // srand(time(NULL));
    // std::ifstream file("../input/dni.in");
    // system("pwd");
    // return 0;
    // std::ifstream file("input/dni.in");

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
    std::vector<dni> vector;
    vector.push_back(dni(42751043,'T'));
    vector.push_back(dni(76668648,'B'));
    vector.push_back(dni(19102864,'F'));
    vector.push_back(dni(64164486,'Y'));
    vector.push_back(dni(13248306,'F'));
    vector.push_back(dni(59539781,'A'));
    vector.push_back(dni(27838276,'L'));
    vector.push_back(dni(29596135,'B'));
    vector.push_back(dni(60871566,'L'));
    vector.push_back(dni(35704589,'X'));
    vector.push_back(dni(59539781,'A'));
    for (size_t i = 0; i < vector.size(); i++) {
        std::cout << "Dni: " << vector[i].getDni() << "\n";
        if (myTable.Insert(vector[i]))
        std::cout << vector[i].getDni() << " insertado\n";
        else
        std::cout << vector[i].getDni() << " NO insertado\n";
    
        myTable.Print();
    }
    std::cout << "Dni: " << vector[3].getDni() << "\n";
    if (myTable.Search(vector[3]))
    std::cout << vector[3].getDni() << " encontrado\n";
    else
    std::cout << vector[3].getDni() << " NO encontrado\n";

    myTable.Print();

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