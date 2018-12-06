// BubbleSort und SelectionSort
// Autor: Suayb Yurdakul
// Datum: 2018-12-06

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <array>
using namespace std;
#include "bubbleSort.h"
#include "selectionSort.h"
#include "lessEqualSorted.h"

string boolToString(bool b) {
    return b ? "true" : "false";
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    cout << "Programm zum Sortieren von Containern.";

    array<int, 100> numbers = { }; for (unsigned int i = 0; i < numbers.size(); i++) numbers[i] = rand();
    vector<string> words = { "Tiger", "Zebra", "Affe", "Kamel", "Esel" };

    cout << "\n\n1.0. Bubblesort Array\n";
    for (unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << "\t";
    bubbleSort(numbers);
    cout << "\n\n";
    for (unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << "\t";
    cout << "\nAufsteigend sortiert? " << boolToString(lessEqualSorted(numbers));
    cin.ignore();

    cout << "\n\n1.1. Bubblesort Vector\n";
    for (unsigned int i = 0; i < words.size(); i++) std::cout << words[i] << "\t";
    bubbleSort(words);
    cout << "\n\n";
    for (unsigned int i = 0; i < words.size(); i++) cout << words[i] << "\t";
    cout << "\nAufsteigend sortiert? " << boolToString(lessEqualSorted(words));
    cin.ignore();


    for (unsigned int i = 0; i < numbers.size(); i++) numbers[i] = rand();
    words = { "Vogel", "Fuchs", "Baer", "Otter", "Uhu" };

    cout << "\n\n2.0. Selectionsort Array\n";
    for (unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << "\t";
    selectionSort(numbers);
    cout << "\n\n";
    for (unsigned int i = 0; i < numbers.size(); i++) cout << numbers[i] << "\t";
    cout << "\nAufsteigend sortiert? " << boolToString(lessEqualSorted(numbers));
    cin.ignore();

    cout << "\n\n2.1. Selectionsort Vector\n";
    for (unsigned int i = 0; i < words.size(); i++) std::cout << words[i] << "\t";
    selectionSort(words);
    cout << "\n\n";
    for (unsigned int i = 0; i < words.size(); i++) cout << words[i] << "\t";
    cout << "\nAufsteigend sortiert? " << boolToString(lessEqualSorted(words));
    cin.ignore();

    return 0;
}