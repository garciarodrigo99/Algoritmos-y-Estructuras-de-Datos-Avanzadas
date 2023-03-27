#include "../../Base_class/sequence.hpp"

template<class Key>
class block : public Sequence<Key>{

    public:
        block(int);
        ~block();

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const;
		void Print() const override;
        //friend std::ostream& operator<<(std::ostream& os, const block<Key>) const;

    private:
        Key* vct;
        int blocksize;
        int count = 0;
};

template<class Key>
block<Key>::block(int size_param) : blocksize (size_param){
    vct = new Key[blocksize];
}

template<class Key>
block<Key>::~block(){
    delete[] vct;
}

template<class Key>
bool block<Key>::search(const Key& k) const {
    for (int i = 0; i < count; i++){
        if (k == vct[i])
            return true;   
    }
    return false;
}

template<class Key>
bool block<Key>::insert(const Key& k) {
    if (isFull())
        return false;

    vct[count] = k;
    count++;
    return true;
}

template<class Key>
bool block<Key>::isFull() const {
    if (count == blocksize)
        return true;

    return false;
}

template <class Key>
void block<Key>::Print() const
{
	for (int i = 0; i < count; i++){
		std::cout << " |" << vct[i] << "|";
	}
}

// template<class Key>
// std::ostream& operator<<(std::ostream& os) const {
// 	for (size_t i = 0; i < vct.size(); i++){
// 		os << " |" << vct[i] << "|";
// 	}
	
// 	return os;
// }