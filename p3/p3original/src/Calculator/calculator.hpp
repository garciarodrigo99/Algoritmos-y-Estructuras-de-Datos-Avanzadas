// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS
// Curso: 2º
// Práctica 3: Calculadora universal para números enteros grandes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 06/03/2023
// Archivo calculator.hpp: Definición e implementación de la clase 
// Calculator<class T>
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 28/02/2023 - Creación (primera versión) del código

#pragma once
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include "../../lib/auxFunctions.hpp"

enum Operators {
  plus = '+',
  minus = '-',
  multiply = '*',
  split = '/',
  power = '^',
  modulo = '%',
  factorial = '!',
};
 
class Calculator {

public:
  // Constructores y destructor
  Calculator();
  Calculator(std::map<std::string, Number*>);
  ~Calculator();

  static unsigned totalInstances();

  // Getter
  Number* GetResult(std::string,std::map<std::string, Number*>);
  void insertNum(std::string, Number*);

private:
  bool isNumber(std::string);
  void Operations(char, int = 1);

private:
  std::stack<Number*> stack_;
  std::map<std::string, Number*> numbers_;
  static unsigned instanceCount;
};
 
unsigned Calculator::instanceCount = 0;

// // Funcion para separar cada linea en cadenas según espacios
// std::vector<std::string> SplitChain(std::string str, char pattern);

Calculator::Calculator() {
  ++Calculator::instanceCount;
}

Calculator::Calculator(std::map<std::string, Number*> mapNum) : 
numbers_(mapNum){}

Calculator::~Calculator(){
  --Calculator::instanceCount;
}

inline unsigned Calculator::totalInstances(){
  return Calculator::instanceCount;
}


// Metodo que dada una sentencia (conjunto de operaciones) y delimitador
// (para separar la secuencia), devuelve el lenguaje resultante de todas las
// operaciones previas
Number* Calculator::GetResult(std::string line,
  std::map<std::string, Number*> numeros) {
  std::vector<std::string> sequence(SplitChain(line));
  numbers_ = numeros;

  if (numbers_.size() == 0)
    throw std::out_of_range("La pila no dispone de números almacenados");

  int power = 1;
  for (size_t i = 2; i < sequence.size(); i++) {
    // Lenguaje declarado
    if (isNumber(sequence.at(i))) {
      stack_.push(numbers_[sequence.at(i)]);
    // } else if (std::all_of(sequence.at(i).begin(),
    //                        sequence.at(i).end(), ::isdigit)) {
    //   // Exponente opercion potencia
    //   power = std::stoi(sequence.at(i));
    } else {
      // Signo operación o fallo
      Operations(sequence.at(i).at(0), power);
    }
  }
  assert(stack_.size() == 1);

  Number* toRetun(stack_.top());
  stack_.pop();
  return toRetun;
}

// Metodo para saber si existe un lenguaje con un identificador de lenguaje
// recibido por parametro (modularidad)
bool Calculator::isNumber(std::string paramName) {
  auto it = numbers_.find(paramName);
  if (it != numbers_.end()) {
    return true;
  } 
  return false;
}

// Metodo que ejecuta las operaciones soportadas por la calculadora, que recibe
// el supuesto operador, y un entero, para usar en el caso de la potencia, y
// si no se indica el parametro, se pasará uno por defecto (modularidad)
void Calculator::Operations(char _operator, int power) {
  // Pila no vacia
  assert(!(stack_.empty()));
  Number* secondNumber(stack_.top());
  stack_.pop();

  if (_operator == Operators::factorial) {
    //stack_.push(secondNumber.factorial());
  } else {
    assert(!(stack_.empty()));
    Number* firstNumber(stack_.top());
    stack_.pop();
    switch (_operator) {
      case Operators::plus:
        //stack_.push(firstNumber + secondNumber);
        stack_.push(firstNumber->add(secondNumber));
        break;
      case Operators::minus:
        stack_.push(firstNumber->subtract(secondNumber));
        //stack_.push(firstNumber - secondNumber);
        break;
      case Operators::multiply:
        stack_.push(firstNumber->multiply(secondNumber));
        //stack_.push(firstNumber * secondNumber);
        break;
      case Operators::split:
        stack_.push(firstNumber->divide(secondNumber));
        //stack_.push(firstNumber / secondNumber);
        break;
      case Operators::power:
        stack_.push(firstNumber->power(secondNumber));
        break;
      case Operators::modulo:
        stack_.push(firstNumber->module(secondNumber));
        //stack_.push(firstNumber % secondNumber);
        break;
      default:
        throw std::invalid_argument("Simbolo no soportado");
        break;
    }
  }
}

void Calculator::insertNum(std::string tag, Number* value) {
  numbers_[tag] = value;
}