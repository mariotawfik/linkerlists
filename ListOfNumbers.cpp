//
//  ListOfNumbers.cpp
//  LinkedLists
//
#include "ListOfNumbers.hpp"
#include <iostream>
using namespace std;

ListOfNumbers::ListOfNumbers(){
    number = 0;
    next = NULL;
}

ListOfNumbers::ListOfNumbers(int v){
    SetValue(v);
    next = NULL;
};

void ListOfNumbers::PrintItem(){
    cout << number << "  ::::Address:" << this <<endl;
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
    ListOfNumbers* current = this;
    current = ChangeCurrent(current);
    current->SetNext(temp);
};

void ListOfNumbers::AskValue(){
    int temp;
    cout << "Please enter a new number" << endl;
    cin >> temp;
    SetValue(temp);
};

void ListOfNumbers::NewLON(){
    AskValue();
    AddObject(number);
};

ListOfNumbers* ListOfNumbers::ChangeCurrent(ListOfNumbers* current){
        while(current != NULL){
            current = current->next;
        }

    return current;
}

void ListOfNumbers::SetNext(ListOfNumbers* n){
    next = n;
};

void ListOfNumbers::SetValue(int v){
    number = v;
};

void ListOfNumbers::intAddR(){

    if(next == NULL){
    }

};
