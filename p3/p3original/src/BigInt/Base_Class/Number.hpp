// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS
// Curso: 2º
// Práctica 3: Calculadora universal para números enteros grandes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 06/03/2023
// Archivo Big_Int.hpp: Definición e implementación de la clase 
// BigInt<std::size_t Base>
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 28/02/2023 - Creaci´on (primera versi´on) del c´odigo

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

template <std::size_t Base> class BigInt;

class Number {

	public:
		//Number(/* args */);
		virtual ~Number();

	// Operaciones aritmeticas
		virtual Number* add(const Number*) const = 0;
		virtual Number* subtract(const Number*) const = 0;
		virtual Number* multiply(const Number*) const = 0;
		virtual Number* divide(const Number*) const = 0;
		virtual Number* module(const Number*) const = 0;
		// virtual Number* pow(const Number*) const = 0;

	// Operaciones de cambio de tipo.
		virtual operator BigInt<2>() const = 0;
		virtual operator BigInt<8>() const = 0;
		virtual operator BigInt<10>() const = 0;
		virtual operator BigInt<16>() const = 0;

	static Number* create(size_t, std::string&);
	//virtual std::ostream& write(std::ostream&) const = 0;

	protected:
	virtual std::ostream& write(std::ostream&) const = 0;
	//virtual std::istream& read(std::istream&) = 0;
	friend std::ostream& operator<<(std::ostream&, const Number&);
	//friend std::istream& operator>>(std::istream&, Number&);

};

#include "../Derived_Class/Big_Int.hpp"

