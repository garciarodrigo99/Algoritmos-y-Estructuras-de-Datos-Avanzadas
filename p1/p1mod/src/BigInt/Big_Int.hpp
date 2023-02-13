// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS
// Curso: 2º
// Práctica 1: Representación de números grandes en notación posicional
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 13/02/2023
// Archivo Big_Int.hpp: Definición e implementación de la clase 
// BigInt<std::size_t Base>
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl
// Historial de revisiones
// 13/10/2022 - Creaci´on (primera versi´on) del c´odigo

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>

#pragma once

template <std::size_t Base> class BigInt;

template <std::size_t Base> std::ostream& operator<< (std::ostream&, const BigInt<Base>&);

// template <std::size_t Base> 
// std::ostream& operator>> (std::ostream&, const BigInt<Base>&);

template <std::size_t Base> bool operator==(const BigInt<Base>&, const BigInt<Base> &);

template <std::size_t Base> bool operator>(const BigInt<Base>&, const BigInt<Base> &);

template <std::size_t Base> bool operator<(const BigInt<Base>&, const BigInt<Base> &);

template <std::size_t Base> BigInt<Base> operator+(const BigInt<Base>&, const BigInt<Base>&);

template <std::size_t Base> BigInt<Base> operator/(const BigInt<Base>&, const BigInt<Base>&);

template <std::size_t Base> BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);

int convertToNumber(char);
char convertToCharacter(int toConvert);

template <std::size_t Base = 10> 
class BigInt {
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
		// friend std::istream& operator>> <Base>(std::istream&, BigInt<Base>&);
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

		// Potencia a^b
		friend BigInt<Base> pow<Base>(const BigInt<Base>&, const BigInt<Base>&);

		BigInt<Base> factorial() const;

		std::string cvToStr(void);

		static unsigned totalInstances();
};

template <size_t Base> 
unsigned BigInt<Base>::instanceCount = 0;

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

// OK
template <std::size_t Base>
inline BigInt<Base> &BigInt<Base>::operator=(const BigInt<Base> & bigIntParam)
{
	sign_ = bigIntParam.sign_;
	digits_ = bigIntParam.digits_;
	// digits_.clear();
	// for (auto i : bigIntParam.digits_)
	// 	digits_.push_back(i);
	return *this;
}

template <size_t Base>
std::ostream& operator<<(std::ostream& os, const BigInt<Base>& bigInt) {

	if (bigInt.sign_ == -1)
		os << '-';
	for(int i=bigInt.digits_.size()-1; i>=0; i--){
		os << bigInt.digits_[i];
	}
	return os;
}

// //Falta implementacion
// template <size_t Base>
// std::istream& operator>>(std::istream& is, BigInt<Base>& bigInt) {

