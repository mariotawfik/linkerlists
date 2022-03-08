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
        ListOfNumbers* previousTemp = this;
        ListOfNumbers* current = previousTemp->next;
        ListOfNumbers* temp = current->next;
        ListOfNumbers* temp2 = temp->next;
        int i= 0;
        while(current != NULL){
            current = current->next;
            i++;
        }
        current = previousTemp->next;
        for(int k= 0; k < i;k++){
            for(int p = 0; p < i-1; p++){
                if(current->next != NULL){
                    if(current->number >= temp->number){
                        
                        temp->next = current;
                        current->next = temp2;
                        previousTemp->next = temp;
                    }
                    previousTemp = previousTemp->next;
                    current = previousTemp->next;
                    temp = current->next;
                }
            }
            previousTemp = this;
            current = previousTemp->next;
            temp = current->next;
        }

    return this;
}

