// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS
// Curso: 2º
// Práctica 3: Calculadora universal para números enteros grandes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 06/03/2023
// Archivo Big_Int.hpp: Definición de la clase abstracta Number
// Referencias:
// Enlaces de interéss
// Historial de revisiones
// 28/02/2023 - Creación (primera versión) del código

#include "Number.hpp"
#include "../Derived_Class/Big_Int.hpp"

Number::~Number() {}

Number *Number::create(size_t base, std::string &s)
{
	Number* toReturn = nullptr;
	if (base == 2) {
		toReturn = new BigInt<2>(s);
	} else if (base == 8) {
		toReturn = new BigInt<8>(s);
	} else if (base == 10) {
		toReturn = new BigInt<10>(s);
	} else if (base == 16) {
		toReturn = new BigInt<16>(s);
	} else {
		throw BigIntBaseNotImplemented("Base no válida");
	}

  return toReturn;
}

std::ostream &operator<<(std::ostream &os, const Number &number)
{
  number.write(os);
	return os;
}

std::istream &operator>>(std::istream & is, Number & number)
{
  number.read(is);
	return is;
}
