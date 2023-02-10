#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <algorithm>

#pragma once

template <std::size_t Base> 
class BigInt;

template <std::size_t Base> 
std::ostream& operator<< (std::ostream&, const BigInt<Base>&);

// template <std::size_t Base> 
// std::ostream& operator>> (std::ostream&, const BigInt<Base>&);

template <std::size_t Base> 
bool operator==(const BigInt<Base>&, const BigInt<Base> &);

template <std::size_t Base> 
bool operator>(const BigInt<Base>&, const BigInt<Base> &);

template <std::size_t Base> 
bool operator<(const BigInt<Base>&, const BigInt<Base> &);

template <std::size_t Base>
BigInt<Base> operator+(const BigInt<Base>&, const BigInt<Base>&);

int convertToNumber(char);
char convertToCharacter(int toConvert);

template <std::size_t Base> 
class BigInt {
	private:
		std::vector<char> vector_;
		void build(std::string&);
		void checkCharFromBase(char);
		void print();

	public:
		// Constructores
		BigInt(long n = 0);
		BigInt(std::string&);
		BigInt(const char* );
		BigInt(const BigInt<Base>&); // Constructor de copia
		~BigInt();
		//void print();

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
		friend BigInt<Base> operator/(const BigInt<Base>&, const BigInt<Base>&);
		BigInt<Base> operator%(const BigInt<Base>&) const;

		// Potencia a^b
		friend BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);

		void insert(char);
};

template <size_t Base>
BigInt<Base>::BigInt(long n)
{
	std::string str = std::to_string(n);
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
}

// OK
template <std::size_t Base>
inline BigInt<Base> &BigInt<Base>::operator=(const BigInt<Base> & bigIntParam)
{
	vector_.clear();
	for (auto i : bigIntParam.vector_)
		vector_.push_back(i);
	return *this;
}

template <size_t Base>
std::ostream& operator<<(std::ostream& os, const BigInt<Base>& bigInt) {

	for(int i=bigInt.vector_.size()-1; i>=0; i--){
		os << bigInt.vector_[i];
	}
	return os;
}

// template <size_t Base>
// void BigInt<Base>::insert(char toInsert) {
// 	if (vector_ == 1) {

// 	}
// 	vector_.push_back();
// }

// //Falta implementacion
// template <size_t Base>
// std::istream& operator>>(std::istream& is, BigInt<Base>& bigInt) {

// 	std::string str;
// 	is >> str;
// 	for(int i=bigInt.vector_.size()-1; i>=0; i--){
// 		bigInt.vector_.push_back();
// 	}
// 	return is;
// }

// (!!!) int sign() const; // Signo: 1 o -1

template <std::size_t Base>
char BigInt<Base>::operator[](int index) const
{
  return vector_[index];
}

// OK
template <std::size_t Base>
bool operator==(const BigInt<Base>& first, const BigInt<Base> & second) {
	if(first.vector_.size() != second.vector_.size()){
		return false;
	}
	for(int i=first.vector_.size()-1; i>=0; i++){
		if (first.vector_[i] != second.vector_[i]) {
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
	if(first.vector_.size() != second.vector_.size()){
		return (first.vector_.size() > second.vector_.size());
	}
	for(int i=first.vector_.size()-1; i>=0; --i){
		if (first.vector_[i] != second.vector_[i]) {
			return (first.vector_[i] > second.vector_[i]);
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
	if(first.vector_.size() != second.vector_.size()){
		return (first.vector_.size() < second.vector_.size());
	}
	for(int i=first.vector_.size()-1; i>=0; --i){
		if (first.vector_[i] != second.vector_[i]) {
			return (first.vector_[i] < second.vector_[i]);
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
	int carry = 1;
	for(int i=0; i<vector_.size();i++) {
		int element = convertToNumber(vector_[i]) + carry;
		carry = element / Base;
		element = element % Base;
		vector_[i] = convertToCharacter(element);
	}
	if (carry != 0) {
		vector_.push_back('1');
	}
	return *this;
}

template <std::size_t Base>
BigInt<Base> BigInt<Base>::operator++(int) {
	BigInt<Base> copy(*this);
	int carry = 1;
	operator++();
	return copy;
}

template <std::size_t Base>
BigInt<Base>& BigInt<Base>::operator--() {
	bool carry = true;
	for(int i=0; i<vector_.size();i++) {
		int element = convertToNumber(vector_[i]) - carry;
		carry = (element < 0);
		vector_[i] = convertToCharacter(element);
	}
	if (carry != 0) {
		vector_.push_back('1');
	}
	return *this;
}// Pre-decremento

template <std::size_t Base>
BigInt<Base> BigInt<Base>::operator--(int) {
	BigInt<Base> copy(*this);
	int carry = 1;
	operator--();
	return copy;
} // Post-decremento

template <size_t Base>
BigInt<Base> operator+(const BigInt<Base>& b1, const BigInt<Base>& b2) {

	BigInt<Base> first(b1);
	BigInt<Base> second(b2);

	// if (first.vector_.size() != second.vector_.size()) {
	// 	throw std::domain_error("Todavia no implementado diferentes tamaños");
	// }
	int loopIterations = std::min(first.vector_.size(),second.vector_.size());

	int carry = 0;
	int element = 0;
	std::list<char> list;
	for(int i=0; i<loopIterations; i++){
		element = carry + convertToNumber(first.vector_[i])
		+ convertToNumber(second.vector_[i]);
		carry = element / Base;
		element = element % Base;
		list.push_front(convertToCharacter(element));
	}
	element = 0;
	if (first.vector_.size() != second.vector_.size()) {
		BigInt<Base>* bigger;	// BigInt<Base>* bigger
		if (first.vector_.size() > second.vector_.size()) {
			bigger = &first;		// bigger = first
		} else {
			bigger = &second;		// bigger = second
		}
		for (int i=loopIterations; i<bigger->vector_.size();i++) { // bigger.vector_.size()
			element = carry + convertToNumber(bigger->vector_[i]);	// bigger.vector_[i]
			carry = element / Base;
			element = element % Base;
			list.push_front(convertToCharacter(element));
		}
	}
	if (carry != 0) 
		list.push_front(convertToCharacter(carry));
	std::string strParam;
	for(auto i : list)
		strParam.push_back(i);

	BigInt<Base> toReturn(strParam);
	return toReturn;
}

// (!!!) BigInt<Base> operator-(const BigInt<Base> &) const;

// (!!!) BigInt<Base> operator-() const;

template <size_t Base>
BigInt<Base> BigInt<Base>::operator*(const BigInt<Base>& multiplier) const {
	BigInt<Base> zero;
	if (multiplier == zero){
		return zero;
	}

	BigInt<Base> iterator;	// Zero by default
	BigInt<Base> copy(*this);
	BigInt<Base> result;
	while (iterator < (multiplier)) {
		result = result + copy;
		iterator++;
	}
	return result;
}

// (!!!) friend BigInt<Base> operator/(const BigInt<Base>&, const BigInt<Base>&);

// (!!!) BigInt<Base> operator%(const BigInt<Base>&) const;

// (!!!) friend BigInt<Base> pow(const BigInt<Base>&, const BigInt<Base>&);


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
	//std::cout << str << ", tamaño: " << str.size() << std::endl;
	for(int i=str.size()-1; i>=0; i--){
		checkCharFromBase(str[i]);
		vector_.push_back(str[i]);
	}
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
	for (auto i : vector_)
		std::cout << i << " | ";

	std::endl(std::cout);
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