#include "AB.h"

void A::Beautiful_print(B &b){
	std::cout << name << std::endl;
	std::cout << b.GetName() << std::endl;
}

void A::Click() {
	std::cout << "A: click" <<std::endl;
	mediator->Notify(mediator_events::click);
}

void A::Get_notify(observer_events event) {
	std::cout << "A: " << name << " received event " << event << std::endl;
}

void A::Print() {
	std::cout << "A: print" <<std::endl;
	mediator->Notify(mediator_events::print);
}

void B::Print() {
	std::cout << "B: I am " << name << " and I am printing" << std::endl;
}

void B::Click() {
	std::cout << "B: I am " << name << " and I am clicking" << std::endl;
}

std::string B::GetName() {
	return name;
}