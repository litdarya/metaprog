#include <iostream>
#include <string>

class NullType {
};

template <class T, class U>
struct TypeList {
	typedef T head;
	typedef U tail;
};

template <class K>
struct TypeList <K, NullType> {
	typedef K head;
};


template<class T1>
struct Length {};

template<class U, class T>
struct Length <TypeList<U, T>> {
	static const size_t length = 1 + Length<T>::length;
};

template<class U>
struct Length <TypeList<U, NullType>> {
	static const size_t length = 1;
};

typedef TypeList<int, TypeList<char, TypeList<std::string, TypeList<double, NullType>>>> Example;


int main() {
	std::cout << Length<Example>::length;
	return 0;
}