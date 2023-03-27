#include "../../Base_class/ExplorationFunction.hpp"

template<class Key>
class feRedispersion: public ExplorationFunction<Key> {
    public:
        feRedispersion(int n){
            tam_tabla = n;
        }
        ~feRedispersion(){}
        unsigned operator()(const Key& k, unsigned i) const {
            srand(k);
            int value;
            for(unsigned j = 0; j <= i; j++){
                value = rand() % tam_tabla;
            }
            return value; 
        }
    private:
        int tam_tabla;
};