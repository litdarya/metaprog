#pragma once

#include "AB.h"
#include "Patterns.h"

#include <exception>
#include <memory>

class B;

template<>
class Pattern<patterns_options::Mediator> {
public:
    Pattern<patterns_options::Mediator>() { register_players(); }
    void Notify(mediator_events event);

private:
    std::unique_ptr<B> click = nullptr;
    std::unique_ptr<B> print = nullptr;

    void register_players();
};