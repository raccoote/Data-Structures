#include "UnsortedArray.h"
#include <iostream>
#include <string>
using namespace std;

UnsortedArray::UnsortedArray()
{
    //initiliazation stuff
    size = 0;
    count = new int[MAX_SIZE];
    Array = new string[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        count[i] = 1;
        Array[i] = '.';
    }
}

UnsortedArray::~UnsortedArray()
{
    delete [] count;
    delete [] Array;
}
//getters
int UnsortedArray::getSize() const
{
    return size;
}

int UnsortedArray::getCount(int i) const
{
    if(i == -1) // sometimes search functions can return -1 (item not found), so we are more lenient with the user here and we return 0, so the word appears 0 times
    {
        return 0;
    }
    else if(i < 0) // out of bounds, so we warn the user because there are no negative indexes in the array
    {
        cout << "getCount error: out of bounds" << endl;
        return -1;
    }
    else //
    {
        return count[i];
    }
}

string UnsortedArray::getWord(int i) const
{
    if(i<0) // out of bounds
    {
        cout << "getWord error: out of bounds" << endl; // we warn the user because there are no negative indexes in the array
        return Array[i*(-1)];
    }
    return Array[i];
}

//other
void UnsortedArray::print(int n) const  // print the first n word of the array with their counts
{
    for (int i = 0;i < n;i++)
    {
        cout << Array[i] << " -> " << count[i] << endl;
    }
}

int UnsortedArray::search(string target) const // performs a basic linear search and returns count
{
    for (int i = 0;i < size;i++)
    {
        if(target == Array[i]) // if word is found
        {
            return count[i]; // return count (times appeared)
        }
    }
    return 0; // if word is not found we return 0 (0 appearances in text)
}

int UnsortedArray::searchPos(string target) const // performs a basic linear search and returns index of word
{
    for (int i = 0;i < size;i++)
    {
        if(target == Array[i]) // if word is found
        {
            return i;  // return index
        }
    }
    return -1; // if not found, return -1
}
void UnsortedArray::insert(string str)
{
    int pos = searchPos(str); // search for word
    if (pos == -1) // if word is not found
    {
        Array[size++] = str; // add new word in the end of the Array
    }
    else // if word is found
    {
        count[pos]++; // we increment the count by one
    }
}

bool UnsortedArray::remove(string str)
{
    int pos = searchPos(str); // find the pos
    if (pos == -1) // if not found
    {
        return false; // removing cannot be performed
    }
    for (int i = pos; i < size - 1; i++)  // move all the words to the left
    {
        Array[i] = Array[i + 1];
        count[i] = count[i + 1];
    }
    return true; // removing was successfull

}


//operators
ostream &operator<<(ostream &o, const UnsortedArray &a)
{
    o << "UnsortedArray with " << a.getSize() <<" unique words";
    return o;

}
