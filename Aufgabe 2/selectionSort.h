#pragma once

template <class T>
void selectionSort(T& container) {
    int n = container.size();

    for (int i = 0; i < n; i++) {
        int j = i;

        for (int k = i + 1; k < n; k++) if (container[k] < container[j]) j = k;

        auto element = container[i];
        container[i] = container[j];
        container[j] = element;
    }
}