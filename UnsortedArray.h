#ifndef UnsortedArray_h
#define UnsortedArray_h
#include <iostream>
#include <string>
using namespace std;
#define MAX_SIZE 1200000  // initial max size of the array, feel free to change this according to your needs


class UnsortedArray
{
  protected:
      string * Array; // stores the words
      int size;       // size of Array, basically the number of words in our file
      int * count;    // how many times each word appears
  public:
      UnsortedArray(); // basic constructor
      ~UnsortedArray(); // basic destructor

      //getters
      int getSize() const; // returns size
      int getCount(int) const; // returns count[i]
      string getWord(int) const; // returns Array[i]

      //main functions
      void insert(string); // search if string already exists in array, otherwise adds string to array in the last position
      int search(string) const; // linear seach, returns count of the string in the array
      int searchPos(string target) const; // linear seach, returns index or -1 (if argument not found)
      bool remove(string); // removes item from array and moves all items accordingly

      //other
      void print(int) const; // prints first (e.g. 100) array's elements, mostly for debugging purposes
};

//operators
ostream &operator<<(ostream &, const UnsortedArray &); // prints basic info about the array, like type (UnsortedArray) and size (total words saved)

#endif
