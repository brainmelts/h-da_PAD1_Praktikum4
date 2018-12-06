#pragma once

template<class T>
void bubbleSort(T& container) {
    int n = container.size();

    for (size_t i = 0; i < (n - 1); i++) {
        for (size_t j = (i + 1); j < n; j++) {
            if (container[i] > container[j]) {
                //Swap elements
                auto element = container[i];
                container[i] = container[j];
                container[j] = element;
            }
        }
    }
}