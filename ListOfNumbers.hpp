//
//  ListOfNumbers.hpp
//  LinkedLists
//

#ifndef ListOfNumbers_hpp
#define ListOfNumbers_hpp

class ListOfNumbers {
private:
    int number;
    ListOfNumbers *next;
    bool sentinel;
public:
    ListOfNumbers();
    ListOfNumbers(int v);
    ~ListOfNumbers();

    // Uses IOSTREAM to ask for a value *Uses the SetValue function*
    int AskValue();
    void SetValue(int v);
    void SetNext(ListOfNumbers *n);

    // Prints a single item’s number
    void PrintItem();
    
    ListOfNumbers* sortList();
    
    void PrintPTR(ListOfNumbers* p);
    
    void PrintPTRNULL(ListOfNumbers* p);

    // Prints the whole list
    void PrintList();

    // Adds a list of number object at the end
    void AddObject(int n);

    // Adds a list of number object at the end (Recursive)
    void intAddR(int v);
    
    void PtrAddR(ListOfNumbers* p);

    // Creates a new ListOfNumbers object from an inputed number
    void NewLON();
    
    void findR_Print(int Value);

    // Changes the current pointer of the current object to the next object
    ListOfNumbers* ChangeCurrent(ListOfNumbers* current);
    
    ListOfNumbers* find (int Value);
    
    ListOfNumbers* findR (int Value);
    
    void findAllR (int Value);
    
    ListOfNumbers* Remove (int Value);
    
    ListOfNumbers* findPrevious (ListOfNumbers* p);
    
    void setSentinel();
    
    bool getSentinel(ListOfNumbers* p);
    
    ListOfNumbers* findMinimum();
};

#endif /* ListOfNumbers_hpp */
