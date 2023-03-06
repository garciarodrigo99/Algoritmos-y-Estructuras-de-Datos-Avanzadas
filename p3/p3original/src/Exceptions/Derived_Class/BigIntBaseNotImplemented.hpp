#include "../Base_Class/BigIntException.hpp"

class BigIntBaseNotImplemented : public BigIntException {
public:
    BigIntBaseNotImplemented() : BigIntException("BigIntException"), msg_("Base no implementada") {}
    const char* what() const noexcept override {
        return msg_.c_str();
    }
private:
    std::string msg_;
};