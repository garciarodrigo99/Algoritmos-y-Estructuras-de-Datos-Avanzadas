#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

#include "splitChain.h"

#pragma once

template <class T> 
class Board;

template <class T> 
std::ostream& operator<< (std::ostream&, const Board<T>&);

template <class T>
class Board {
	private:
		std::map<std::string, T> number_;
		std::map<std::string, std::vector<std::string>> expression_;
		std::string fileName_;
	public:
		Board(std::string);
		~Board();
		friend std::ostream& operator<< <T>(std::ostream&, const Board<T>&);
};

template <class T>
Board<T>::Board(std::string fileName)
{
	std::ifstream archivo_entrada(fileName);
  std::string linea;

	getline(archivo_entrada, linea);

	//int i = 0;

	std::vector<std::string> splittedChain;
  while(getline(archivo_entrada, linea)) {
		splittedChain = SplitChain(linea);

		if (splittedChain.size() == 3){
			number_[splittedChain.at(0)] = T(splittedChain.at(2));
		} else {
			std::vector<std::string> expressionString(splittedChain.begin()+2,
				splittedChain.end());
			expression_[splittedChain.at(0)] = expressionString;
		}
  }
  archivo_entrada.close();
}

template <class T>
Board<T>::~Board()
{
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Board<T>& paramBoard) {

	os << "Numeros:\n";
	for(auto i : paramBoard.number_){
		os << '\t' << i.first << ": " << i.second << "\n";
	}

	os << "Expresiones:\n";
	for(auto i : paramBoard.expression_){
		os << "\t" << i.first << ": ";
		for (auto j : i.second) {
			os << j << " ";
		}
		os << '\n';
	}

	return os;
}