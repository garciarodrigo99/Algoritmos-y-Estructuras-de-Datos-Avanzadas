#include <iostream>
#include <vector>
#pragma once

template<typename Key>
void printVector(std::vector<Key>& seq) {
	for (size_t i = 0; i < seq.size(); i++) {
		std::cout << seq[i] << " ";
	}
	std::endl(std::cout);
}

// Insertion sort
template<typename Key>
void insertionSortFunction(std::vector<Key>& seq, unsigned size, 
													bool printTrace = true) {
	for(unsigned i = 1; i < size; ++i) {
		Key key = seq[i];
		unsigned j = i;
		while(j > 0 && seq[j - 1] > key) {
				seq[j] = seq[j - 1];
				--j;
		}
		seq[j] = key;
		if (printTrace) printVector(seq);
	}
};
// ----------------------------------------------------------------------------

// Merge
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
void mergeSortFunction(std::vector<Key>& seq, unsigned left, unsigned right,
                      bool printTrace = true) {
  if(left < right) {
    unsigned mid = left + (right - left) / 2;
    mergeSortFunction(seq, left, mid);
    mergeSortFunction(seq, mid + 1, right);
    merge(seq, left, mid, right);
  }
};
// ----------------------------------------------------------------------------

// ShellSort
template<typename Key>
void deltaSort(std::vector<Key>& seq, unsigned size, float delta, 
							bool printTrace = true) {
    for (unsigned i = delta; i < size; i++){
        Key x = seq[i];
        int j = i;
        while ((j >= delta) && (x<seq[j-delta])){
            seq[j]=seq[j-delta];
            j=j-delta;
						if (printTrace) printVector(seq);
        }
        seq[j]=x;
				if (printTrace) printVector(seq);
    }
}

template<typename Key>
void shellSortFunction(std::vector<Key>& seq, unsigned size, float alfa = 0.5,
											bool printTrace = true) {
	// float delta = size * alfa;
	float delta = size;
	int contador = 0;
	while (delta > 1.0){
			delta *= alfa;
			deltaSort(seq,size,delta,printTrace);
			contador++;
	}
}
// ----------------------------------------------------------------------------

// HeapSort
template<class Key>
void baja(std::vector<Key>& vector,long size,int iteracion,
					bool printTrace = true){
    int h = iteracion;
    int h1 = (2*iteracion); 
    int h2 = h1 + 1;
    if((h1 < size) && (vector[h1] > vector[h]))
        h = h1;

    if((h2 < size) && (vector[h2] > vector[h]))
        h = h2;
    
    if(h != iteracion) {
        std::swap(vector[iteracion],vector[h]);
				if (printTrace) printVector(vector);
        baja(vector,size,h);
    }
}

template<typename Key>
void heapSortFunction(std::vector<Key>& seq, unsigned size, 
                    	bool printTrace = true ) {
    //Algoritmo HeapSort
    for(int i = (size/2)-1; i >= 0; i--){
        baja(seq, size,i,printTrace);
    }
    for(int i = size-1; i >= 0; i--){
			std::swap(seq[0],seq[i]);
			if (printTrace) printVector(seq);
			baja(seq,i,0,printTrace);
    }
}
// ----------------------------------------------------------------------------

// RadixSort
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
void radixSortFunction(std::vector<Key>& seq, unsigned size, 
											bool printTrace = true) {
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
// ----------------------------------------------------------------------------

// SelectionSort
template<typename Key>
void selectionSortFunction(std::vector<Key>& seq, unsigned size,
													bool printTrace = true) {
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
				if (printTrace) printVector(seq);
    }
};
// ----------------------------------------------------------------------------

// QuickSort
template<typename Key>
void quick(std::vector<Key>& seq, long start, long end,
					bool printTrace = true) {
    long i = start;
    long f = end;
    Key p = seq[(i+f)/2];
    while (i <= f){
        while (seq[i] < p) i++;
        while (seq[f] > p) f--;
        if (i <= f) {
            std::swap(seq[i],seq[f]);
						if (printTrace) printVector(seq);
            i++; 
            f--;
        }
    }
    if (start < f) quick(seq, start, f); 
    if (i < end) quick(seq, i, end);
}

template<typename Key>
void quickSortFunction(std::vector<Key>& seq, long start, long end, 
											bool printTrace = true) {
	quick(seq,start,end,printTrace);
}
// ----------------------------------------------------------------------------