// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS
// Curso: 2º
// Práctica 3: Calculadora universal para números enteros grandes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 06/03/2023
// Archivo Big_Int.hpp: Declaración y definición de la clase 
// BigInt<std::size_t Base> y declaración de la especialización BigInt<2>
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/4445654/multiple-definition-of-template-specialization-when-using-different-objects
// https://stackoverflow.com/questions/53660616/explicit-template-specialization-multiple-definitions
// https://stackoverflow.com/questions/43566006/c-error-multiple-definition-of-a-member-function-specialized-in-template-clas
// Historial de revisiones
// 28/02/2023 - Creación (primera versión) del código

#pragma once
#include "../Base_Class/Number.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>

#include "../../Exceptions/Base_Class/BigIntException.hpp"

//class Number;

template <std::size_t Base> class BigInt;

template <>
class BigInt<2> : public Number{
	private:
		std::vector<bool> c2_;
		void build(std::string&);
		void checkBinary(char);
		BigInt<2> complementNumber();
		void removeUselessElements();
    void fillDifference(int nElements);

	public:
		// Constructores
		BigInt(long n = 0);
		BigInt(std::string&, bool = false);
		BigInt(const char* );
		BigInt(const BigInt<2>&); // Constructor de copia
		~BigInt();

		// Pruebas metodos privados

		// Modif
		size_t sizeOf();

    // Asignación:
		BigInt<2>& operator=(const BigInt<2>&);

		// Inserción y extracción en flujo:
		friend std::ostream& operator<< (std::ostream&, const BigInt<2>&);
		friend std::istream& operator>> (std::istream&, BigInt<2>&);
		// friend BigInt<Base>& operator>>(BigInt<Base>&, char &x);

		// Accesor:
		bool sign() const; // Signo: 0 ó 1
		char operator[](int) const; // Acceso al i-ésimo dígito
		int size(void) const;

		// Comparación:
		friend bool operator==(const BigInt<2>&, const BigInt<2> &);
		bool operator!=(const BigInt<2>&) const;
		friend bool operator>(const BigInt<2>&, const BigInt<2> &);
		bool operator>=(const BigInt<2> &) const;
		friend bool operator< (const BigInt<2>&, const BigInt<2>&);
		bool operator<=(const BigInt<2>&) const;

		// Incremento/decremento:
		BigInt<2>& operator++(); // Pre-incremento(++i)
		BigInt<2> operator++(int); // Post-incremento
		BigInt<2>& operator--(); // Pre-decremento
		BigInt<2> operator--(int); // Post-decremento

		// Operadores aritméticos:
		friend BigInt<2> operator+(const BigInt<2>&, const BigInt<2>&);
		BigInt<2> operator-(const BigInt<2> &) const;
		BigInt<2> operator-() const;
		BigInt<2> operator*(const BigInt<2>&) const;
		friend BigInt<2> operator/(const BigInt<2>&, const BigInt<2>&);
		BigInt<2> operator%(const BigInt<2>&) const;

		// Operador de conversión
		template <size_t BaseToConvert> operator BigInt<BaseToConvert> ();						

		// Potencia a^b
		friend BigInt<2> pow(const BigInt<2>&, const BigInt<2>&);
		BigInt<2> factorial() const;

		// Operaciones aritmeticas heredadas
		Number* add(const Number*) const override;
		Number* subtract(const Number*) const override;
		Number* multiply(const Number*) const override;
		Number* divide(const Number*) const override;
		Number* module(const Number*) const override;
		Number* power(const Number*) const override;

		operator BigInt<2>() const override;
		operator BigInt<8>() const override;
		operator BigInt<10>() const override;
		operator BigInt<16>() const override;

		std::ostream& write(std::ostream&) const override;
		std::istream& read(std::istream&) override;

		std::string cvToStr(void);
		static unsigned totalInstances();
};

template <std::size_t Base> std::ostream& operator<< (std::ostream&, const BigInt<Base>&);

template <std::size_t Base> 
std::istream& operator>> (std::istream&, BigInt<Base>&);

template <std::size_t Base> bool operator==(const BigInt<Base>&, const BigInt<Base> &);

template <std::size_t Base> bool operator>(const BigInt<Base>&, const BigInt<Base> &);

