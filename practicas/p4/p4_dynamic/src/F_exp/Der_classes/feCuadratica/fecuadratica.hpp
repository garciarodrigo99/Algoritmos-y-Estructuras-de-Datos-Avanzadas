#include "../../Base_class/ExplorationFunction.hpp"

template<class Key>
class feCuadratica: public ExplorationFunction<Key> {
    public:
        feCuadratica(){}
        ~feCuadratica(){}
        unsigned operator()(const Key& k, unsigned i) const {
            return i*i;
        }
};