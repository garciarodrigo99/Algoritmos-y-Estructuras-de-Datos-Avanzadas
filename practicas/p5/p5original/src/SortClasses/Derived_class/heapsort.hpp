#include "../Base_class/SortMethod.hpp"
// Complejidad O(n log n)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_457

template<class Key>
void baja(std::vector<Key>& vector,long size,int iteracion){
    //std::cout << "Estás en baja()\n";
    int h = iteracion;
    int h1 = (2*iteracion); 
    int h2 = h1 + 1;
    if((h1 < size) && (vector[h1] > vector[h]))
        //std::cout << "Baja\n";
        h = h1;

    if((h2 < size) && (vector[h2] > vector[h]))
        //std::cout << "Sube\n";
        h = h2;
    
    if(h != iteracion) {
        //std::cout << "Colocado\n";
        std::swap(vector[iteracion],vector[h]);
        baja(vector,size,h);
    }
}

template<typename Key>
void heapSortFunction(std::vector<Key>& seq, unsigned size) {
    //Algoritmo HeapSort
    for(int i = (size/2)-1; i >= 0; i--){
        baja(seq, size,i);
    }
    for(int i = size-1; i >= 0; i--){
        std::swap(seq[0],seq[i]);
        baja(seq,i,0);
    }
}

template<class Key>
class HeapSortMethod : public SortMethod<Key>{

public:
    HeapSortMethod(std::vector<Key>&);
    ~HeapSortMethod() override;
    void Sort() override;

// private:
    // std::vector<Key>& vector_;
    // long size_;
};

template<class Key>
HeapSortMethod<Key>::HeapSortMethod(std::vector<Key>& vct_p) : 
                    SortMethod<Key>(vct_p) {}

template<class Key>
HeapSortMethod<Key>::~HeapSortMethod(){}

template <class Key>
inline void HeapSortMethod<Key>::Sort()
{
    heapSortFunction(this->vector_,this->size_);
}