template <std::size_t Base> bool operator<(const BigInt<Base>&, const BigInt<Base> &);

template <std::size_t Base> BigInt<Base> operator+(const BigInt<Base>&, const BigInt<Base>&);

template <std::size_t Base> BigInt<Base> operator/(const BigInt<Base>&, const BigInt<Base>&);

template <std::size_t Base> BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);

inline char convertToNumber(char);
inline char convertToCharacter(char toConvert);

template <std::size_t Base = 10> 
class BigInt : public Number{
	private:
		std::vector<char> digits_;
		int sign_ = 1;
		void build(std::string&);
		void checkCharFromBase(char);
		void print();
		static unsigned instanceCount;
		//std::string cvToStr(void);

	public:
		// Constructores
		BigInt(long n = 0);
		BigInt(std::string&);
		BigInt(const char* );
		BigInt(const BigInt<Base>&); // Constructor de copia
		~BigInt();

		// Asignación:
		BigInt<Base>& operator=(const BigInt<Base>&);

		// Inserción y extracción en flujo:
		friend std::ostream& operator<< <Base>(std::ostream&, const BigInt<Base>&);
		friend std::istream& operator>> <Base>(std::istream&, BigInt<Base>&);
		// friend BigInt<Base>& operator>>(BigInt<Base>&, char &x);

		// Accesor:
		int sign() const; // Signo: 1 o -1
		char operator[](int) const; // Acceso al i-ésimo dígito

		// Comparación:
		friend bool operator==<Base>(const BigInt<Base>&, const BigInt<Base> &);
		bool operator!=(const BigInt<Base>&) const;
		friend bool operator><Base>(const BigInt<Base>&, const BigInt<Base> &);
		bool operator>=(const BigInt<Base> &) const;
		friend bool operator< <Base>(const BigInt<Base>&, const BigInt<Base>&);
		bool operator<=(const BigInt<Base>&) const;

		// Incremento/decremento:
		BigInt<Base>& operator++(); // Pre-incremento(++i)
		BigInt<Base> operator++(int); // Post-incremento
		BigInt<Base>& operator--(); // Pre-decremento
		BigInt<Base> operator--(int); // Post-decremento

		// Operadores aritméticos:
		friend BigInt<Base> operator+ <Base>(const BigInt<Base>&, const BigInt<Base>&);
		BigInt<Base> operator-(const BigInt<Base> &) const;
		BigInt<Base> operator-() const;
		BigInt<Base> operator*(const BigInt<Base>&) const;
		friend BigInt<Base> operator/ <Base>(const BigInt<Base>&, const BigInt<Base>&);
		BigInt<Base> operator%(const BigInt<Base>&) const;
		operator BigInt<2> ();

		// Potencia a^b
		friend BigInt<Base> pow<Base>(const BigInt<Base>&, const BigInt<Base>&);
		BigInt<Base> factorial() const;

		// Operaciones aritmeticas heredadas
		Number* add(const Number*) const override;
		Number* subtract(const Number*) const override;
		Number* multiply(const Number*) const override;
		Number* divide(const Number*) const override;
		Number* module(const Number*) const override;
		Number* power(const Number*) const override;

		operator BigInt<2>() const override;
		operator BigInt<8>() const override;
		operator BigInt<10>() const override;
		operator BigInt<16>() const override;

		std::ostream& write(std::ostream&) const override;
		std::istream& read(std::istream&) override;

		std::string cvToStr(void);
		static unsigned totalInstances();
};

template <size_t Base> 
unsigned BigInt<Base>::instanceCount = 0;

static int toCharCounter = 0;
static int toNumCounter = 0;

template <size_t Base>
BigInt<Base>::BigInt(long n)
{
	std::string str(std::to_string(n));
	build(str);
}

template <size_t Base>
BigInt<Base>::BigInt(std::string& str)
{
	build(str);
}

template <size_t Base>
BigInt<Base>::BigInt(const char* cchar)
{
	std::string str = cchar;
	build(str);
}

// OK
template <size_t Base>
BigInt<Base>::BigInt(const BigInt<Base>& copy)
{	
	*this = copy;	
}

template <size_t Base>
BigInt<Base>::~BigInt()
{
	//--BigInt<Base>::instanceCount;
}

