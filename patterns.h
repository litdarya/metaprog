#include <memory>
#pragma once
#include "main.h"

#include <unordered_set>
#include <vector>
#include <exception>
#include <memory>

template<>
class Pattern<patterns_options::Mediator> {
public:
    Pattern<patterns_options::Mediator>() {
        register_players();
    }

    void Notify(mediator_events event) {
        if (!click || !print) {
            throw std::invalid_argument("clients are corrupted...");
        }

        switch (event) {
            case mediator_events::click:
                    click->click();
                break;
            case mediator_events::print:
                    print->print();
                break;
            default:
                throw std::invalid_argument("bad event...");
        }
    }

private:
    std::unique_ptr<B> click = nullptr;
    std::unique_ptr<B> print = nullptr;

    void register_players() {
        click = std::make_unique<B>("clicker");
        print = std::make_unique<B>("printer");
    }
};