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

char convertToNumber(char);
char convertToCharacter(char toConvert);

template <>
class BigInt<2> {
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

    // Asignación:
		BigInt<2>& operator=(const BigInt<2>&);

		// Inserción y extracción en flujo:
		friend std::ostream& operator<< (std::ostream&, const BigInt<2>&);
		// friend std::istream& operator>> <Base>(std::istream&, BigInt<Base>&);
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
		//friend BigInt<2> pow(const BigInt<2>&, const BigInt<2>&);

		BigInt<2> factorial() const;

		std::string cvToStr(void);

		static unsigned totalInstances();
};

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
		operator BigInt<2> ();

		// Potencia a^b
		friend BigInt<Base> pow<Base>(const BigInt<Base>&, const BigInt<Base>&);

		BigInt<Base> factorial() const;

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
	// if (sign_ == -1) {
	// 	if (*this == BigInt<Base>(-1)){	// Problema 0 negativo
	// 		*this = BigInt<Base>("0");
	// 	} else {
	// 		BigInt<Base> copy(*this);
	// 		copy.sign_ = 1;
	// 		--copy;
	// 		*this = copy;
	// 		sign_ = -1;
	// 	}
	// } else {
	// 	int carry = 1;
	// 	for(size_t i=0; i<digits_.size();i++) {
	// 		int element = digits_[i] + carry;
	// 		carry = element / Base;
	// 		element = element % Base;
	// 		digits_[i] = element;
	// 	}
	// 	if (carry != 0) {
	// 		digits_.push_back('1');
	// 	}
	// }
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
	// if (sign_ == -1) {
	// 	BigInt<Base> copy(*this);
	// 	copy.sign_ = 1;
	// 	++copy;
	// 	*this = copy;
	// 	sign_ = -1;
	// } else if (*this == BigInt<Base>("0")){
	// 	*this = BigInt<Base>(-1);
	// } else {
	// 	bool carry = true;
	// 	for(size_t i=0; i<digits_.size();i++) {
	// 		char element = digits_[i] - carry;
	// 		carry = (element < 0);
	// 		digits_[i] = element;
	// 	}
	// 	if (carry != 0) {
	// 		digits_.push_back('1');
	// 	}
	// }
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

template <size_t Base>
BigInt<Base>::operator BigInt<2> () {

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
		checkCharFromBase(toConvert);
		digits_.push_back(toConvert);
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
		message.append(" no es un caracter valido");		
		throw std::domain_error(message);
	}

	int digit = pCharacter;

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

// ----------------------------------------------------------------------------

BigInt<2>::BigInt(long n)
{
	//std::cout << "Binario\n";
	std::string str(std::to_string(n));
	build(str);
}

/**
 * @brief Constructor de binario en complemento a 2
 * 
 * @param str 
 */
BigInt<2>::BigInt(std::string& str, bool condition)
{
	build(str);
	if (condition)
		*this = complementNumber();
}

BigInt<2>::BigInt(const char* cchar)
{
	std::string str = cchar;
	build(str);
}

// OK
BigInt<2>::BigInt(const BigInt<2>& copy)
{	
	*this = copy;
	removeUselessElements();
}

BigInt<2>::~BigInt() {}


inline BigInt<2> &BigInt<2>::operator=(const BigInt<2> & binary)
{
	c2_ = binary.c2_;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const BigInt<2>& binary) {

	for(int i=binary.c2_.size()-1; i>=0; i--){
		os << convertToCharacter(binary.c2_[i]);
	}
	return os;
}

bool BigInt<2>::sign() const
{
	return c2_.back();
}

char BigInt<2>::operator[](int index) const
{
  return c2_[index];
}

inline int BigInt<2>::size(void) const
{
  return c2_.size();
}

bool operator==(const BigInt<2>& first, const BigInt<2> & second) {
	if(first.sign() != second.sign()){
		return false;
	}
	
	if(first.c2_.size() != second.c2_.size()){
		return false;
	}
	for(int i=first.c2_.size()-2; i>=0; i--){
		if (first.c2_[i] != second.c2_[i]) {
			return false;
		}
	}
	return true;
}

bool BigInt<2>::operator!=(const BigInt<2>& param) const {
	return !(*this == param);
}

bool operator>(const BigInt<2>& first, const BigInt<2> & second) {
	if(first.sign() != second.sign()){
		return (!first.sign());
	}
	if(first.c2_.size() != second.c2_.size()){
		return (first.c2_.size() > second.c2_.size());
	}
	for(int i=first.c2_.size()-2; i>=0; --i){
		if (first.c2_[i] != second.c2_[i]) {
			return (first.c2_[i] > second.c2_[i]);
		}
	}
	return false;
}

