#include "menu.h"
#include <vector>
#include <stdexcept>

const int constMax = 100000;
int cmp_int(int a, int b){
    if(a>b)
        return 1;
    else return 0;
}
int cmp_double(double a, double b){
    if(a>b)
        return 1;
    else return 0;
}

int СhooseSort(){
    int sort;
    cout << "What sort do you want to use?: \n"
         << "\t0: Exit\n"
         << "\t1: Bubble Sort\n"
         << "\t2: Bubble Shaker Sort\n"
         << "\t3: Insertion Sort\n"
         << "\t4: Selection Sort\n"
         << "\t5: Quick Sort\n"
         << "Enter a number: ";
    cin >> sort;
    cout << endl;
    /*if (sort < 0 || sort > 5){
        throw invalid_argument("Incorrect number");
    }*/
    return sort;
}

int ChooseDataType(){
    int dt;
    cout<<"What data type do you want to work with?: \n"
        <<"\t0: Exit\n"
        <<"\t1: int\n"
        <<"\t2: double\n"
        << "Enter a number: ";
    cin >> dt;
    cout << endl;
    /*if (dt < 0 || dt > 2){
        throw invalid_argument("Incorrect number");
    }*/
    return dt;
}


int ChooseOption(){
    int option;
    cout<< "Choose an option:\n"
        << "\t0: Exit\n"
        << "\t1: Sort Sequence\n"
        << "\t2: Compare Sorts\n"
        << "Enter a number: ";
    cin >> option;
    cout << endl;
    /*if (option < 0 || option > 2){
        throw invalid_argument("Incorrect number");
    }*/
    return option;
}

int ChooseDataStruct(){
    int ds;
    cout << "What data structure do you want to work with?: \n"
         << "\t0: Exit\n"
         << "\t1: Array Sequence\n"
         << "\t2: Linked List Sequence\n"
         << "Enter a number: ";
    cin >> ds;
    cout << endl;
    /*if (ds < 0 || ds > 2){
        throw invalid_argument("Incorrect number");
    }*/
    return ds;
}

template <typename T>
void PrintSequence(Sequence<T>* seq) {
    for (int i=0; i<seq->GetSize(); i++) {
        cout << seq->Get(i);
        cout << " ";
    }
    cout<<endl;
}

///ArraySequence
/*
template <typename T>
void PrintArraySequence(ArraySequence<T>* seq) {
    for (int i=0; i<seq->GetSize(); i++) {
        cout << seq->Get(i);
        cout << " ";
    }
    cout<<endl;
}*/

template <typename T>
ArraySequence<T>* InputArraySequence(){
    try {
        int dim;
        cout << "\tEnter a dimension of sequence: ";
        cin >> dim;
        cout << endl;
        if (dim < 0) {
            throw "Incorrect number";
        }
        auto *seq = new ArraySequence<T>(dim);
        cout << "\tEnter elements of sequence: ";
        T element;
        for (int i = 0; i < dim; i++) {
            cin >> element;
            seq->Set(i, element);
        }
        return seq;
    }
    catch(const char* exception) {
        cout << "Error:" << exception << endl;
    }
}
template <typename T>
void CompareSortsASInt(ArraySequence<T>* seq){
    cout << "\tBubble Sorts: " << getSortTimeAS(1, seq, cmp_int) << endl;
    cout << "\tBubble Shaker Sort: " << getSortTimeAS(2, seq, cmp_int) << endl;
    cout << "\tInsertion Sort: " << getSortTimeAS(3, seq, cmp_int) << endl;
    cout << "\tSelection Sort: " << getSortTimeAS(4, seq, cmp_int) << endl;
    cout << "\tQuick Sort: " << getSortTimeAS(5, seq, cmp_int) << endl;
}

template <typename T>
void CompareSortsASDouble(ArraySequence<T>* seq){
    cout << "\tBubble Sorts: " << getSortTimeAS(1, seq, cmp_double) << endl;
    cout << "\tBubble Shaker Sort: " << getSortTimeAS(2, seq, cmp_double) << endl;
    cout << "\tInsertion Sort: " << getSortTimeAS(3, seq, cmp_double) << endl;
    cout << "\tSelection Sort: " << getSortTimeAS(4, seq, cmp_double) << endl;
    cout << "\tQuick Sort: " << getSortTimeAS(5, seq, cmp_double) << endl;
}

