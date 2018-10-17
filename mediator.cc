#include "mediator.h"

void Pattern<patterns_options::Mediator>::Notify(mediator_events event) {
    if (!click || !print) {
        throw std::invalid_argument("clients are corrupted...");
    }

    switch (event) {
        case mediator_events::click:
                click->Click();
            break;
        case mediator_events::print:
                print->Print();
            break;
        default:
            throw std::invalid_argument("bad event...");
    }
}

void Pattern<patterns_options::Mediator>::register_players() {
    click = std::make_unique<B>("clicker");
    print = std::make_unique<B>("printer");
}