bool BigInt<2>::operator>=(const BigInt<2> & param) const {
	return !(*this < param);
}

bool operator<(const BigInt<2>& first, const BigInt<2> & second) {
	if(first.sign() != second.sign()){
		return (first.sign());
	}
	if(first.c2_.size() != second.c2_.size()){
		return (first.c2_.size() < second.c2_.size());
	}
	for(int i=first.c2_.size()-2; i>=0; --i){
		if (first.c2_[i] != second.c2_[i]) {
			return (first.c2_[i] < second.c2_[i]);
		}
	}
	return false;
}

bool BigInt<2>::operator<=(const BigInt<2> & param) const {
	return !(*this > param);
}

BigInt<2>& BigInt<2>::operator++() {

	bool originalSign = sign();
	bool carry = true;
	for(size_t i=0; i<c2_.size();i++) {
		bool element = c2_[i] + carry;
		if ((c2_[i] == true) && (carry == true)){
			carry = true;
			element = false;
		}else
			carry = false;
		
		c2_[i] = element;
	}
	if ((sign() == true) && (originalSign == false)) {
		c2_.push_back(originalSign);
		c2_[c2_.size()-2] = true;
	}
	return *this;
}

BigInt<2> BigInt<2>::operator++(int) {
	BigInt<2> copy(*this);
	operator++();
	return copy;
}

BigInt<2>& BigInt<2>::operator--() {
	BigInt<2> result(complementNumber());
	++result;
	result = result.complementNumber();
	*this = result;
	return *this;
}// Pre-decremento

BigInt<2> BigInt<2>::operator--(int) {
	BigInt<2> copy(*this);
	operator--();
	return copy;
}

BigInt<2> operator+(const BigInt<2>& first, const BigInt<2>& second) {

	BigInt<2> firstCopy(first);
	BigInt<2> secondCopy(second);

	
	// Necesario operaciones números negativos
	if ((firstCopy.size() != secondCopy.size())){
		if (firstCopy.size() < secondCopy.size()) {
			firstCopy.fillDifference(secondCopy.size()-firstCopy.size());
		} else {
			secondCopy.fillDifference(firstCopy.size()-secondCopy.size());
		}
	}

	std::string boolString;

	bool addBit = (firstCopy.sign() ^ secondCopy.sign());
	bool carry = false;
	for(size_t i=0; i<firstCopy.c2_.size(); i++) {
		bool element = firstCopy.c2_[i] ^ carry;
		carry = (firstCopy.c2_[i] && carry);
		if (i < secondCopy.c2_.size()) {
			element = element ^ secondCopy.c2_[i];
			carry = carry || (firstCopy.c2_[i] && secondCopy.c2_[i]) ||
							(secondCopy.c2_[i] && carry);
		}
		boolString.push_back(element ? '1' : '0');
		
	}
	if (!addBit && boolString.back()) {
		boolString.push_back(firstCopy.sign() ? '1' : '0');
	}
	std::reverse(boolString.begin(), boolString.end());

	BigInt<2> toReturn(boolString);
	return toReturn;
}

BigInt<2> BigInt<2>::operator-(const BigInt<2> & param) const {

	BigInt<2> toSubstract(param);
	BigInt<2> toReturn(*this + toSubstract.complementNumber());
	return toReturn;
}

BigInt<2> BigInt<2>::operator*(const BigInt<2>& multiplier) const {
	BigInt<2> zero;
	if ((multiplier == zero) || (*this == zero))
		return zero;
	if (multiplier == BigInt<2>(1))
		return *this;
	
	if (*this == BigInt<2>(1))
		return multiplier;

	// Multiplicación negativos
	if(sign() || multiplier.sign()){
		BigInt<2> first(*this);
		if (first.sign())
			first = first.complementNumber();
		
		BigInt<2> second(multiplier);
		if (second.sign())
			second = second.complementNumber();

		BigInt<2> toReturn(first * second);
		if (sign() ^ multiplier.sign())
			return toReturn.complementNumber();
		
		return toReturn;
	}

	std::vector<BigInt<2>> vectorsum;
	for(std::size_t j=0;j<multiplier.c2_.size();j++){
		std::list<char> result2;
		for(std::size_t i=0;i<c2_.size();i++){
			bool result = c2_[i] && multiplier[j];
			result2.push_front(result);
		}
		for (size_t i = 0; i < j; i++){
			result2.push_back(0);
		}
		std::string strParam;
		for(auto i : result2)
			strParam.push_back(convertToCharacter(i));
		vectorsum.push_back(BigInt<2>(strParam));
	}
	BigInt<2> toReturn;
	for (std::size_t i=0; i<vectorsum.size();i++) {
		toReturn = toReturn + vectorsum[i];
	}
	
	return toReturn;
}

