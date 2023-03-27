#include "../../Base_class/DispersionFunction.hpp"

template<class Key>
class fdSum: public DispersionFunction<Key> {
    public:
        fdSum(const unsigned n): tableSize(n){}
        unsigned operator()(const Key& k) const {
            long p = k; // Cuidado
            int sum=0;
            while (p > 0){
                sum = sum + (p % 10);
                p = p / 10;
            }
            //std::cout << "Sum: " << sum << std::endl;
            return sum % tableSize;
        }
    private:
        unsigned tableSize;
};