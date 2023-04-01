#include "../Base_class/SortMethod.hpp"
// Complejidad O(nk)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_742

template<class Key>
class RadixSort : public SortMethod<Key>{

public:
    RadixSort(std::vector<Key>&,long);
    ~RadixSort() override;
    void Sort() override;

private:
    std::vector<Key> vector_;
    long size_;
};

template<class Key>
RadixSort<Key>::RadixSort(std::vector<Key>& vct_p, long tam_p) : 
                        vector_(vct_p) , size_(tam_p){}

template<class Key>
RadixSort<Key>::~RadixSort(){}

template <class Key>
inline void RadixSort<Key>::Sort()
{
}