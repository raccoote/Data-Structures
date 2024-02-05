#ifndef SortedArray_h
#define SortedArray_h
#include "UnsortedArray.h"
#include <iostream>
#include<string.h>
using namespace std;


class SortedArray : public UnsortedArray
{
  public:
      // uses remove, constructor and destructor functions from superclass (UnsortedArray)
      void insert(string); //check if string already exists in array, otherwise add string to array alphabetically
      bool searchForInsertion(string, int&) const; // find position to insert an item using binary search, returns false if the word doesnt exist yet
      int search(string) const; // simple binary seach, returns index or -1 (if argument not found)
};

//operators
ostream &operator<<(ostream &, const SortedArray &); // prints basic info about the array, like type (SortedArray) and size (total words stored)

#endif
