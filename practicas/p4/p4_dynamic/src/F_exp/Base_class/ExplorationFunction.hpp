#include "../../Key/Base_class/Key.hpp"
#pragma once

template<class Key>
class ExplorationFunction {
    public:
    virtual unsigned operator()(const Key& k, unsigned i) const = 0;
};

#include "../Der_classes/feCuadratica/fecuadratica.hpp"
#include "../Der_classes/feDobleDisp/fedobledisp.hpp"
#include "../Der_classes/feLineal/felineal.hpp"
#include "../Der_classes/feRedispersion/feredispersion.hpp"