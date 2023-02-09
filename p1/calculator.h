// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 18/10/2022
// Archivo calculator.h: Cabecera de la clase Calculator.
// Se define la clase Calculator con sus métodos y atributos
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include <stack>
#include <string>
#include <vector>
#include <map>
#include "Big_Int.h"
#include "splitChain.h"

enum Operators {
  plus = '+',
  minus = '-',
  multiply = '*',
  split = '/',
  power = '^',
};

template <std::size_t Base> 
class Calculator {

public:
  // Constructores y destructor
  Calculator();
  Calculator(std::map<std::string, BigInt<Base>>);
  ~Calculator();

  // Getter
  BigInt<Base> GetResult(std::vector<std::string>);

private:
  bool isNumber(std::string);
  void Operations(char, int);

private:
  std::stack<BigInt<Base>> stack_;
  std::map<std::string, BigInt<Base>> numbers_;
};

// // Funcion para separar cada linea en cadenas según espacios
// std::vector<std::string> SplitChain(std::string str, char pattern);

template <std::size_t Base>
Calculator<Base>::Calculator() {}

template <std::size_t Base>
Calculator<Base>::Calculator(std::map<std::string, BigInt<Base>> mapNum) : 
numbers_(mapNum){}

template <std::size_t Base>
Calculator<Base>::~Calculator(){}

// Metodo que dada una sentencia (conjunto de operaciones) y delimitador
// (para separar la secuencia), devuelve el lenguaje resultante de todas las
// operaciones previas
template <std::size_t Base>
BigInt<Base> Calculator<Base>::GetResult(std::vector<std::string> operations) {

  if (numbers_.size() == 0)
    throw std::domain_error("La pila no dispone de números almacenados");

  int power = 1;
  for (size_t i = 0; i < operations.size(); i++) {
    // Lenguaje declarado
    if (isNumber(operations.at(i))) {
      stack_.push(numbers_[operations.at(i)]);
    } else if (std::all_of(operations.at(i).begin(),
                           operations.at(i).end(), ::isdigit)) {
      // Exponente opercion potencia
      power = std::stoi(operations.at(i));
    } else {
      // Signo operación o fallo
      Operations(operations.at(i).at(0), power);
    }
  }
  assert(stack_.size() == 1);

  Language lang_aux(stack_.top(), "L_result");
  return lang_aux;
}

// Metodo para saber si existe un lenguaje con un identificador de lenguaje
// recibido por parametro (modularidad)
template <std::size_t Base>
bool Calculator<Base>::isNumber(std::string paramName) {
  auto it = numbers_.find(paramName);
  if (it != my_map.end()) {
    return true;
  } 
  return false;
}

// Metodo que ejecuta las operaciones soportadas por la calculadora, que recibe
// el supuesto operador, y un entero, para usar en el caso de la potencia, y
// si no se indica el parametro, se pasará uno por defecto (modularidad)
template <std::size_t Base>
void Calculator<Base>::Operations(char _operator, int power = 1) {
  // Pila no vacia
  assert(!(stack_.empty()));
  BigInt<Base> secondNumber(stack_.top());
  stack_.pop();

  if (_operator == Operators::power) {
    stack_.push(l2.Power(power));
  } else {
    assert(!(stack_.empty()));
    BigInt<Base> firstNumber(stack_.top());
    stack_.pop();
    switch (_operator) {
      case Operators::plus:
        stack_.push(firstNumber + secondNumber);
        break;
      case Operators::minus:
        stack_.push(firstNumber - secondNumber);
        break;
      case Operators::multiply:
        stack_.push(firstNumber * secondNumber);
        break;
      case Operators::split:
        stack_.push(firstNumber / secondNumber);
        break;
      default:
        throw std::domain_error("Simbolo no soportado");
        break;
    }
  }
}