#pragma once

#include "AB.h"
#include "Patterns.h"

#include <array>
#include <set>

template<>
class Pattern<patterns_options::Observer> : public B {
public:
    Pattern<patterns_options::Observer>(std::string name):B(name){};

    void Click() override;
    void Notify(observer_events event);
    void Print() override;
    void Subscribe(observer_events event, A* listener);
    void Unsubscribe(observer_events event, A* listener);
private:
    std::array<std::set<A*>, observer_events::COUNT> listeners;
};