// QuickSort
// Autor: Suayb Yurdakul
// Datum: 2018-12-06

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
using namespace std;
#include "quickSort.h"
#include "partition.h"
#include "lessEqualSorted.h"

string boolToString(bool b) {
    return b ? "true" : "false";
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    array<int, 1000> numbers = { }; for (unsigned int i = 0; i < numbers.size(); i++) numbers[i] = rand();
    vector<string> words = { "Tiger", "Zebra", "Affe", "Kamel", "Esel" };

    cout << "\n\nQuicksort Array\n";
    for (unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << "\t";
    quickSort(numbers, 0, (numbers.size() - 1));
    cout << "\n\n";
    for (unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << "\t";
    cout << "\nAufsteigend sortiert? " << boolToString(lessEqualSorted(numbers));
    cin.ignore();

    cout << "\n\nQuicksort Vector\n";
    for (unsigned int i = 0; i < words.size(); i++) std::cout << words[i] << "\t";
    quickSort(words, 0, (words.size() - 1));
    cout << "\n\n";
    for (unsigned int i = 0; i < words.size(); i++) cout << words[i] << "\t";
    cout << "\nAufsteigend sortiert? " << boolToString(lessEqualSorted(words));
    cin.ignore();

    return 0;
}