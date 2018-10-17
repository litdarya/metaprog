#include "observer.h"

void Pattern<patterns_options::Observer>::Subscribe(observer_events event, A* listener) {
    listeners[event].insert(listener);
}

void Pattern<patterns_options::Observer>::Unsubscribe(observer_events event, A* listener) {
    listeners[event].erase(listener);
}

void Pattern<patterns_options::Observer>::Click() {
    B::Click();
    Notify(observer_events::click);    
}

void Pattern<patterns_options::Observer>::Print() {	
    B::Print();
    Notify(observer_events::print);    
}

void Pattern<patterns_options::Observer>::Notify(observer_events event) {
    for (auto it : listeners[event]) {
        it->Get_notify(event);
    }
}