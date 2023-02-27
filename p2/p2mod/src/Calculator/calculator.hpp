// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS
// Curso: 2º
// Práctica 1: Representación de números grandes en notación posicional
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 13/02/2023
// Archivo calculator.hpp: Definición e implementación de la clase 
// Calculator<class T>
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include <stack>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include "../../lib/splitChain.hpp"

enum Operators {
  plus = '+',
  minus = '-',
  multiply = '*',
  split = '/',
  power = '^',
  modulo = '%',
  factorial = '!',
};

template <class T> 
class Calculator {

public:
  // Constructores y destructor
  Calculator();
  Calculator(std::map<std::string, T>);
  ~Calculator();

  static unsigned totalInstances();

  // Getter
  template<class M>
  T GetResult(std::string,std::map<std::string, M>);
  void insertNum(std::string, T);

private:
  bool isNumber(std::string);
  void Operations(char, int = 1);

private:
  std::stack<T> stack_;
  std::map<std::string, T> numbers_;
  static unsigned instanceCount;
};

template <class T> 
unsigned Calculator<T>::instanceCount = 0;

// // Funcion para separar cada linea en cadenas según espacios
// std::vector<std::string> SplitChain(std::string str, char pattern);

template <class T>
Calculator<T>::Calculator() {
  ++Calculator<T>::instanceCount;
}

template <class T>
Calculator<T>::Calculator(std::map<std::string, T> mapNum) : 
numbers_(mapNum){}

template <class T>
Calculator<T>::~Calculator(){
  --Calculator<T>::instanceCount;
}

template <class T>
inline unsigned Calculator<T>::totalInstances(){
  return Calculator<T>::instanceCount;
}


// Metodo que dada una sentencia (conjunto de operaciones) y delimitador
// (para separar la secuencia), devuelve el lenguaje resultante de todas las
// operaciones previas
template <class T>
template <class M>
T Calculator<T>::GetResult(std::string line,
  std::map<std::string, M> numeros) {
  std::vector<std::string> sequence(SplitChain(line));
  //numbers_ = numeros;
//-----------------------------------------------------------------------------
  numbers_.clear();
  for (auto it = numeros.begin(); it != numeros.end(); ++it) {
    BigInt<2> aux(it->second);
    numbers_[it->first] = it->second;
  }
//-----------------------------------------------------------------------------

  if (numbers_.size() == 0)
    throw std::domain_error("La pila no dispone de números almacenados");

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

  T toRetun(stack_.top());
  stack_.pop();
  return toRetun;
}

// Metodo para saber si existe un lenguaje con un identificador de lenguaje
// recibido por parametro (modularidad)
template <class T>
bool Calculator<T>::isNumber(std::string paramName) {
  auto it = numbers_.find(paramName);
  if (it != numbers_.end()) {
    return true;
  } 
  return false;
}

// Metodo que ejecuta las operaciones soportadas por la calculadora, que recibe
// el supuesto operador, y un entero, para usar en el caso de la potencia, y
// si no se indica el parametro, se pasará uno por defecto (modularidad)
template <class T>
void Calculator<T>::Operations(char _operator, int power) {
  // Pila no vacia
  assert(!(stack_.empty()));
  T secondNumber(stack_.top());
  stack_.pop();

  if (_operator == Operators::factorial) {
    //stack_.push(secondNumber.factorial());
  } else {
    assert(!(stack_.empty()));
    T firstNumber(stack_.top());
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
        //stack_.push(firstNumber / secondNumber);
        break;
      case Operators::power:
        stack_.push(pow(firstNumber,secondNumber));
        break;
      case Operators::modulo:
        //stack_.push(firstNumber % secondNumber);
        break;
      default:
        throw std::domain_error("Simbolo no soportado");
        break;
    }
  }
}

template <class T>
void Calculator<T>::insertNum(std::string tag, T value) {
  numbers_[tag] = value;
}