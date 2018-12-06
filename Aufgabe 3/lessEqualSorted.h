#pragma once

template<class T>
bool lessEqualSorted(T& container) {
    int n = container.size() - 1;

    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            if (container[i] > container[j]) {
                return false;
            }
        }
    }

    return true;
}