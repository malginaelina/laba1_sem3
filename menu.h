//
// Created by User on 09.10.2021.
//
#ifndef LABA1SEM3_MENU_H
#define LABA1SEM3_MENU_H

#include<iostream>
#include "DinamicArray.h"
#include "Sorts.h"
#include "LinkedListSequence.h"
#include "LinkedList.h"
#include "ArraySequence.h"
#include "Sequence.h"
#include "Timing.h"
#include <ctime>

int cmp_int(int, int);
int cmp_double(double, double );

int ChooseDataStruct();
int ChooseOption();
int СhooseSort();
int ChooseDataType();
//int ChooseTwoCompareSorts();

template <typename T>
ArraySequence<T>* InputArraySequence();
int menu();
void MenuArraySequence();

#endif //LABA1SEM3_MENU_H
