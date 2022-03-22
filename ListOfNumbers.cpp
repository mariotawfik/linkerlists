//
//  ListOfNumbers.cpp
//  LinkedLists
//
#include "ListOfNumbers.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

ListOfNumbers::ListOfNumbers(){
    number = 0;
    next = NULL;
    };

ListOfNumbers::ListOfNumbers(int v){
    SetValue(v);
    next = NULL;
    };

ListOfNumbers::~ListOfNumbers(){
    while(next != NULL){
        delete next;
        }
    };

void ListOfNumbers::PrintItem(){
    cout << number << "  ::::Address: " << this << "  :::::Next: " << next << " :::::Sentinel Element: " << getSentinel(this)<<endl;
    };

void ListOfNumbers::PrintPTR(ListOfNumbers* p){
    if(p != NULL){
    cout << p->number << "  ::::Address: " << p << "  :::::Next: "<< p->next<< endl;
    }else{
        this->PrintPTRNULL(p);
        }
    };

void ListOfNumbers::PrintPTRNULL(ListOfNumbers* p){
    if(p == NULL){
        cout << "--   ::::Address: " << p << endl;
    }else{
        this->PrintPTR(p);
        }
    };

void ListOfNumbers::PrintList(){
    ListOfNumbers* current = this;
        while(current != NULL){
            current->PrintItem();
            current = current->next;
        }
    };

void ListOfNumbers::AddObject(int n){
    ListOfNumbers* temp;
    temp = new ListOfNumbers(n);
    ListOfNumbers* current;
    current = this;
    current = ChangeCurrent(current);
    current->next = temp;
    };

int ListOfNumbers::AskValue(){
    int temp;
    cout << "Please enter a new number" << endl << endl;
    cin >> temp;
    return temp;
    };

void ListOfNumbers::NewLON(){
    int temp;
    temp = AskValue();
    intAddR(temp);
    };

ListOfNumbers* ListOfNumbers::ChangeCurrent(ListOfNumbers* currentPTR){
      
    while(currentPTR->next != NULL){
        currentPTR = currentPTR->next;
        }
    
    return currentPTR;
    };

void ListOfNumbers::SetNext(ListOfNumbers* n){
    next = n;
    };

void ListOfNumbers::SetValue(int v){
    if(sentinel == false){
        number = v;
        }
    };

void ListOfNumbers::PtrAddR(ListOfNumbers* p){
    if(next == NULL){
        next = p;
    }else{
        next->PtrAddR(p);
        }
    };

void ListOfNumbers::intAddR(int v){
    
    ListOfNumbers *temp = new ListOfNumbers(v);
    PtrAddR(temp);
    };

ListOfNumbers * ListOfNumbers::find (int Value){
    ListOfNumbers* current = this;
        if(Value == number){
            return current;
        }else{
            while(current->next != NULL){
                current = current->next;
                if(Value == current->number){
                    return current;
                    }
                }
            return NULL;
        }
    };

ListOfNumbers* ListOfNumbers::findR (int Value){
    if(Value == number){
        return this;
        }else{
            if(next != NULL){
                return next->findR(Value);
            }else{
                return NULL;
                }
        }
    };

void ListOfNumbers::findAllR (int Value){
    ListOfNumbers* current = this;
    int i = 0;
    while(current != NULL){
        if(Value == current->number){
            current->PrintItem();
            i++;
            }
        current = current->next;
        }
    cout << "Total " << Value <<"'s found is: " << i << endl;
    }

void ListOfNumbers::findR_Print(int Value){
    ListOfNumbers* temp;
    temp = findR(Value);
    PrintPTR(temp);
    };

ListOfNumbers* ListOfNumbers::findPrevious (ListOfNumbers* p){
    if(this->next != p){
        if(this->next != NULL){
            return next->findPrevious(p);
        }else{
            return NULL;
            }
        }
    return this;
    }