template <std::size_t Base>
inline BigInt<Base> &BigInt<Base>::operator=(const BigInt<Base> & bigIntParam)
{
	sign_ = bigIntParam.sign_;
	digits_ = bigIntParam.digits_;
	return *this;
}

template <size_t Base>
std::ostream& operator<<(std::ostream& os, const BigInt<Base>& bigInt) {

	if (bigInt.sign_ == -1)
		os << '-';
	for(int i=bigInt.digits_.size()-1; i>=0; i--){
		os << convertToCharacter(bigInt.digits_[i]);
	}
	return os;
}

template <size_t Base>
std::istream& operator>>(std::istream & is, BigInt<Base>& bigInt)
{
	std::string input;
	is >> input;
	bigInt = BigInt<Base>(input);
	return is;
}


template <std::size_t Base>
int BigInt<Base>::sign() const
{
	return sign_;
}

template <std::size_t Base>
char BigInt<Base>::operator[](int index) const
{
  return digits_[index];
}

// OK
template <std::size_t Base>
bool operator==(const BigInt<Base>& first, const BigInt<Base> & second) {
	if(first.sign_ != second.sign_){
		return false;
	}
	
	if(first.digits_.size() != second.digits_.size()){
		return false;
	}
	for(int i=first.digits_.size()-1; i>=0; i--){
		if (first.digits_[i] != second.digits_[i]) {
			return false;
		}
	}
	return true;
}

template <std::size_t Base>
bool BigInt<Base>::operator!=(const BigInt<Base>& param) const {
	return !(*this == param);
}

template <std::size_t Base>
bool operator>(const BigInt<Base>& first, const BigInt<Base> & second) {
	if(first.sign_ != second.sign_){
		return (first.sign_ > second.sign_);
	}
	if(first.digits_.size() != second.digits_.size()){
		return (first.digits_.size() > second.digits_.size());
	}
	for(int i=first.digits_.size()-1; i>=0; --i){
		if (first.digits_[i] != second.digits_[i]) {
			return (first.digits_[i] > second.digits_[i]);
		}
	}
	return false;
}

template <std::size_t Base>
bool BigInt<Base>::operator>=(const BigInt<Base> & param) const {
	return !(*this < param);
}

template <std::size_t Base>
bool operator<(const BigInt<Base>& first, const BigInt<Base> & second) {
	if(first.sign_ != second.sign_){
		return (first.sign_ < second.sign_);
	}
	if(first.digits_.size() != second.digits_.size()){
		return (first.digits_.size() < second.digits_.size());
	}
	for(int i=first.digits_.size()-1; i>=0; --i){
		if (first.digits_[i] != second.digits_[i]) {
			return (first.digits_[i] < second.digits_[i]);
		}
	}
	return false;
}

template <std::size_t Base>
bool BigInt<Base>::operator<=(const BigInt<Base> & param) const {
	return !(*this > param);
}

template <std::size_t Base>
BigInt<Base>& BigInt<Base>::operator++() {
	*this = *this + BigInt<Base>(1);
	return *this;
}

template <std::size_t Base>
BigInt<Base> BigInt<Base>::operator++(int) {
	BigInt<Base> copy(*this);
	//int carry = 1;
	if (sign_ == -1) {
		operator--();
	} else {
		operator++();
	}
	return copy;
}

// CUIDADO 0, -1
template <std::size_t Base>
BigInt<Base>& BigInt<Base>::operator--() {
	*this = *this - BigInt<Base>(1);
	return *this;
}// Pre-decremento

template <std::size_t Base>
BigInt<Base> BigInt<Base>::operator--(int) {
	BigInt<Base> copy(*this);
	if (sign_ == -1) {
		operator++();
	} else {
		operator--();
	}
	return copy;
} // Post-decremento

