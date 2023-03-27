#include "../../Base_class/ExplorationFunction.hpp"
#include "../../../F_disp/Base_class/DispersionFunction.hpp"

template<class Key>
class feDobleDisp: public ExplorationFunction<Key> {
    public:
        feDobleDisp(DispersionFunction<Key>* ptr_param){
            ptr_fd = ptr_param;
        }
        ~feDobleDisp(){}
        unsigned operator()(const Key& k, unsigned i) const {
            return ptr_fd->operator()(k) * i;
        }
    
    private:
        DispersionFunction<Key>* ptr_fd;
};