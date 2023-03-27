#include <vector>
#pragma once

template<class Key>
class Sequence{

    public:
        virtual bool search(const Key& k) const = 0;
        virtual bool insert(const Key& k) = 0;
        virtual bool isFull() const = 0;
				virtual void Print() const = 0;
};

#include "../Der_classes/Block/block.hpp"
#include "../Der_classes/List/list.hpp"