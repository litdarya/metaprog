#pragma once

#include <iostream>
#include <string>

#include "mediator.h"
#include "Patterns.h"

class B;

class A {
public:
	A(std::string name_):name(name_) {};
	A(std::string name_, Pattern<patterns_options::Mediator>* mediator_):
																name(name_),
																mediator(mediator_) {};

	void Beautiful_print(B &b);
	void Click();
	void Get_notify(observer_events event);
	void Print();
private:
	Pattern<patterns_options::Mediator>* mediator;
	std::string name;
};

class B {
public:
	B(std::string name_):name(name_) {};

	virtual void Click();
	virtual std::string GetName();
	virtual void Print();
private:
	std::string name;
};