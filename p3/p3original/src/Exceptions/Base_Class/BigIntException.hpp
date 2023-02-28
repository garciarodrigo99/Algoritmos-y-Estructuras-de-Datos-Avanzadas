#include <exception>
#include <string>

#pragma once

class BigIntBaseNotImplemented;
class BigIntBadDigit;
class BigIntDivisionByZero;
class BigIntOperationNotSupported;

class BigIntException : public std::exception {
public:
    BigIntException(const char* message) : msg_(message) {}
    const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};

#include "../Derived_Class/BigIntBaseNotImplemented.hpp"
#include "../Derived_Class/BigIntBadDigit.hpp"
#include "../Derived_Class/BigIntDivisionByZero.hpp"
#include "../Derived_Class/BigIntOperationNotSupported.hpp"