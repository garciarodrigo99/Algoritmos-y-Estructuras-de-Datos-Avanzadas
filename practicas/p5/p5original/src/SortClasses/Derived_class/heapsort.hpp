#include "../Base_class/SortMethod.hpp"
// Complejidad O(n log n)
// https://docs.google.com/presentation/d/1Hllv0bOMllv5sYFNPZ05NhISbtf6hGJE5BhZi0Fpq3g/edit#slide=id.g119bcdab500_1_457

template<class Key>
class HeapSort : public SortMethod<Key>{

public:
    HeapSort(std::vector<Key>&,long);
    ~HeapSort() override;
    //std::vector<Key> orderedVector() override;
    void Sort() override;

private:
    void baja(std::vector<Key>&,long,int);
    void heap();

private:
    std::vector<Key> muestra;
    long tamanno;
};

template<class Key>
HeapSort<Key>::HeapSort(std::vector<Key>& vct_p, long tam_p) : 
                        muestra(vct_p) , tamanno(tam_p){}

template<class Key>
HeapSort<Key>::~HeapSort(){}

// template<class Key>
// std::vector<Key> HeapSort<Key>::orderedVector(){
//     heap();
//     return muestra;
// }

template<class Key>
void HeapSort<Key>::heap(){
      //Algoritmo HeapSort
      for(int i = (tamanno/2)-1; i >= 0; i--){
        baja(muestra, tamanno,i);
      }
      for(int i = tamanno-1; i >= 0; i--){
        std::swap(muestra[0],muestra[i]);
        baja(muestra,i,0);
      }
}

template<class Key>
void HeapSort<Key>::baja(std::vector<Key>& vector,long size,int iteracion){
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

template <class Key>
inline void HeapSort<Key>::Sort()
{
}