#ifndef LABA1SEM3_TIMING_H
#define LABA1SEM3_TIMING_H

#include <ctime>
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Sorts.h"
#include <cstdlib>
#include <chrono>

template <typename T>
unsigned long long getSortTimeAS(int index, ArraySequence<T>* arr, int (*cmp) (T,T)){
    if(index == 1){
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>:: BubbleSortClone(arr, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
    else if(index == 2){
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>:: BubbleShakerSortClone(arr, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
    else if(index == 3){
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>:: InsertionSortClone(arr, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
    else if (index == 4){
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>:: SelectionSortClone(arr, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
    else if(index == 5) {
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>::QuickSortClone(arr, 0, arr->GetSize() - 1, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
}

template <typename T>
unsigned long long getSortTimeLLS(int index, ListSequence<T>* arr, int (*cmp) (T,T)){
    if(index == 1){
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>:: BubbleSortClone(arr, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
    else if(index == 2){
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>:: BubbleShakerSortClone(arr, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
    else if(index == 3){
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>:: InsertionSortClone(arr, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
    else if (index == 4){
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>:: SelectionSortClone(arr, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
    else if(index == 5) {
        auto start = std::chrono::high_resolution_clock::now();
        Sorts<T>::QuickSortClone(arr, 0, arr->GetSize() - 1, cmp);
        auto finish = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
        return result / 1000000;
    }
}

#endif //LABA1SEM3_TIMING_H