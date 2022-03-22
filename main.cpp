//
//  main.cpp
//  LinkedLists
//
#include <iostream>
#include <limits>
#include "ListOfNumbers.hpp"
using namespace std;

int main(){
    ListOfNumbers *a,*b,*c,*d;
    a = new ListOfNumbers(INT_MAX);
    b = new ListOfNumbers(24);
    c = new ListOfNumbers(-24);
    d = new ListOfNumbers(15);
    a->SetNext(b);
    b->SetNext(c);
    c->SetNext(d);
    cout << "Values : " << endl;
    a->PrintItem();
    b->PrintItem();
    c->PrintItem();
    cout << "List 1 : " << endl ;
    a->PrintList();
    cout << endl << endl << endl << "List 2 : " << endl;
    c->PrintList();
    a->setSentinel();
    a->PrintList();
    cout<<endl<<endl;
    ListOfNumbers* e = a->sortList();
    e->PrintList();
    a->sortingTime(20000);
};

 
