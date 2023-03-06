// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: ALGORITMOS Y ESTRUCTURAS DE DATOS AVANZADAS
// Curso: 2º
// Práctica 3: Calculadora universal para números enteros grandes
// Autor: Rodrigo Garcia Jimenez
// Correo: alu0101154473@ull.edu.es
// Fecha: 06/03/2023
// Archivo Big_Int.hpp: Definición de la especialización BigInt<2>
// Se hace de esta manera para evitar la definición múltiple de los métodos
// de la especialización de la plantilla.
// Referencias:
// Enlaces de interéss
// https://stackoverflow.com/questions/4445654/multiple-definition-of-template-specialization-when-using-different-objects
// https://stackoverflow.com/questions/53660616/explicit-template-specialization-multiple-definitions
// https://stackoverflow.com/questions/43566006/c-error-multiple-definition-of-a-member-function-specialized-in-template-clas
// Historial de revisiones
// 28/02/2023 - Creación (primera versión) del código

#include "Big_Int.hpp"

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

size_t BigInt<2>::sizeOf()
{
	size_t result;
	for (size_t i = 0; i < c2_.size(); i++){
		result += sizeof(bool);
	}
	
  return result;
}

BigInt<2> &BigInt<2>::operator=(const BigInt<2> &binary)
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

std::istream& operator>>(std::istream& is,BigInt<2>& binary) {
	std::string input;
	is >> input;
	binary = BigInt<2>(input);
	return is;
}

inline bool BigInt<2>::sign() const
{
	return c2_.back();
}

inline char BigInt<2>::operator[](int index) const
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
		bool element = firstCopy.c2_[i] ^ secondCopy.c2_[i] ^ carry;
		carry = (firstCopy[i] & secondCopy[i]) | (firstCopy[i] & carry) | (secondCopy[i] & carry);
		boolString.push_back(element ? '1' : '0');
	}
	if (!addBit && (boolString.back() != firstCopy.sign())) {
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

BigInt<2> operator/(const BigInt<2>& first, const BigInt<2>& second) {
	if (second == BigInt<2>("0")){
		throw BigIntDivisionByZero("Divisor es 0");
	}
	if (first == BigInt<2>("0")){
		return BigInt<2>("0");
	}
	if (first < second){
		return BigInt<2>("0");
	}
	BigInt<2> base("010");
	BigInt<2> minuendo(first.c2_.back());		// Va a ser el resto
	BigInt<2> sustraendo;	
	std::string cociente;
	bool firstElementSet = false;
	int firstElemPos = first.c2_.size() - 1;
	while (minuendo < second){
		minuendo.c2_.insert(minuendo.c2_.begin(),first.c2_[firstElemPos-1]);
		--firstElemPos;
		cociente.push_back('0');
	}
	++firstElemPos;
	for (int i = firstElemPos; i > 0; i--) {
		if(firstElementSet) {
			if (i != 0) {
				minuendo.c2_.insert(minuendo.c2_.begin(),first.c2_[i-1]);
			} else {
				minuendo.c2_.insert(minuendo.c2_.begin(),first.c2_[i]);
			}
		}
		int secondLoop = 0;
		BigInt<2> indexCociente;
		BigInt<2> tmp;	// Elemento i del while pero en base(Base)
		if (!firstElementSet){
			secondLoop = 1;
			tmp++;
			indexCociente++; // Minimo ya que sabemos first > second
			firstElementSet = true;
		}
		while (secondLoop < 2){ // Cambiar primera vez
			if((tmp*second) <= minuendo){
				indexCociente = tmp;
			} else {
				break;
			}
			secondLoop++;
			tmp++;
		}
		sustraendo = second * indexCociente;
		cociente.push_back(convertToCharacter(indexCociente.c2_[0]));
		minuendo = minuendo - sustraendo;
	}
	return (BigInt<2>(cociente));
}

BigInt<2> BigInt<2>::operator%(const BigInt<2>& param) const {
	return BigInt<2>(*this - (param * (*this / param)));
}

BigInt<2> pow(const BigInt<2>& base, const BigInt<2>& exponent) {
	
	if (exponent == BigInt<2>("0")) {
		return BigInt<2>(1);
	}
	if (exponent < BigInt<2>("0")){
		throw BigIntOperationNotSupported("Operacion no soportada");
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

BigInt<2> BigInt<2>::factorial() const  {
	BigInt<2> result("01");
	BigInt<2> current(*this);

	while (current > BigInt<2>("01")) {
		result = result * current;
		--current;
	}

	return result;
}

template <size_t BaseToConvert>
BigInt<2>::operator BigInt<BaseToConvert>()
{
	BigInt<BaseToConvert> result;
	BigInt<2> naturalBinary(*this);
	if (naturalBinary.sign())
		naturalBinary = complementNumber();
	
	BigInt<BaseToConvert> exponent;
	for (size_t i = 0; i < naturalBinary.c2_.size()-1; i++) {
		result = (result + (BigInt<BaseToConvert>
							(pow(BigInt<BaseToConvert>(2),exponent) 
							* BigInt<BaseToConvert>(naturalBinary.c2_[i]))));
		exponent++;
	}
	if (sign())
		result = result * BigInt<BaseToConvert>(-1);
	
	return result;
}

Number *BigInt<2>::add(const Number * number) const
{
	BigInt<2> aux = number->operator BigInt<2>();
	BigInt<2> copy(*this);
	aux = copy + aux;
  return (new BigInt<2>(aux));
}

Number *BigInt<2>::subtract(const Number * number) const
{
	BigInt<2> aux = number->operator BigInt<2>();
	aux = *this - aux;
  return (new BigInt<2>(aux));
}

Number *BigInt<2>::multiply(const Number * number) const
{
	BigInt<2> aux = number->operator BigInt<2>();
	aux = *this * aux;
  return (new BigInt<2>(aux));
}

Number *BigInt<2>::divide(const Number * number) const
{
	BigInt<2> aux = number->operator BigInt<2>();
	aux = *this / aux;
  return (new BigInt<2>(aux));
}

Number *BigInt<2>::module(const Number * number) const
{
	BigInt<2> aux = number->operator BigInt<2>();
	aux = *this % aux;
  return (new BigInt<2>(aux));
}

Number *BigInt<2>::power(const Number * number) const
{
	BigInt<2> aux = number->operator BigInt<2>();
	BigInt<2> copy(*this);
	BigInt<2> result(pow(copy,aux));
	// aux = pow(*this,aux);
  return (new BigInt<2>(result));
}

BigInt<2>::operator BigInt<2>() const
{
	return (*this);
}

BigInt<2>::operator BigInt<8>() const
{
  BigInt<2> copy(*this);
	return BigInt<8>(copy);
  //return BigInt<8>(*this); // Segmentation fault
}

BigInt<2>::operator BigInt<10>() const
{	
  BigInt<2> copy(*this);
	return BigInt<10>(copy);
  //return BigInt<10>(*this); // Segmentation fault
}

BigInt<2>::operator BigInt<16>() const
{
  BigInt<2> copy(*this);
	return BigInt<16>(copy);
  //return BigInt<16>(*this); // Segmentation fault
}

inline std::ostream &BigInt<2>::write(std::ostream & os) const
{
  os << "2, " << *this;
	return os;
}

std::istream &BigInt<2>::read(std::istream & is)
{
  is >> *this;
	return is;
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
	if (c2_.size() == 1){
		c2_.push_back(false);
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
		throw BigIntBadDigit("Digito no binario");
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
