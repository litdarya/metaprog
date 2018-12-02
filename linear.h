#pragma once

#include "typeList.h"

// Linear hierarchy

class Root {
public:
	virtual void Call(){};
};

template<int n, typename TypeList, template<class, class> class Unit>
class LinearHierarchy;

template<int n, typename U, typename ... T, template<class, class> class Unit>
class LinearHierarchy<n, TypeList<U, T ...>, Unit>:
public Unit<U, LinearHierarchy<n - 1, TypeList<T ...>, Unit>> {};

template<int n, template<class, class> class Unit>
class LinearHierarchy<n, EmptyList, Unit>:
public Unit<EmptyList, Root>{};

template<typename H, typename ...T, template<class, class> class Unit>
class LinearHierarchy<0, TypeList<H, T ...>, Unit>:
public Unit<EmptyList, Root>{};
