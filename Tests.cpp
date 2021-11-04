#include <gtest/gtest.h>
#include "DinamicArray.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Sorts.h"
#include <cmath>

int arr[] = {1, 4, 3, 2};
int *pointer = arr;

template <typename T>
int cmp(T a, T b){
    if(a>b)
        return 1;
    else return 0;
}

TEST(ArraySequence, Get) {
    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    EXPECT_EQ(seq.Get(0), 1);
    EXPECT_THROW(seq.Get(-1), out_of_range);
}

TEST(ArraySequence, GetSize) {
    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    EXPECT_EQ(seq.GetSize(), 4);
}

TEST(ArraySequence, Append) {
    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    seq.Append(12);
    EXPECT_EQ(seq.Get(4), 12);
}

TEST(ArraySequence, Prepend) {
    DynamicArray<int> array = DynamicArray<int>(pointer, 4);
    ArraySequence<int> seq = ArraySequence<int>(&array);
    seq.Prepend(12);
    EXPECT_EQ(seq.Get(0), 12);
}

TEST(ListSequence, Get) {
    LinkedList<int> array = LinkedList<int>(pointer, 4);
    ListSequence<int> seq = ListSequence<int>(&array);
    EXPECT_EQ(seq.Get(0), 1);
    EXPECT_THROW(seq.Get(-1), out_of_range);
}

TEST(ListSequence, GetSize) {
    LinkedList<int> array = LinkedList<int>(pointer, 4);
    ListSequence<int> seq = ListSequence<int>(&array);
    EXPECT_EQ(seq.GetSize(), 4);
}

TEST(ListSequence, Append) {
    LinkedList<int> array = LinkedList<int>(pointer, 4);
    ListSequence<int> seq = ListSequence<int>(&array);
    seq.Append(12);
    EXPECT_EQ(seq.Get(4), 12);
}

TEST(ListSequence, Prepend) {
    LinkedList<int> array = LinkedList<int>(pointer, 4);
    ListSequence<int> seq = ListSequence<int>(&array);
    seq.Prepend(12);
    EXPECT_EQ(seq.Get(0), 12);
}

TEST(BubbleSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    Sorts<int>::BubbleSort(&array, cmp);
    EXPECT_EQ(array.Get(0), 1);
    EXPECT_EQ(array.Get(1), 2);
    EXPECT_EQ(array.Get(2), 3);
    EXPECT_EQ(array.Get(3), 4);
}

TEST(BubbleSort, LinkedListSequence){
    ListSequence<int> array(arr, 4);
    Sorts<int>::BubbleSort(&array, cmp);
    EXPECT_EQ(array.Get(0), 1);
    EXPECT_EQ(array.Get(1), 2);
    EXPECT_EQ(array.Get(2), 3);
    EXPECT_EQ(array.Get(3), 4);
}

TEST(BubbleShakerSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    Sorts<int>::BubbleShakerSort(&array, cmp);
    EXPECT_EQ(array.Get(0), 1);
    EXPECT_EQ(array.Get(1), 2);
    EXPECT_EQ(array.Get(2), 3);
    EXPECT_EQ(array.Get(3), 4);
}

TEST(BubbleShakerSort, LinkedListSequence){
    ListSequence<int> array(arr, 4);
    Sorts<int>::BubbleShakerSort(&array, cmp);
    EXPECT_EQ(array.Get(0), 1);
    EXPECT_EQ(array.Get(1), 2);
    EXPECT_EQ(array.Get(2), 3);
    EXPECT_EQ(array.Get(3), 4);
}

TEST(InsertionSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    Sorts<int>::InsertionSort(&array, cmp);
    EXPECT_EQ(array.Get(0), 1);
    EXPECT_EQ(array.Get(1), 2);
    EXPECT_EQ(array.Get(2), 3);
    EXPECT_EQ(array.Get(3), 4);
}

TEST(InsertionSort, LinkedListSequence){
    ListSequence<int> array(arr, 4);
    Sorts<int>::InsertionSort(&array, cmp);
    EXPECT_EQ(array.Get(0), 1);
    EXPECT_EQ(array.Get(1), 2);
    EXPECT_EQ(array.Get(2), 3);
    EXPECT_EQ(array.Get(3), 4);
}

TEST(SelectionSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    Sorts<int>::SelectionSort(&array, cmp);
    EXPECT_EQ(array.Get(0), 1);
    EXPECT_EQ(array.Get(1), 2);
    EXPECT_EQ(array.Get(2), 3);
    EXPECT_EQ(array.Get(3), 4);
}

TEST(SelectionSort, LinkedListSequence){
    ListSequence<int> array(arr, 4);
    Sorts<int>::SelectionSort(&array, cmp);
    EXPECT_EQ(array.Get(0), 1);
    EXPECT_EQ(array.Get(1), 2);
    EXPECT_EQ(array.Get(2), 3);
    EXPECT_EQ(array.Get(3), 4);
}

TEST(QuickSort, ArraySequence){
    ArraySequence<int> array(arr, 4);
    Sorts<int>::QuickSort(&array, 0, array.GetSize()-1, cmp);
    EXPECT_EQ(array.Get(0), 1);
    EXPECT_EQ(array.Get(1), 2);
    EXPECT_EQ(array.Get(2), 3);
    EXPECT_EQ(array.Get(3), 4);
}