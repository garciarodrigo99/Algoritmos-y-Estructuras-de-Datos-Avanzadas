#include "../Base_class/SortMethod.hpp"
// Complejidad O(n²)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_185

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
    InsertionSortMethod(std::vector<Key>&,long);
    ~InsertionSortMethod() override;
    void Sort() override;

private:
    std::vector<Key>& vector_;
    long size_;
};

template<class Key>
InsertionSortMethod<Key>::InsertionSortMethod(std::vector<Key>& vct_p, long tam_p) : 
                        vector_(vct_p) , size_(tam_p){}

template<class Key>
InsertionSortMethod<Key>::~InsertionSortMethod(){}

template <class Key>
inline void InsertionSortMethod<Key>::Sort()
{
    //std::cout << "Hola\n";   
    insertionSortFunction(vector_,size_);
}