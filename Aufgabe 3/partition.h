#pragma once

#include <algorithm>
#include "partition.h"

template<typename T>
void quickSort(T& container, size_t first, size_t last) {
    if (first < last) {
        size_t curLocation = partition(container, first, last);
        quickSort(container, first, curLocation);
        quickSort(container, curLocation + 1, last);
    }
}