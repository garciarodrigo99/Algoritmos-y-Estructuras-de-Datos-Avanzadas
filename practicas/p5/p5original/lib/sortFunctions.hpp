#include <iostream>
#include <vector>

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
	}
};