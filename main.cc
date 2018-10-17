#include "AB.h"
#include "mediator.h"
#include "observer.h"
#include "proxy.h"

int main() {
	// Mediator sample
	Pattern<patterns_options::Mediator> mediator;
	A a("test A", &mediator);
	a.Click();
	a.Print();

	// Proxy sample
	B b("ordinary B");
	Pattern<patterns_options::Proxy> proxy("proxy B");
	a.Beautiful_print(b);
	a.Beautiful_print(proxy);

	// Observer sample
	A a1("A1");
	Pattern<patterns_options::Observer> observer1("B1");
	observer1.Subscribe(observer_events::click, &a1);
	observer1.Click();

	A a2("A2");
	Pattern<patterns_options::Observer> observer2("B2");
	observer2.Subscribe(observer_events::print, &a2);
	observer2.Click();
	observer2.Print();

	return 0;
}