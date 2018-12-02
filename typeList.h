#pragma once

class NullType {};

template <typename ... Args>
struct TypeList {
	using Head = NullType;
	using Tail = TypeList<>;
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

template <typename TypeList, size_t i>
struct GetTail {
	using Result = typename GetTail<typename TypeList::Tail, i - 1>::Result;
};

template <typename TypeList>
struct GetTail <TypeList, 0> {
	using Result = TypeList;
};

template <>
struct GetTail <EmptyList, 0> {
	using Result = EmptyList;
};

template<typename ... Args>
struct Union {};

template <typename U, typename ... T, typename N, typename ... F>
struct Union <TypeList<U, T ... >, TypeList<N, F...>> {
	using Result = TypeList<U, T..., N, F...>;
};

template <typename U, typename ... T>
struct Union <TypeList<U, T ... >, EmptyList> {
	using Result = TypeList<U, T...>;
};

// Add to i-th place
template <typename TypeList, typename T, size_t i>
struct Add;

template<size_t i>
struct Add <EmptyList, NullType, i> {
	using Result = EmptyList;
};

template <typename T, size_t i>
struct Add <EmptyList, T, i> {
	using Result = TypeList<T>;
};

template <typename U, typename ... T, size_t i>
struct Add <EmptyList, TypeList<U, T ...>, i> {
	using Result = TypeList<U, T ...>;
};

template <typename U, typename ... T, typename N, size_t i>
struct Add <TypeList<U, T ... >, N, i> {
	using Result = typename Union<TypeList<U>, typename Add<TypeList<T ...>, N, i - 1>::Result>::Result;
};

template <typename U, typename ... T, typename N>
struct Add <TypeList<U, T ...>, N, 0> {
	using Result = TypeList<N, U, T...>;
};

// Remove i-th element
template <typename TypeList, size_t i>
struct Remove;

template<size_t i>
struct Remove <EmptyList, i> {
	using Result = EmptyList;
};

template <typename U, typename ... T, size_t i>
struct Remove <TypeList<U, T ... >, i> {
	using Result = typename Union<TypeList<U>, typename Remove<TypeList<T ...>, i - 1>::Result>::Result;
};

template <typename U, typename ... T>
struct Remove <TypeList<U, T ...>, 0> {
	using Result = TypeList<T...>;
};

template <typename U>
struct Remove <TypeList<U>, 0> {
	using Result = EmptyList;
};