#include "../../Base_class/ExplorationFunction.hpp"

template<class Key>
class feLineal: public ExplorationFunction<Key> {
    public:
        feLineal(){}
        ~feLineal(){}
        unsigned operator()(const Key& k, unsigned i) const {
            return i;
        }
};
