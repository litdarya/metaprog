#include <iostream>
#include <string>

class NullType {};

template <typename ... Args>
struct TypeList {
	using Head = NullType;
	using Tail = NullType;
};

typedef TypeList<> EmptyList;

template <typename H, typename ... T>
struct TypeList <H, T ...> {
	using Head = H;
	using Tail = TypeList<T ... >;
};

template<typename ... Args>
struct Length {};

template <typename U, typename ... T>
struct Length <TypeList<U, T ... >> {
	static const size_t length = 1 + Length<TypeList<T ... >>::length;
};

template <>
struct Length <EmptyList> {
	static const size_t length = 0;
};

template <typename TypeList, size_t i>
struct GetElem {
	using Result = typename GetElem<typename TypeList::Tail, i - 1>::Result;
};

template <typename TypeList>
struct GetElem <TypeList, 0> {
	using Result = typename TypeList::Head;
};


template <>
struct GetElem <EmptyList, 0> {
	using Result = NullType;
};

typedef TypeList<int, char, std::string, float, int> my_list;

int main() {
	// std::cout << Length<my_list>::length;
	GetElem<my_list, 1>::Result a = 'a';
	return 0;
}
// сделать добавление и удаление