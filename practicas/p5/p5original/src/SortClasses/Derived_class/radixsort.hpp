#include "../Base_class/SortMethod.hpp"
// Complejidad O(nk)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_742

#include "../Base_class/SortMethod.hpp"

template<typename Key>
void countingSort(std::vector<Key>& seq, unsigned exp) {
    std::vector<Key> output(seq.size());
    int count[10] = {0};
    for(unsigned i = 0; i < seq.size(); ++i) {
        count[(seq[i] / exp) % 10]++;
    }
    for(unsigned i = 1; i < 10; ++i) {
        count[i] += count[i - 1];
    }
    for(int i = seq.size() - 1; i >= 0; --i) {
        output[count[(seq[i] / exp) % 10] - 1] = seq[i];
        count[(seq[i] / exp) % 10]--;
    }
    for(unsigned i = 0; i < seq.size(); ++i) {
        seq[i] = output[i];
    }
}

template<typename Key>
void radixSortFunction(std::vector<Key>& seq, unsigned size) {
    Key max = seq[0];
    for(unsigned i = 1; i < size; ++i) {
        if(seq[i] > max) {
            max = seq[i];
        }
    }
    for(unsigned exp = 1; max / exp > 0; exp *= 10) {
        countingSort(seq, exp);
    }
}

template<class Key>
class RadixSortMethod : public SortMethod<Key>{

public:
    RadixSortMethod(std::vector<Key>&);
    ~RadixSortMethod() override;
    void Sort() override;

// private:
//     std::vector<Key>& vector_;
//     long size_;
};

template<class Key>
RadixSortMethod<Key>::RadixSortMethod(std::vector<Key>& vct_p) : 
                        SortMethod<Key>(vct_p) {}

template<class Key>
RadixSortMethod<Key>::~RadixSortMethod(){}

template <class Key>
inline void RadixSortMethod<Key>::Sort()
{
    radixSortFunction(this->vector_,this->size_);
}