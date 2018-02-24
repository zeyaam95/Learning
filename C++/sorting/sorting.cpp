//
// Created by Zeyaam Shahid on 1/2/18.
//

#include "sorting.h"
#include <vector>
#include <iostream>


void sorting::swap (int * first, int * second) {
    int * temp = first;
    first = second;
    second = temp;
}

std::vector <int> sorting::bubbleSort(std::vector <int> numbers) {
    bool swapped;
    for (int i=0; i < numbers.size() - 1; i++) {
        swapped = false;
        for (int j=0; j < numbers.size() - i - 1; j++) {
            if (numbers[j] > numbers[j+1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
                swapped = true;
            }
        }
        if (swapped == false) break;
    }
    return numbers;
}

void sorting::selectionSort(std::vector <int> numbers) {
    int outer, inner, minimum;
    for (outer = 0; outer<numbers.size()-1; outer++) {
        minimum = outer;
        for (inner = outer+1; inner<numbers.size(); inner++) {
            if (numbers[outer] < numbers[minimum]) minimum = inner;
        }
        swap(&numbers[minimum], &numbers[outer]);
    }
}
