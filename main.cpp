//
//  main.cpp
//  LinkedLists
//
#include <iostream>
#include <limits>
#include "ListOfNumbers.hpp"
using namespace std;

int main(){
    ListOfNumbers *a,*b,*c;
    a = new ListOfNumbers(INT_MAX);
    b = new ListOfNumbers(5);
    c = new ListOfNumbers(-24);
    a->SetNext(b);
    b->SetNext(c);
    cout << "Values : " << endl;
    a->PrintItem();
    b->PrintItem();
    c->PrintItem();
    cout << "List 1 : " << endl ;
    a->PrintList();
    cout << endl << endl << endl << "List 2 : " << endl;
    c->PrintList();
    a->NewLON();
    a->NewLON();
    a->NewLON();
    a->NewLON();
    a->setSentinel();
    a->PrintList();
    cout<<endl<<endl;
    ListOfNumbers* d = a->sortList();
    d->PrintList();

};
