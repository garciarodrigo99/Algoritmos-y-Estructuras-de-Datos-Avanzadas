#include "../../Base_class/sequence.hpp"

#include <list>

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
        std::list<Key> vct;
};

template<class Key>
list<Key>::list(){}

template<class Key>
list<Key>::~list(){}

template<class Key>
bool list<Key>::search(const Key& k) const{
    for (auto it = vct.begin(); it != vct.end(); ++it){
        if (*it == k)
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
    for (auto it = vct.begin(); it != vct.end(); ++it){
        std::cout << " |" << *it << "|";
    }
}

// template<class Key>
// std::ostream& list<Key>::operator<<(std::ostream& os) const {
// 	for (size_t i = 0; i < vct.size(); i++){
// 		os << " |" << vct[i] << "|";
// 	}
	
// 	return os;
// }