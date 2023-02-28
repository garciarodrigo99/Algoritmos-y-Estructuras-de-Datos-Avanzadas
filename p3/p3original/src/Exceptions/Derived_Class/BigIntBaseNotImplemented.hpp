#include "../Base_Class/BigIntException.hpp"

class BigIntBaseNotImplemented : public BigIntException {
public:
    BigIntBaseNotImplemented(const char* message) : BigIntException(message), msg_(message) {}
    const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};