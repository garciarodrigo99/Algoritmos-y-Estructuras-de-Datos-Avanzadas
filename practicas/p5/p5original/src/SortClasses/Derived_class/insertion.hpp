#include "../Base_class/SortMethod.hpp"
// Complejidad O(n²)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_185
// El código 2, por otro lado, utiliza variables de instancia protegidas en la clase base, lo que permite que la clase derivada InsertionSortMethod tenga acceso a estas variables de instancia sin necesidad de almacenar una referencia en una variable miembro. Esto hace que el código sea más seguro y prevenido de posibles errores.

// En general, se recomienda utilizar variables de instancia protegidas en la clase base en lugar de variables de instancia privadas en la clase derivada, ya que esto hace que el código sea más seguro y menos propenso a errores.

template<typename Key>
void insertionSortFunction(std::vector<Key>& seq, unsigned size) {
    for(unsigned i = 1; i < size; ++i) {
        Key key = seq[i];
        unsigned j = i;
        while(j > 0 && seq[j - 1] > key) {
            seq[j] = seq[j - 1];
            --j;
        }
        seq[j] = key;
    }
};

template<class Key>
class InsertionSortMethod : public SortMethod<Key>{

public:
    InsertionSortMethod(std::vector<Key>&);
    ~InsertionSortMethod() override;
    void Sort() override;

// private:
//     std::vector<Key>& vector_;
//     long size_;
};

template<class Key>
InsertionSortMethod<Key>::InsertionSortMethod(std::vector<Key>& vct_p) : 
                          SortMethod<Key>(vct_p) {}

template<class Key>
InsertionSortMethod<Key>::~InsertionSortMethod(){}

template <class Key>
inline void InsertionSortMethod<Key>::Sort()
{  
    insertionSortFunction(this->vector_,this->size_);
}