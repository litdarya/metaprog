#pragma once

#include "typeList.h"
// Scatter hierarchy

template <typename TypeList>
class ScatterHierarchy;

template <class H, class ...T>
class ScatterHierarchy<TypeList<H, T...>>:
	public ScatterHierarchy<TypeList<H>>,
	public ScatterHierarchy<TypeList<T...>> 
{
public:
    using Left = ScatterHierarchy<TypeList<H>>;
    using Right = ScatterHierarchy<TypeList<T...>>;
};

template <typename H>
class ScatterHierarchy<TypeList<H>>:
	public H
{
public:
    using Left = H;
};

template <>
class ScatterHierarchy<EmptyList> {};