#include "../Base_class/SortMethod.hpp"
// Complejidad O(n²)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_185

template<typename Key>
void selectionSortFunction(std::vector<Key>& seq, unsigned size) {
    for (size_t i = 0; i < seq.size() - 1; i++){
        int indice_menor = i;
        Key valor_menor = seq[i];
        for (size_t j = i + 1; j < seq.size(); j++){
            if (seq[j] < valor_menor){
                valor_menor = seq[j];
                indice_menor = j;
            }
        }
        std::swap(seq[i],seq[indice_menor]);
    }
};

template<class Key>
class SelectionSortMethod : public SortMethod<Key>{

public:
    SelectionSortMethod(std::vector<Key>&,long);
    ~SelectionSortMethod() override;
    void Sort() override;

private:
    std::vector<Key>& vector_;
    long size_;
};

template<class Key>
SelectionSortMethod<Key>::SelectionSortMethod(std::vector<Key>& vct_p, long tam_p) : 
                        vector_(vct_p) , size_(tam_p){}

template<class Key>
SelectionSortMethod<Key>::~SelectionSortMethod(){}

template <class Key>
inline void SelectionSortMethod<Key>::Sort()
{
    selectionSortFunction(vector_,size_);
}