template <size_t Base>
BigInt<Base> operator+(const BigInt<Base>& first, const BigInt<Base>& second) {

	if (first < second)
		return BigInt<Base>(second+first);
	
	if ((first.sign_ == -1) ^ (second.sign_ == -1)){
		// (-) + (+)
		if (first.sign_ == -1){
			BigInt<Base> lower(first);
			lower.sign_ = 1;
			lower = lower - second;
			lower.sign_ = -1;
			return lower;
		}
		// (+) + (-)
		BigInt<Base> lower(second);
		lower.sign_ = 1;
		return BigInt<Base>(first - lower);
	}
	
	int carry = 0;
	int element = 0;
	std::list<char> list;

	for(size_t i=0; i<first.digits_.size(); i++){
		element = carry + first.digits_[i];
		if (i<second.digits_.size()){
			element = element + second.digits_[i];
		}
		carry = element / Base;
		list.push_front(element % Base);
	}

	if (carry != 0) 
		list.push_front(carry);
	std::string strParam;
	for(auto i : list)
		strParam.push_back(convertToCharacter(i));

	BigInt<Base> toReturn(strParam);
	if (first.sign_ == -1)	// (-) + (-)
		toReturn.sign_ = -1; 
	return toReturn;
}

template <std::size_t Base>
BigInt<Base> BigInt<Base>::operator-(const BigInt<Base> & param) const {

	if (param > *this){
		BigInt<Base> aux(param - *this);
		aux = aux * BigInt<Base>(-1);
		return aux;
	}

	if(param.sign_ == -1){
		BigInt<Base> aux(param);
		aux.sign_ = 1;
		return BigInt<Base>(aux + *this);
	}

	int carry = 0;
	int element = 0;
	std::list<char> list;
	for(size_t i=0; i<digits_.size(); i++){
		element = digits_[i] - carry;
		if (i<param.digits_.size()) // Tamaño comun
			element = element - param.digits_[i];
		if (element < 0){
			element = Base + element;
			carry = 1;
		} else{
			carry = 0;
		}
		list.push_front(element);
	}
	// Borrar 0
	for (size_t i = list.size()-1; i > 0; i--){
		if (list.front() == 0){
			list.pop_front();
		} else{
			break;
		}
	}
	
	// List<char> -> string
	std::string strParam;
	for(auto i : list)
		strParam.push_back(convertToCharacter(i));

	BigInt<Base> toReturn(strParam);
	return toReturn;
}

