#include <iostream>
#include <cxxabi.h>
#include <string>

#include "linear.h"
#include "linearGen.h"
#include "scatter.h"
#include "typeList.h"

template<class T>
std::string GetNamePretty() {
	int status;
	return abi::__cxa_demangle(typeid(T).name(), 0, 0, &status);
}

// Example
template <class Next, class Base>
class Example: public Next, public Base {
public:
	virtual void Call() {
		if (GetNamePretty<Next>() == "TypeList<>") {
			std::cout << "end" << std::endl;
			return;
		}
		std::cout << GetNamePretty<Next>() << "->";
		Base::Call();
	}
};

class Example1 {};
class Example2 {};
class Example3 {};
class Example4 {};
class Example5 {};
class Example6 {};

typedef TypeList<Example1, Example2, Example3, Example4, Example5, Example6> hierarchy_list;

typedef GenerateListLinear<0, hierarchy_list, Example>::Result linear_list;

typedef ScatterHierarchy<linear_list> tree_root;

int main() {
	std::cout << GetNamePretty<tree_root>() << std::endl;

	typename tree_root::Left root_example;
	root_example.Call();

	return 0;
}