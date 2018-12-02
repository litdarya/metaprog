#pragma once

template<int  n>
constexpr int fibonacci() {
    return fibonacci<n - 1>() + fibonacci<n - 2>();
}

template<>
constexpr int fibonacci<1>() {
    return 1;
}

template<>
constexpr int fibonacci<0>() {
    return 0;
}