void MenuArraySequence(){
    try{
        while (true) {
            int type = ChooseDataType(); // 1-int, 2-double
            if (type == 0) {
                break;
            } else if (type == 1) {
                while (true) {
                    int option = ChooseOption(); // 1-sort, 2-compare
                    if (option == 0) {
                        break;
                    } else if (option == 1) {
                        cout << "Enter sequence: \n";
                        auto *seq = InputArraySequence<int>();
                        bool flag = true;
                        while (flag) {
                            cout << "Print entered sequence?\n\t1 - Yes\n\t0 - No" << endl;
                            int buf;
                            cin >> buf;
                            if (buf == 1) {
                                cout << "Entered sequence: ";
                                PrintSequence(seq);
                            } else if (buf != 0)
                                throw "Incorrect number";
                            int sort = СhooseSort(); //1-bubble,2-bubble shaker, 3-insertion, 4-selection
                            if (sort < 0 || sort > 5) {
                                throw "Incorrect number";
                            } else if (sort == 0) {
                                break;
                            } else {
                                cout << "Your sorted sequence: ";
                                if (sort == 1) {
                                    auto *newSeq = Sorts<int>::BubbleSortClone(seq, cmp_int);
                                    PrintSequence(newSeq);
                                    //Sorts<int>::BubbleSort(seq, cmp_int);
                                } else if (sort == 2) {
                                    auto *newSeq = Sorts<int>::BubbleShakerSortClone(seq, cmp_int);
                                    PrintSequence(newSeq);
                                    //Sorts<int>::BubbleShakerSort(seq, cmp_int);
                                } else if (sort == 3) {
                                    auto *newSeq = Sorts<int>::InsertionSortClone(seq, cmp_int);
                                    PrintSequence(newSeq);
                                    //Sorts<int>::InsertionSort(seq, cmp_int);
                                } else if (sort == 4) {
                                    auto *newSeq = Sorts<int>::SelectionSortClone(seq, cmp_int);
                                    PrintSequence(newSeq);
                                    //Sorts<int>::SelectionSort(seq, cmp_int);
                                } else if (sort == 5) {
                                    auto *newSeq = Sorts<int>::QuickSortClone(seq, 0, seq->GetSize() - 1, cmp_int);
                                    PrintSequence(newSeq);
                                    //Sorts<int>::QuickSort(seq, 0, seq->GetSize()-1, cmp_int);
                                }
                            }
                            cout << "Do you want to continue working with this sequence?\n\t1 - Yes\n\t0 - No\n";
                            cin >> flag;
                        }
                    } else if (option == 2) {
                        int dim;
                        cout << "Enter dimension of random sequence: (0 - 100000)";
                        cin >> dim;
                        int randomSeq[constMax];
                        srand(time(NULL));
                        for (int i = 0; i < dim; i++) {
                            randomSeq[i] = rand();
                        }
                        ArraySequence<int> seq(randomSeq, dim);
                        auto *pointer = new ArraySequence<int>(seq);
                        cout << "Sorting time in milliseconds:\n";
                        CompareSortsASInt(pointer);
                    }
                    else
                        throw "Incorrect number";

                }
            } else if (type == 2) {
                while (true) {
                    int option = ChooseOption(); // 1-sort, 2-compare
                    if (option == 0) {
                        break;
                    } else if (option == 1) {
                        cout << "Enter sequence: \n";
                        auto *seq = InputArraySequence<double>();
                        bool flag = true;
                        while (flag) {
                            cout << "Print entered sequence?\n\t1 - Yes\n\t0 - No" << endl;
                            int buf;
                            cin >> buf;
                            if (buf == 1) {
                                cout << "Entered sequence: ";
                                PrintSequence(seq);
                            } else if (buf != 0)
                                throw "Incorrect number";
                            int sort = СhooseSort(); //1-bubble,2-bubble shaker, 3-insertion, 4-selection
                            if (sort < 0 || sort > 5) {
                                throw "Incorrect number";
                            } else if (sort == 0) {
                                break;
                            } else {
                                cout << "Your sorted sequence: ";
                                if (sort == 1) {
                                    auto *newSeq = Sorts<double>::BubbleSortClone(seq, cmp_double);
                                    PrintSequence(newSeq);
                                } else if (sort == 2) {
                                    auto *newSeq = Sorts<double>::BubbleShakerSortClone(seq, cmp_double);
                                    PrintSequence(newSeq);
                                } else if (sort == 3) {
                                    auto *newSeq = Sorts<double>::InsertionSortClone(seq, cmp_double);
                                    PrintSequence(newSeq);
                                } else if (sort == 4) {
                                    auto *newSeq = Sorts<double>::SelectionSortClone(seq, cmp_double);
                                    PrintSequence(newSeq);
                                } else if (sort == 5) {
                                    auto *newSeq = Sorts<double>::QuickSortClone(seq, 0, seq->GetSize() - 1,
                                                                                 cmp_double);
                                    PrintSequence(newSeq);
                                } else {
                                    throw "Incorrect number";
                                }
                            }
                            cout << "Do you want to continue working with this sequence?\n\t1 - Yes\n\t0 - No\n";
                            cin >> flag;
                        }
                    } else if (option == 2) {
                        int dim;
                        cout << "Enter dimension of random sequence: ";
                        cin >> dim;
                        srand(time(NULL));
                        vector<double> randomSeq(dim);
                        for (int i = 0; i < dim; i++) {
                            randomSeq[i] = rand() / (double) RAND_MAX;
                        }
                        ArraySequence<double> seq(randomSeq, dim);
                        auto *pointer = new ArraySequence<double>(seq);
                        cout << "Sorting time in milliseconds:\n";
                        CompareSortsASDouble(pointer);
                    } else
                        throw "Incorrect number";
                }
            } else {
                throw "Incorrect number";
            }
        }
    }
    catch(const char* exception) {
        cout << "Error:" << exception << endl;
    }
}