ListOfNumbers* ListOfNumbers::Remove (int Value){
    ListOfNumbers* temp;
    ListOfNumbers* tempNext;
    ListOfNumbers* previous;
    temp = findR(Value);
    tempNext = temp->next;
    previous = findPrevious(temp);
    if(temp->sentinel == true){
        temp = temp->next;
        while(temp != NULL){
            while(temp->number != Value){
                temp = temp->next;
            }
            temp->next = NULL;
            tempNext = temp;
            delete tempNext;
            temp = NULL;
        }
        return NULL;
    }else{
        temp->next = NULL;
        delete temp;
        previous->next = tempNext;
        return previous->next;
        }
    }
    
void ListOfNumbers::setSentinel(){
    ListOfNumbers* current = this;
    while(current != NULL){
        if(findPrevious(current) == NULL){
            current->sentinel = true;
        }else{
            current->sentinel = false;
        }
        current = current->next;
    }
}
    
bool ListOfNumbers::getSentinel(ListOfNumbers* p){
    return p->sentinel;
    }

    ListOfNumbers* ListOfNumbers::sortList(){
        ListOfNumbers* current = this->next;
        ListOfNumbers* currentPrevious = this;
        ListOfNumbers* currentNext = NULL;
        ListOfNumbers* minimumNext = NULL;
        ListOfNumbers* minimum = NULL;
        ListOfNumbers* minimumPrevious = NULL;
        int i = 0;
        while(current != NULL){
            currentNext = current->next;
            i++;
            minimum = current->findMinimum();
            minimumPrevious = findPrevious(minimum);
            minimumNext = minimum->next;
            currentPrevious = findPrevious(current);
            if(minimumPrevious == current){
                currentPrevious->next = minimum;
                minimum->next = current;
                current->next = minimumNext;
                current = minimum->next;
            }else{
                currentPrevious->next = minimum;
                minimumPrevious->next = current;
                current->next = minimumNext;
                minimum->next = currentNext;
                current = minimum->next;
            }
        }
        return this;
    }

ListOfNumbers* ListOfNumbers::findMinimum(){
    ListOfNumbers* current = this->next;
    ListOfNumbers* minimum = this;
    while(current != NULL){
        if(minimum->number >= current->number){
            minimum = current;
        }
        current = current->next;
    }
    return minimum;
}

int* ListOfNumbers::randArray(int num){
    int* arr = new int(num);
    srand(time(NULL));
    for(int i = 0; i < num; i++){
        arr[i] = rand()%10000;
    }
    return arr;
}

ListOfNumbers* ListOfNumbers::randList(int* arr, int num){
    ListOfNumbers* a = new ListOfNumbers(INT_MAX-1);
    for(int i = 0; i < num; i++){
        a->intAddR(arr[i]);
    }
    a->setSentinel();
    return a;
}

void ListOfNumbers::arrayBubbleSort(int* arr, int num){
    int* temp = new int;
    for(int i= 0; i < num; i++){
        for(int j = 0; j < num; j++){
            if(arr[j] > arr[i]){
                *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = *temp;
            }
        }
    }
}

void ListOfNumbers::sortingTime(int num){
    int* array = randArray(num);
    ListOfNumbers* list = randList(array, num);
    clock_t start, end;
    start = clock();
    arrayBubbleSort(array, num);
    end = clock();
    double arrayTime = (double)(end-start)/CLOCKS_PER_SEC;
    start = clock();
    list->sortList();
    end = clock();
    double listTime = (double)(end-start)/CLOCKS_PER_SEC;
    cout << "Array sorting time: " << arrayTime << endl;
    cout<< "List sorting time: " << listTime << endl;
    if(arrayTime > listTime){
        cout << "Linked List sorting takes less time by a margin of " << arrayTime-listTime << " seconds" << endl;
    }else{
        if( arrayTime != listTime){
            cout << "Array sorting takes less time by a margin of " << listTime-arrayTime << " seconds" << endl;
        }else{
            cout << "Array and Linked list sorting time are the same at a time of " << listTime << " seconds" << endl;
        }
    }
}

void ListOfNumbers::elementsOfArrayAndList(int* arr, ListOfNumbers* list, int num){
    cout << endl << endl;
    for(int i = 0; i < num; i++){
        cout << arr[i] << endl;
    }
    cout << endl << endl;
    list->PrintList();
    cout << endl << endl;
}

