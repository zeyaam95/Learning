//
// Created by Zeyaam Shahid on 1/2/18.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H
#include <iostream>
#include <vector>


class sorting {
public:
    void swap (int * first, int * second);
    std::vector <int> bubbleSort(std::vector <int> numbers);
    void selectionSort(std::vector <int> numbers);
};


#endif //SORTING_SORTING_H
