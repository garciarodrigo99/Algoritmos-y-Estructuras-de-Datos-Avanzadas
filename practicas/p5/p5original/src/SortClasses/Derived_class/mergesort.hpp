#include "../Base_class/SortMethod.hpp"
// Complejidad O(nk)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_742

template<typename Key>
void merge(std::vector<Key>& seq, unsigned left, unsigned mid, unsigned right) {
  unsigned n1 = mid - left + 1;
  unsigned n2 = right - mid;
  std::vector<Key> leftSeq(n1), rightSeq(n2);
  for(unsigned i = 0; i < n1; ++i) {
      leftSeq[i] = seq[left + i];
  }
  for(unsigned j = 0; j < n2; ++j) {
      rightSeq[j] = seq[mid + 1 + j];
  }
  unsigned i = 0, j = 0, k = left;
  while(i < n1 && j < n2) {
      if(leftSeq[i] <= rightSeq[j]) {
          seq[k] = leftSeq[i];
          ++i;
      }
      else {
          seq[k] = rightSeq[j];
          ++j;
      }
      ++k;
  }
  while(i < n1) {
      seq[k] = leftSeq[i];
      ++i;
      ++k;
  }
  while(j < n2) {
      seq[k] = rightSeq[j];
      ++j;
      ++k;
  }
}

template<typename Key>
void mergeSortFunction(std::vector<Key>& seq, unsigned left, unsigned right) {
  if(left < right) {
    unsigned mid = left + (right - left) / 2;
    mergeSortFunction(seq, left, mid);
    mergeSortFunction(seq, mid + 1, right);
    merge(seq, left, mid, right);
  }
};

template<class Key>
class MergeSortMethod : public SortMethod<Key>{

public:
    MergeSortMethod(std::vector<Key>&);
    ~MergeSortMethod() override;
    void Sort() override;

// private:
    // std::vector<Key>& vector_;
    // long size_;
};

template<class Key>
MergeSortMethod<Key>::MergeSortMethod(std::vector<Key>& vct_p) : 
                      SortMethod<Key>(vct_p) {}

template<class Key>
MergeSortMethod<Key>::~MergeSortMethod(){}

template <class Key>
inline void MergeSortMethod<Key>::Sort()
{
  mergeSortFunction(this->vector_,0,this->size_-1);
}