// }

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
	if (sign_ == -1) {
		if (*this == BigInt<Base>(-1)){	// Problema 0 negativo
			*this = BigInt<Base>("0");
		} else {
			BigInt<Base> copy(*this);
			copy.sign_ = 1;
			--copy;
			*this = copy;
			sign_ = -1;
		}
	} else {
		int carry = 1;
		for(size_t i=0; i<digits_.size();i++) {
			int element = convertToNumber(digits_[i]) + carry;
			carry = element / Base;
			element = element % Base;
			digits_[i] = convertToCharacter(element);
		}
		if (carry != 0) {
			digits_.push_back('1');
		}
	}
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
	if (sign_ == -1) {
		BigInt<Base> copy(*this);
		copy.sign_ = 1;
		++copy;
		*this = copy;
		sign_ = -1;
	} else if (*this == BigInt<Base>("0")){
		*this = BigInt<Base>(-1);
	} else {
		bool carry = true;
		for(size_t i=0; i<digits_.size();i++) {
			int element = convertToNumber(digits_[i]) - carry;
			carry = (element < 0);
			digits_[i] = convertToCharacter(element);
		}
		if (carry != 0) {
			digits_.push_back('1');
		}
	}
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
		element = carry + convertToNumber(first.digits_[i]);
		if (i<second.digits_.size()){
			element = element + convertToNumber(second.digits_[i]);
		}
		carry = element / Base;
		list.push_front(convertToCharacter(element % Base));
	}

	if (carry != 0) 
		list.push_front(convertToCharacter(carry));
	std::string strParam;
	for(auto i : list)
		strParam.push_back(i);

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
		element = convertToNumber(digits_[i]) - carry;
		if (i<param.digits_.size()) // Tamaño comun
			element = element - convertToNumber(param.digits_[i]);
		if (element < 0){
			element = Base + element;
			carry = 1;
		} else{
			carry = 0;
		}
		list.push_front(convertToCharacter(element));
	}
	// Borrar 0
	for (size_t i = list.size()-1; i > 0; i++){
		if (convertToNumber(list.front()) == 0){
			list.pop_front();
		} else{
			break;
		}
	}
	
	// List<char> -> string
	std::string strParam;
	for(auto i : list)
		strParam.push_back(i);

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

	// BigInt<Base> iterator;	// Zero by default
	// BigInt<Base> copy(*this);
	// BigInt<Base> result;
	// while (iterator < (multiplier)) {
	// 	result = result + copy;
	// 	iterator++;
	// }
	// return result;
	bool negative = ((sign_ == -1) ^ (multiplier.sign_ == -1));	// ^ xor
	std::vector<BigInt<Base>> vectorsum;
	for(std::size_t j=0;j<multiplier.digits_.size();j++){
		int carry = 0;
		std::list<char> result2;
		for(std::size_t i=0;i<digits_.size();i++){
			int result = (convertToNumber(digits_[i]) * 
				convertToNumber(multiplier[j])) + carry;
			carry = result / Base;
			result = result % Base;
			result2.push_front(convertToCharacter(result));
		}
		if(carry != 0){
			result2.push_front(convertToCharacter(carry));
		}
		for (size_t i = 0; i < j; i++){
			result2.push_back('0');
		}
		std::string strParam;
		for(auto i : result2)
			strParam.push_back(i);
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
		throw std::domain_error("Divisor es 0");
	}
	if (first == BigInt<Base>("0")){
		return BigInt<Base>("0");
	}
	if (first < second){
		return BigInt<Base>("0");
	}
	BigInt<Base> base(Base-1);
	base = base + (BigInt<Base>(1));
	BigInt<Base> minuendo(convertToNumber(first.digits_.back()));		// Va a ser el resto
	BigInt<Base> sustraendo;	
	std::string cociente;
	bool firstElementSet = false;
	int firstElemPos = first.digits_.size() - 1;
	while (minuendo < second){
		minuendo = (minuendo * base);
		BigInt<Base> aux(convertToNumber(first.digits_[firstElemPos-1]));	// Si no se crea el objeto la sobrecarga del operador recibe valor 0
		minuendo = aux + minuendo;
		--firstElemPos;
	}
	++firstElemPos;
	for (int i = firstElemPos; i > 0; i--) {
		if(firstElementSet) {
			minuendo = (minuendo * base);
			if (i != 0) {
				BigInt<Base> aux(convertToNumber(first.digits_[i-1]));	// Si no se crea el objeto la sobrecarga del operador recibe valor 0
				minuendo = aux + minuendo;
			} else {
				BigInt<Base> lastAux(convertToNumber(first.digits_[i]));	
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
		cociente.push_back(indexCociente.digits_[0]);
		minuendo = minuendo - sustraendo;
	}
	return (BigInt<Base>(cociente));
}

template <size_t Base>
BigInt<Base> BigInt<Base>::operator%(const BigInt<Base>& param) const {
	return BigInt<Base>(*this - (param * (*this / param)));
}

template <size_t Base>
BigInt<Base> pow(const BigInt<Base>& base, const BigInt<Base>& exponent) {
	
	if (exponent == BigInt<Base>("0")) {
		return BigInt<Base>(1);
	}
	if (exponent < BigInt<Base>("0")){
		throw std::domain_error("Operacion no soportada");
	}

	BigInt<Base> counter;
	BigInt<Base> result(base);
	BigInt<Base> operations(exponent);
	--operations;
	while (counter < (operations)) {
		result = result * base;
		counter++;
	}
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
		checkCharFromBase(str[i]);
		digits_.push_back(str[i]);
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

	bool isDec = ((pCharacter>='0') && (pCharacter<='9'));
	bool isHex = ((pCharacter>='A') && (pCharacter<='F'));

	if(!isDec && !isHex){		
		std::string message;
		message.push_back(pCharacter);
		message.append(" no es un caracter valido");		
		throw std::domain_error(message);
	}

	int digit = convertToNumber(pCharacter);

	if((digit / Base) > 0){
		std::string message;
		message.push_back(pCharacter);
		message.append(" no es un caracter valido para la base seleccionada");
		throw std::domain_error(message);
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
std::string BigInt<Base>::cvToStr(void) {
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

// Función externa
int convertToNumber(char toConvert) {
	if ((toConvert>='0') && (toConvert<='9')) {
		return (int)(toConvert - '0');
	}
	return (int)(toConvert - 'A') + 10;
}

char convertToCharacter(int toConvert) {
	toConvert = std::abs(toConvert);
	if (toConvert >= 0 && toConvert <= 9) {
		return (char)(toConvert + '0');
	}
	return (char)(toConvert - 10 + 'A');
}
