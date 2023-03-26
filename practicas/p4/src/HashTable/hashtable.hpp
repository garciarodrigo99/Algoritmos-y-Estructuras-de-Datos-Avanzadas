#include "../Key/Base_class/Key.hpp"
#include "../F_disp/Base_class/DispersionFunction.hpp"
#include "../F_exp/Base_class/ExplorationFunction.hpp"
#include "../Sequence/Base_class/sequence.hpp"
#include <vector>
#pragma once

// namespace AEDA{

template<class Key>
class HashTable {

    public:
        //HashTable(int,DispersionFunction<Key>*,ExplorationFunction<Key>*,int);
        HashTable(int, int, int, int);
        ~HashTable();

        bool Search(const Key& k) const;
        bool Insert(const Key& k);
        void Print();

    private:
        int tablesize = 1;                  // Posiciones de la tabla
        std::vector<Sequence<Key>*> table;
        DispersionFunction<Key>* fd;        // Funcion de dispersion (falta por indicar)
        int blocksize = 0;                  // 
        ExplorationFunction<Key>* fe = nullptr;
};
//-----------------------------------------------------------------------------
template<class Key>
HashTable<Key>::HashTable(int tb_sz,int opt_fd,int opt_fe,int bl_sz){
    tablesize = tb_sz;
    blocksize = bl_sz;

    switch (opt_fd){
        case 1:
            fd = new fdModule<Key>(tablesize);
            break;
        case 2:
            fd = new fdSum<Key>(tablesize);
            break;
        case 3:
            fd = new fdSRand<Key>(tablesize);
            break;
        
        default:
            throw std::invalid_argument("Opción función de dispersión no válida.");
            break;
    }

    switch (opt_fe){
        case 0:
            break;
        case 1:
            fe = new feLineal<Key>;
            break;
        case 2:
            fe = new feCuadratica<Key>;
            break;
        case 3:
            fe = new feDobleDisp<Key>(fd);
            break;
        case 4:
            fe = new feRedispersion<Key>(tablesize);
            break;

        default:
            throw std::invalid_argument("Opción función de exploración no válida.");
            break;
    }

    if (opt_fe == 0){
        for (int i = 0; i < tablesize; i++){
            table.push_back(new list<Key>);
        }
    } else{
        for (int i = 0; i < tablesize; i++){
            table.push_back(new block<Key>(blocksize));
        }
    }
}

template<class Key>
HashTable<Key>::~HashTable(){
    table.clear();
}

template<class Key>
bool HashTable<Key>::Search(const Key& k) const {
    if (table[fd->operator()(k)]->search(k)){
        return true;
    } else {
        if (!table[fd->operator()(k)]->isFull()){
            return false;
        }
        for (size_t i = 0; i < tablesize; i++){
            if (table[fe->operator()(k,i)]->search(k)){
                return true;
            }
            if (!table[fe->operator()(k,i)]->isFull()){
                return false;
            }
        }
    }
    return false;
}

template<class Key>
bool HashTable<Key>::Insert(const Key& k){
    bool insertado = table[fd->operator()(k)]->insert(k);
    if (insertado) return true;

    for (int i = 1; i < tablesize; i++){
			int pos = (fd->operator()(k) + fe->operator()(k,i)) % tablesize;
			insertado = table[pos]->insert(k);
			if (insertado) return true;
    }
    return false;
}

template<class Key>
void HashTable<Key>::Print(){
	for (size_t i = 0; i < table.size(); i++){
		std::cout << "|" << i << "|";
		table.at(i)->Print();
		std::cout << "\n";
	}
}

// }//Namespace