// (!!!) BigInt<Base> operator-() const;
template <std::size_t Base>
BigInt<Base> BigInt<Base>::operator-() const {
throw std::domain_error("??????????????");
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator*(const BigInt<Base>& multiplier) const {
	BigInt<Base> zero;
	if ((multiplier == zero) || (*this == zero))
		return zero;
	if (multiplier == BigInt<Base>(1))
		return *this;
	
	if (*this == BigInt<Base>(1))
		return multiplier;

	bool negative = ((sign_ == -1) ^ (multiplier.sign_ == -1));	// ^ xor
	std::vector<BigInt<Base>> vectorsum;
	for(std::size_t j=0;j<multiplier.digits_.size();j++){
		int carry = 0;
		std::list<char> result2;
		for(std::size_t i=0;i<digits_.size();i++){
			int result = digits_[i] * multiplier[j] + carry;
			carry = result / Base;
			result = result % Base;
			result2.push_front(result);
		}
		if(carry != 0){
			result2.push_front(carry);
		}
		for (size_t i = 0; i < j; i++){
			result2.push_back(0);
		}
		std::string strParam;
		for(auto i : result2)
			strParam.push_back(convertToCharacter(i));
		vectorsum.push_back(BigInt<Base>(strParam));
	}
	BigInt<Base> toReturn;
	for (std::size_t i=0; i<vectorsum.size();i++) {
		toReturn = toReturn + vectorsum[i];
	}
	if (negative) {
		toReturn.sign_ = -1;
	}
	
	return toReturn;
}

template <size_t Base>
BigInt<Base> operator/(const BigInt<Base>& first, const BigInt<Base>& second) {
	if (second == BigInt<Base>("0")){
		throw BigIntDivisionByZero("Divisor es 0");
	}
	if (first == BigInt<Base>("0")){
		return BigInt<Base>("0");
	}
	if (first < second){
		return BigInt<Base>("0");
	}
	BigInt<Base> base(Base-1);
	base = base + (BigInt<Base>(1));
	BigInt<Base> minuendo(first.digits_.back());		// Va a ser el resto
	BigInt<Base> sustraendo;	
	std::string cociente;
	bool firstElementSet = false;
	int firstElemPos = first.digits_.size() - 1;
	while (minuendo < second){
		minuendo = (minuendo * base);
		BigInt<Base> aux(first.digits_[firstElemPos-1]);	// Si no se crea el objeto la sobrecarga del operador recibe valor 0
		minuendo = aux + minuendo;
		--firstElemPos;
	}
	++firstElemPos;
	for (int i = firstElemPos; i > 0; i--) {
		if(firstElementSet) {
			minuendo = (minuendo * base);
			if (i != 0) {
				BigInt<Base> aux(first.digits_[i-1]);	// Si no se crea el objeto la sobrecarga del operador recibe valor 0
				minuendo = aux + minuendo;
			} else {
				BigInt<Base> lastAux(first.digits_[i]);	
				minuendo = minuendo + lastAux;
			}
		}
		int secondLoop = 0;
		BigInt<Base> indexCociente;
		BigInt<Base> tmp;	// Elemento i del while pero en base(Base)
		if (!firstElementSet){
			secondLoop = 1;
			tmp++;
			indexCociente++; // Minimo ya que sabemos first > second
			firstElementSet = true;
		}
		while (secondLoop < (int)Base){ // Cambiar primera vez
			if((tmp*second) <= minuendo){
				indexCociente = tmp;
			} else {
				break;
			}
			secondLoop++;
			tmp++;
		}
		sustraendo = second * indexCociente;
		cociente.push_back(convertToCharacter(indexCociente.digits_[0]));
		minuendo = minuendo - sustraendo;
	}
	return (BigInt<Base>(cociente));
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator%(const BigInt<Base>& param) const {
	return BigInt<Base>(*this - (param * (*this / param)));
}

// template <size_t Base>
// BigInt<Base>::operator BigInt<2> () const {

// 	std::list<bool> boolList;
// 	bool negativeNumber = (sign_ == -1);
// 	BigInt<Base> dividendo(*this);
// 	if (negativeNumber){
// 		dividendo = dividendo * BigInt<Base> (-1);
// 	}
	
// 	while (dividendo > BigInt<Base>("0")){
// 		if ((dividendo % BigInt<Base>(2)) == BigInt<Base>("0"))
// 			boolList.push_front(false);
// 		else 
// 			boolList.push_front(true);
		
// 		dividendo = dividendo / BigInt<Base>(2); 
// 	}
	
// 	boolList.push_front(false);
// 	std::string strParam;
// 	for(auto i : boolList)
// 		strParam.push_back(convertToCharacter(i));

// 	if (negativeNumber){
// 		BigInt<2> toReturn(strParam,true);
// 		return toReturn;
// 	}
	
// 	BigInt<2> toReturn(strParam);
// 	return toReturn;
// }

template <size_t Base>
BigInt<Base> pow(const BigInt<Base>& base, const BigInt<Base>& exponent) {
	
	if (exponent == BigInt<Base>("0")) {
		return BigInt<Base>(1);
	}
	if (exponent < BigInt<Base>("0")){
		throw BigIntOperationNotSupported("Operacion no soportada");
	}

	BigInt<Base> counter;
	BigInt<Base> result(base);
	BigInt<Base> operations(exponent);
	--operations;
	while (counter < operations) {
		result = result * base;
		//std::cout << "it: " << counter << ", result: " << result << std::endl;
		counter++;
	}
	//std::cout << "Ultimo: " << counter << " < " << operations << " " << (counter < operations) << std::endl;
	return result;
}

template <size_t Base>
BigInt<Base> BigInt<Base>::factorial() const  {
	if ((*this == BigInt<Base>("0")) || *this == BigInt<Base>(1)){
		return BigInt<Base>(1);
	}
	BigInt<Base> toReturn(*this);
	BigInt<Base> minus(toReturn - BigInt<Base>(1));
	toReturn = toReturn * minus.factorial();
	return toReturn;
}

template <std::size_t Base>
Number *BigInt<Base>::add(const Number * number) const
{
	//BigInt<Base> test = dynamic_cast<const Number*>(number)->operator BigInt<Base>();
	BigInt<Base> aux = number->operator BigInt<Base>();
	BigInt<Base> copy(*this);
	aux = copy + aux;
	// std::cout << aux << std::endl;
  return (new BigInt<Base>(aux));
}

template <std::size_t Base>
Number *BigInt<Base>::subtract(const Number * number) const
{
	//throw BigIntOperationNotSupported("Operacion no soportada");
	BigInt<Base> aux = number->operator BigInt<Base>();
	aux = *this - aux;
	// std::cout << aux << std::endl;
  return (new BigInt<Base>(aux));
}

template <std::size_t Base>
Number *BigInt<Base>::multiply(const Number * number) const
{
	//throw BigIntOperationNotSupported("Operacion no soportada");
	BigInt<Base> aux = number->operator BigInt<Base>();
	aux = *this * aux;
	// std::cout << aux << std::endl;
  return (new BigInt<Base>(aux));
}

template <std::size_t Base>
Number *BigInt<Base>::divide(const Number * number) const
{
	//throw BigIntOperationNotSupported("Operacion no soportada");
	BigInt<Base> aux = number->operator BigInt<Base>();
	aux = *this / aux;
	// std::cout << aux << std::endl;
  return (new BigInt<Base>(aux));
}

template <std::size_t Base>
Number *BigInt<Base>::module(const Number * number) const
{
	//throw BigIntOperationNotSupported("Operacion no soportada");
	BigInt<Base> aux = number->operator BigInt<Base>();
	aux = *this % aux;
	// std::cout << aux << std::endl;
  return (new BigInt<Base>(aux));
}

template <std::size_t Base>
Number *BigInt<Base>::power(const Number * number) const
{
	BigInt<Base> aux = number->operator BigInt<Base>();
	aux = pow(*this,aux);
  return (new BigInt<Base>(aux));
}

template <std::size_t Base>
BigInt<Base>::operator BigInt<8>() const
{
	if (Base == 8) {
		return *this;
	}
	BigInt<8> toReturn;
	BigInt<8> objectBase;
	size_t counter = 0;
	while (Base > counter){
		objectBase++;
		counter++;
	}
	BigInt<8> exponent;

	for (size_t i=0; i<=digits_.size()-1; i++) {
		int value = (digits_[i] < 8) ? (digits_[i] - 0) : (digits_[i] - 8 + 10);
		toReturn = toReturn + (BigInt<8>(value) * pow(objectBase,exponent));
		exponent++;
	}

	if (sign_ == -1) {
			toReturn = toReturn * BigInt<8>("-1");
	}

	return toReturn;
}

template <std::size_t Base>
BigInt<Base>::operator BigInt<10>() const
{	
	if (Base == 10) {
		return *this;
	}
	BigInt<10> toReturn;
	BigInt<10> objectBase;
	size_t counter = 0;
	while (Base > counter){
		objectBase++;
		counter++;
	}
	BigInt<10> exponent;

	for (size_t i=0; i<=digits_.size()-1; i++) {
		int value = (digits_[i] < 10) ? (digits_[i] - 0) : (digits_[i] - 10 + 10);
		toReturn = toReturn + (BigInt<10>(value) * pow(objectBase,exponent));
		exponent++;
	}

	if (sign_ == -1) {
			toReturn = toReturn * BigInt<10>("-1");
	}

	return toReturn;
}

template <std::size_t Base>
BigInt<Base>::operator BigInt<16>() const
{
	if (Base == 16) {
		return *this;
	}
	
	BigInt<16> toReturn;
	BigInt<16> objectBase;
	size_t counter = 0;
	while (Base > counter){
		objectBase++;
		counter++;
	}
	BigInt<16> exponent;

	for (size_t i=0; i<=digits_.size()-1; i++) {
		int value = (digits_[i] < 16) ? (digits_[i] - 0) : (digits_[i] - 16 + 10);
		if (value > 9){
			std::string auxStr;
			auxStr.push_back((value-10)+'A');
			toReturn = toReturn + (BigInt<16>(auxStr) * pow(objectBase,exponent));
		} else {
			toReturn = toReturn + (BigInt<16>(value) * pow(objectBase,exponent));
		}
		// std::cout << BigInt<16>(value) << " * " << pow(base,exponent) << " = " << (BigInt<16>(value) * pow(base,exponent)) << std::endl;
		// std::cout << toReturn << std::endl;
		exponent++;
	}

	if (sign_ == -1) {
			toReturn = toReturn * BigInt<16>("-1");
	}

	return toReturn;
}

template <std::size_t Base>
inline std::ostream &BigInt<Base>::write(std::ostream & os) const
{
	size_t aux = Base;
  os << aux << ", " << *this;
	return os;
}

template <std::size_t Base>
std::istream &BigInt<Base>::read(std::istream & is)
{
  is >> *this;
	return is;
}

template <std::size_t Base>
BigInt<Base>::operator BigInt<2>() const
{
	std::list<bool> boolList;
	bool negativeNumber = (sign_ == -1);
	BigInt<Base> dividendo(*this);
	if (negativeNumber){
		dividendo = dividendo * BigInt<Base> (-1);
	}
	
	while (dividendo > BigInt<Base>("0")){
		if ((dividendo % BigInt<Base>(2)) == BigInt<Base>("0"))
			boolList.push_front(false);
		else 
			boolList.push_front(true);
		
		dividendo = dividendo / BigInt<Base>(2); 
	}
	
	boolList.push_front(false);
	std::string strParam;
	for(auto i : boolList)
		strParam.push_back(convertToCharacter(i));

	if (negativeNumber){
		BigInt<2> toReturn(strParam,true);
		return toReturn;
	}
	
	BigInt<2> toReturn(strParam);
	return toReturn;
}

// template <std::size_t Base>
// Number *BigInt<Base>::pow(const Number *) const
// {
//   return nullptr;
// }

// Metodos privados

/**
 * @brief Método privado que hace de constructor de los constructores para 
 * long, string y const char*. Evita código duplicado en los constructores
 * previamente indicados.
 * 
 * @tparam Base 
 * @param str Cadena que representa el numero pasado por parametros.
 */
template <size_t Base>
void BigInt<Base>::build(std::string& str){

	if (str.front() == '-') {
		sign_ = -1;
		str.erase(0,1);
	}

	for(int i=str.size()-1; i>=0; i--){
		char toConvert = convertToNumber(str[i]);
		try {
			checkCharFromBase(toConvert);
			digits_.push_back(toConvert);
		}
		catch(const BigIntBadDigit& bd) {
			std::cerr << bd.what() << '\n';
			digits_.push_back(0);
		}
	}
	++BigInt<Base>::instanceCount;
}

/**
 * @brief Método privado que recibe un caracter.
 * Se comprueba su valor para que en caso de que no sea un valor aceptado
 * se lance una excepción y parar el programa. Se comprueba más tarde si 
 * el caracter pertenece a la base con el mismo motivo.
 * 
 * @tparam Base 
 * @param pCharacter 
 * @return int 
 */
template <size_t Base>
void BigInt<Base>::checkCharFromBase(char pCharacter) {

	bool isDec = ((pCharacter>=0) && (pCharacter<=9));
	bool isHex = ((pCharacter>=10) && (pCharacter<=16));

	if(!isDec && !isHex){		
		std::string message;
		message.push_back(pCharacter);
		message.append("Caracter no valido");		
		throw BigIntBadDigit("Caracter no valido");
	}

	int digit = pCharacter;

	if((digit / Base) > 0){
		std::string message;
		message.push_back(pCharacter);
		message.append(" no es un caracter valido para la base seleccionada");
		throw BigIntBadDigit("Caracter no valido para la base seleccionada");
	}

}

template <std::size_t Base>
inline void BigInt<Base>::print()
{
	for (auto i : digits_)
		std::cout << i << " | ";

	std::endl(std::cout);
}

template <std::size_t Base>
std::string BigInt<Base>::cvToStr(void)
{
  std::string str;
	for(int i=digits_.size()-1; i>=0; i--){
		str.push_back(digits_[i]);
	}
	return str;
}

template <std::size_t Base>
inline unsigned BigInt<Base>::totalInstances(){
  return BigInt<Base>::instanceCount;
}

// Funciones externas

// Para pasar de caracter a numero: 48 -> 0
char convertToNumber(char toConvert) {
	toNumCounter++;
	if ((toConvert>='0') && (toConvert<='9')) {
		return (toConvert - '0');
	}
	return (toConvert - 'A') + 10;
}

// Para pasar de numero a caracter: 0 -> 48
char convertToCharacter(char toConvert) {
	toCharCounter++;
	if (toConvert >= 0 && toConvert <= 9) {
		return (toConvert + '0');
	}
	return (toConvert - 10 + 'A');
}