#pragma once
#include "linearGen.h"
#include "fibonacci.h"

// Generates TypeList of linear hierarchies

template<int i, typename T, template<class, class> class Unit, typename R=EmptyList>
struct GenerateListLinear;

template<int i, typename H, typename ...T, template<class, class> class U, typename R>
struct GenerateListLinear<i, TypeList<H, T ...>, U, R> {
	static constexpr int fib = fibonacci<i>();
	using TL = TypeList<H, T...>;
	using Elem = LinearHierarchy<fib, TL, U>;
	using NewR = typename Add<R, Elem, 0>::Result;
	using Result = typename GenerateListLinear<i + 1, typename GetTail<TL, fib>::Result, U, NewR>::Result;
};

template<int i, template<class, class> class U, typename R>
struct GenerateListLinear<i, EmptyList, U, R> {
	using Result = R;
};