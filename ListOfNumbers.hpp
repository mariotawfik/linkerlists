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
public:
    ListOfNumbers();
    ListOfNumbers(int v);

    // Uses IOSTREAM to ask for a value *Uses the SetValue function*
    void AskValue();
    void SetValue(int v);
    void SetNext(ListOfNumbers *n);

    // Prints a single item’s number
    void PrintItem();

    // Prints the whole list
    void PrintList();

    // Adds a list of number object at the end
    void AddObject(int n);

    // Adds a list of number object at the end (Recursive)
    void intAddR();

    // Creates a new ListOfNumbers object from an inputed number
    void NewLON();

    // Changes the current pointer of the current object to the next object
    ListOfNumbers* ChangeCurrent(ListOfNumbers* current);
};

#endif /* ListOfNumbers_hpp */
