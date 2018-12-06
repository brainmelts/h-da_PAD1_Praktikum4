#pragma once

#include <algorithm>

template<typename T>
size_t partition(T& container, size_t first, size_t last) {
    auto& pivot = container[last];
    size_t left = first;
    size_t right = last - 1;

    while (left < right) {
        while (container[left] < pivot && left < last - 1) ++left;
        while (container[right] >= pivot && right > first) --right;
        if (left < right) std::swap(container[left], container[right]);
    }

    if (container[left] >= pivot) swap(container[left], pivot);

    return left;
}