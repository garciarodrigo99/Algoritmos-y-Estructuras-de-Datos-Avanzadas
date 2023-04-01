#include "../Base_class/SortMethod.hpp"
// Complejidad Promedio: O(n log n),
//            peor caso: O(n²)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_504

template<typename Key>
void quick(std::vector<Key>& seq, long start, long end) {
    long i = start;
    long f = end;
    Key p = seq[(i+f)/2];
    while (i <= f){
        while (seq[i] < p) i++;
        while (seq[f] > p) f--;
        if (i <= f) {
            std::swap(seq[i],seq[f]) ;
            i++; 
            f--;
        }
    }
    if (start < f) quick(seq, start, f); 
    if (i < end) quick(seq, i, end);
}

template<typename Key>
void quickSortFunction(std::vector<Key>& seq, long start, long end) {
    quick(seq,start,end);
}

template<class Key>
class QuickSort : public SortMethod<Key>{

public:
    QuickSort(std::vector<Key>&,long,long);
    ~QuickSort() override;
    void Sort() override;

private:
    std::vector<Key> vector_;
    long start_,end_;
};

template<class Key>
QuickSort<Key>::QuickSort(std::vector<Key>& vct_p, long ini_p, long end__p) : 
                        vector_(vct_p) , start_(ini_p), end_(end__p) {}

template<class Key>
QuickSort<Key>::~QuickSort(){}


template <class Key>
inline void QuickSort<Key>::Sort()
{
    quickSortFunction(vector_,start_,end_);
}