BigInt<2> pow(const BigInt<2>& base, const BigInt<2>& exponent) {
	
	if (exponent == BigInt<2>("0")) {
		return BigInt<2>(1);
	}
	if (exponent < BigInt<2>("0")){
		throw std::domain_error("Operacion no soportada");
	}

	BigInt<2> counter;
	BigInt<2> result(base);
	BigInt<2> operations(exponent);
	--operations;
	while (counter < operations) {
		result = result * base;
		//std::cout << "it: " << counter << ", result: " << result << std::endl;
		counter++;
	}
	//std::cout << "Ultimo: " << counter << " < " << operations << " " << (counter < operations) << std::endl;
	return result;
}

template <size_t BaseToConvert>
BigInt<2>::operator BigInt<BaseToConvert>()
{
	BigInt<BaseToConvert> result;
	BigInt<2> naturalBinary(*this);
	if (naturalBinary.sign())
		naturalBinary = complementNumber();
	
	for (size_t i = 0; i < naturalBinary.c2_.size()-1; i++) {
		result = (result + (BigInt<BaseToConvert>
							(pow(BigInt<BaseToConvert>(2),BigInt<BaseToConvert>(i)) 
							* BigInt<BaseToConvert>(naturalBinary.c2_[i]))));
		/*std::cout << "it: " << i << ", valor iteracion: " << (BigInt<BaseToConvert>
							(pow(BigInt<BaseToConvert>(2),BigInt<BaseToConvert>(i)) 
							* BigInt<BaseToConvert>(naturalBinary.c2_[i]))) << ", result: " << (BigInt<10>)result << std::endl;*/
	}
	if (sign())
		result = result * BigInt<BaseToConvert>(-1);
	
	return result;
}

/**
 * @brief Metodo privado que funciona como constructor común y evita repetir 
 * código
 * 
 * @param str Cadena de caracteres
 */
void BigInt<2>::build(std::string& str){

	for(int i=str.size()-1; i>=0; i--){
		checkBinary(str[i]);
		if (str[i] == '0'){
			c2_.push_back(false);
			continue;
		}
		c2_.push_back(true);
	}
	removeUselessElements();
}

/**
 * @brief Comprueba si un caracter es 1 ó 0
 * 
 * @param pCharacter Caracter a comprobar
 */
void BigInt<2>::checkBinary(char pCharacter) {

	bool isBinary = ((pCharacter == '0') || (pCharacter == '1'));

	if(!isBinary){
		std::string message;
		message.push_back(pCharacter);
		message.append(" no es 0 ó 1");
		throw std::domain_error(message);
	}
}

/**
 * @brief Realiza el complemento a 2 de un número pasado por referencia.
 * No altera el estado del parametro. Util sobretodo para la resta.
 * 
 * @param param Binario en complemento a 2
 * @return BigInt<2> Binario en complemento a 2 pasado por referencia cambiado
 * de signo
 */
BigInt<2> BigInt<2>::complementNumber() {
	if (*this == BigInt<2>("0")) {
		return *this;
	}
	
	BigInt<2> toReturn(*this);
	toReturn.c2_.flip();
	++toReturn;
	return toReturn;
}

/**
 * @brief Elimina elementos que no aportan información al número.
 * Útil sobretodo para hacer las comparaciones usando el tamaño del vector
 * Ej:	000000001 -> 01
 * 			111111111 -> 11
 * 
 */
void BigInt<2>::removeUselessElements() {

	if (!sign()) {
		while ((!*(c2_.end()-2)) && (c2_.size() > 2)) {
			c2_.erase(c2_.end()-2);
		}
	} else 
		while ((*(c2_.end()-2)) && (c2_.size() > 2)) {
			c2_.erase(c2_.end()-2);
		}
}

void BigInt<2>::fillDifference(int nElements) {
	if (!sign()) {
		for (auto i = 0; i < nElements; i++){
			c2_.insert(c2_.end()-1);
		}
	} else {
		for (auto i = 0; i < nElements; i++){
			c2_.insert(c2_.end()-1,sign());
		}
	}
}
