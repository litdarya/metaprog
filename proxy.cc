#include "proxy.h"

std::string Pattern<patterns_options::Proxy>::GetName() {
	std::stringstream printer;
    printer << "B's name is " << B::GetName() << std::endl;
    printer << "-------------";
    return printer.str();
}