#include "../Base_class/SortMethod.hpp"
// Complejidad O(n^1.25)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_716

template<typename Key>
void deltaSort(std::vector<Key>& seq, unsigned size, float delta) {
    for (unsigned i = delta; i < size; i++){
        Key x = seq[i];
        int j = i;
        while ((j >= delta) && (x<seq[j-delta])){
            seq[j]=seq[j-delta];
            j=j-delta;
        }
        seq[j]=x;
    }
}

template<typename Key>
void shellSortFunction(std::vector<Key>& seq, unsigned size, float alfa = 0.5) {
    // float delta = size * alfa;
    float delta = size;
    int contador = 0;
    while (delta > 1.0){
        delta *= alfa;
        deltaSort(seq,size,delta);
        contador++;
    }
}


template<class Key>
class ShellShortMethod : public SortMethod<Key>{

public:
    ShellShortMethod(std::vector<Key>&,long,float = 0.5);
    ~ShellShortMethod() override;
    void Sort() override;

private:
    std::vector<Key>& vector_;
    long size_ = 0;
    float alfa_ = 0.5;
};

template<class Key>
ShellShortMethod<Key>::ShellShortMethod(std::vector<Key>& vct_p, long tam_p, float alfa__p) :
                            vector_(vct_p), size_(tam_p), alfa_(alfa__p){}

template<class Key>
ShellShortMethod<Key>::~ShellShortMethod(){}

template <class Key>
inline void ShellShortMethod<Key>::Sort()
{
    shellSortFunction(vector_,size_,alfa_);
}