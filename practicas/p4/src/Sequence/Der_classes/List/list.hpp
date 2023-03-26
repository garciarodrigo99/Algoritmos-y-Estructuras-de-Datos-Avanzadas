#include "../../Base_class/sequence.hpp"

template<class Key>
class list : public Sequence<Key>{

    public:
        list();
        ~list();

        bool search(const Key& k) const;
        bool insert(const Key& k);
        bool isFull() const;
        void Print() const;
        //friend std::ostream& operator<<(std::ostream& os) const override;

    private:
        std::vector<Key> vct;
};

template<class Key>
list<Key>::list(){}

template<class Key>
list<Key>::~list(){}

template<class Key>
bool list<Key>::search(const Key& k) const{
    for (size_t i = 0; i < vct.size(); i++){
        if (vct[i] == k)
            return true; 
    }
    return false;
}

template<class Key>
bool list<Key>::insert(const Key& k) {
    if (search(k)){
        return false;
    } else {
        vct.push_back(k);
        return true;
    }
}

template<class Key>
bool list<Key>::isFull() const {
    return false;
}

template <class Key>
void list<Key>::Print() const
{
  for (size_t i = 0; i < vct.size(); i++){
		std::cout << " |" << vct[i] << "|";
	}
}

// template<class Key>
// std::ostream& list<Key>::operator<<(std::ostream& os) const {
// 	for (size_t i = 0; i < vct.size(); i++){
// 		os << " |" << vct[i] << "|";
// 	}
	
// 	return os;
// }