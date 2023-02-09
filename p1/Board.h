#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>

#include "Big_Int.h"
#include "splitChain.h"

#pragma once

template <std::size_t Base> 
class Board;

template <std::size_t Base> 
std::ostream& operator<< (std::ostream&, const Board<Base>&);

template <std::size_t Base>
class Board {
	private:
		std::map<std::string, BigInt<Base>> number_;
		std::map<std::string, std::vector<std::string>> expression_;
		std::string fileName_;
	public:
		Board(std::string);
		~Board();
		friend std::ostream& operator<< <Base>(std::ostream&, const Board<Base>&);
};

template <std::size_t Base>
Board<Base>::Board(std::string fileName)
{
	std::ifstream archivo_entrada(fileName);
  std::string linea;

	getline(archivo_entrada, linea);

	//int i = 0;

	std::vector<std::string> splittedChain;
  while(getline(archivo_entrada, linea)) {
		splittedChain = SplitChain(linea);

		if (splittedChain.size() == 3){
			number_[splittedChain.at(0)] = BigInt<Base>(splittedChain.at(2));
		} else {
			std::vector<std::string> expressionString(splittedChain.begin()+2,
				splittedChain.end());
			expression_[splittedChain.at(0)] = expressionString;
		}
  }
  archivo_entrada.close();
}

template <std::size_t Base>
Board<Base>::~Board()
{
}

template <size_t Base>
std::ostream& operator<<(std::ostream& os, const Board<Base>& paramBoard) {

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