///LinkedListSequence

/*template <typename T>
void PrintSequence(ListSequence<T>* seq) {
    for (int i=0; i<seq->GetSize(); i++) {
        cout << seq->Get(i);
        cout << " ";
    }
    cout<<endl;
}*/

template <typename T>
ListSequence<T>* InputLinkedListSequence(){
    try {
        int dim;
        cout << "\tEnter a dimension of sequence: ";
        cin >> dim;
        cout << endl;
        if (dim < 0) {
            throw "Incorrect number";
        }
        auto *seq = new ListSequence<T>();
        cout << "\tEnter elements of sequence: ";
        T element;
        for (int i = 0; i < dim; i++) {
            cin >> element;
            //cout << "\n(02)\n";
            seq->Append(element);
            //cout << "\n(03)\n";
        }
        return seq;
    }
    catch(const char* exception) {
        cout << "Error:" << exception << endl;
    }
}

template <typename T>
void CompareSortsLLSInt(ListSequence<T>* seq){
    cout << "\tBubble Sorts: " << getSortTimeLLS(1, seq, cmp_int) << endl;
    cout << "\tBubble Shaker Sort: " << getSortTimeLLS(2, seq, cmp_int) << endl;
    cout << "\tInsertion Sort: " << getSortTimeLLS(3, seq, cmp_int) << endl;
    cout << "\tSelection Sort: " << getSortTimeLLS(4, seq, cmp_int) << endl;
    cout << "\tQuick Sort: " << getSortTimeLLS(5, seq, cmp_int) << endl;
}

template <typename T>
void CompareSortsLLSDouble(ListSequence<T>* seq){
    cout << "\tBubble Sorts: " << getSortTimeLLS(1, seq, cmp_double) << endl;
    cout << "\tBubble Shaker Sort: " << getSortTimeLLS(2, seq, cmp_double) << endl;
    cout << "\tInsertion Sort: " << getSortTimeLLS(3, seq, cmp_double) << endl;
    cout << "\tSelection Sort: " << getSortTimeLLS(4, seq, cmp_double) << endl;
    cout << "\tQuick Sort: " << getSortTimeLLS(5, seq, cmp_double) << endl;
}

