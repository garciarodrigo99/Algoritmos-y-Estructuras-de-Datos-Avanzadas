#include "Number.hpp"
#include "../Derived_Class/Big_Int.hpp"

Number::~Number() {}

Number *Number::create(size_t base, std::string &s)
{
	Number* toReturn = nullptr;
	if (base == 2) {
		//toReturn = new BigInt<2>(s);
		nullptr;
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