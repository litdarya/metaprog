#pragma once

#include "AB.h"
#include "Patterns.h"

#include <sstream>

template<>
class Pattern<patterns_options::Proxy>: public B {
public:
    Pattern<patterns_options::Proxy>(std::string name):B(name){}

    std::string GetName() override;
};