void MenuLinkedListSequence(){
    try {
        while (true) {
            int type = ChooseDataType(); // 1-int, 2-double
            if (type == 0) {
                break;
            }
            else if (type == 1) {
                while (true) {
                    int option = ChooseOption(); // 1-sort, 2-compare
                    if (option == 0) {
                        break;
                    }
                    else if (option == 1) {
                        cout << "Enter sequence: \n";
                        auto *seq = InputLinkedListSequence<int>();
                        bool flag = true;
                        while (flag) {
                            cout << "Print entered sequence?\n\t1 - Yes\n\t0 - No" << endl;
                            int buf;
                            cin >> buf;
                            if (buf == 1) {
                                cout << "Entered sequence: ";
                                PrintSequence(seq);
                            } else if (buf != 0)
                                throw "Incorrect number";
                            int sort = СhooseSort(); //1-bubble,2-bubble shaker, 3-insertion, 4-selection
                            if (sort < 0 || sort > 5) {
                                throw "Incorrect number";
                            }
                            else if (sort == 0) {
                                break;
                            }
                            else {
                                cout << "Your sorted sequence: ";
                                if (sort == 1) {
                                    auto *newSeq = Sorts<int>::BubbleSortClone(seq, cmp_int);
                                    PrintSequence(newSeq);
                                } else if (sort == 2) {
                                    auto *newSeq = Sorts<int>::BubbleShakerSortClone(seq, cmp_int);
                                    PrintSequence(newSeq);
                                } else if (sort == 3) {
                                    auto *newSeq = Sorts<int>::InsertionSortClone(seq, cmp_int);
                                    PrintSequence(newSeq);
                                } else if (sort == 4) {
                                    auto *newSeq = Sorts<int>::SelectionSortClone(seq, cmp_int);
                                    PrintSequence(newSeq);
                                } else if (sort == 5) {
                                    auto *newSeq = Sorts<int>::QuickSortClone(seq, 0, seq->GetSize() - 1, cmp_int);
                                    PrintSequence(newSeq);
                                }
                            }
                            cout << "Do you want to continue working with this sequence?\n\t1 - Yes\n\t0 - No\n";
                            cin >> flag;
                        }
                    }
                    else if (option == 2) {
                        int dim;
                        cout << "Enter dimension of random sequence (0 - 100000):\t";
                        cin >> dim;
                        int randomSeq[constMax];
                        srand(time(NULL));
                        for (int i = 0; i < dim; i++) {
                            randomSeq[i] = rand();
                        }
                        ListSequence<int> seq(randomSeq, dim);
                        auto *pointer = new ListSequence<int>(seq);
                        cout << "Sorting time in milliseconds:\n";
                        CompareSortsLLSInt(pointer);
                    }
                    else
                        throw "Incorrect number";
                }
            }
            else if (type == 2) {
                while (true) {
                    int option = ChooseOption(); // 1-sort, 2-compare
                    if (option == 0) {
                        break;
                    } else if (option == 1) {
                        cout << "Enter sequence: \n";
                        auto *seq = InputLinkedListSequence<double>();
                        bool flag = true;
                        while (flag) {
                            cout << "Print entered sequence?\n\t1 - Yes\n\t0 - No" << endl;
                            int buf;
                            cin >> buf;
                            if (buf == 1) {
                                cout << "Entered sequence: ";
                                PrintSequence(seq);
                            }
                            else if (buf != 0)
                                throw "Incorrect number";
                            int sort = СhooseSort(); //1-bubble,2-bubble shaker, 3-insertion, 4-selection
                            if (sort < 0 || sort > 5) {
                                throw "Incorrect number";
                            }
                            else if (sort == 0) {
                                break;
                            }
                            else {
                                cout << "Your sorted sequence: ";
                                if (sort == 1) {
                                    auto *newSeq = Sorts<double>::BubbleSortClone(seq, cmp_double);
                                    PrintSequence(newSeq);
                                } else if (sort == 2) {
                                    auto *newSeq = Sorts<double>::BubbleShakerSortClone(seq, cmp_double);
                                    PrintSequence(newSeq);
                                } else if (sort == 3) {
                                    auto *newSeq = Sorts<double>::InsertionSortClone(seq, cmp_double);
                                    PrintSequence(newSeq);
                                } else if (sort == 4) {
                                    auto *newSeq = Sorts<double>::SelectionSortClone(seq, cmp_double);
                                    PrintSequence(newSeq);
                                } else if (sort == 5) {
                                    auto *newSeq = Sorts<double>::QuickSortClone(seq, 0, seq->GetSize() - 1,
                                                                                 cmp_double);
                                    PrintSequence(newSeq);
                                }
                            }
                            cout << "Do you want to continue working with this sequence?\n\t1 - Yes\n\t0 - No\n";
                            cin >> flag;
                        }
                    }
                    else if (option == 2) {
                        int dim;
                        cout << "Enter dimension of random sequence: ";
                        cin >> dim;
                        vector<double> randomSeq(dim);
                        for (int i = 0; i < dim; i++) {
                            randomSeq[i] = rand() / (double) RAND_MAX;
                        }
                        ListSequence<double> seq(randomSeq, dim);
                        auto *pointer = new ListSequence<double>(seq);
                        cout << "Sorting time in milliseconds:\n";
                        CompareSortsLLSDouble(pointer);
                    }
                    else
                        throw "Incorrect number";
                }
            }
            else {
                throw "Incorrect number";
            }
        }
    }
    catch(const char* exception) {
        cout << "Error:" << exception << endl;
    }
}


int menu(){
    while(true){
        try{
            int dataStruct = ChooseDataStruct();
            if(dataStruct == 1){
                MenuArraySequence();
            }
            else if (dataStruct == 2){
                MenuLinkedListSequence();
            }
            else if (dataStruct == 0){
                break;
            }
            else{
                throw "Incorrect number";
            }
        }
        catch(const char* exception) {
            cout << "Error:" << exception << endl;
        }
    }
    return 0;
}