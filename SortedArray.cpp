#include "SortedArray.h"
#include <iostream>
#include <string.h>
using namespace std;

void SortedArray::insert(string str)  //check if string already exists in array, otherwise add string to array alphabetically
{
    int pos = 0;
    if (size == 0)
    {
        Array[pos] = str;
        size++;
    }
    else
    {
        if (searchForInsertion(str, pos)) // if word was found
        {
            count[pos]++; // we increment the count by one
        }
        else // if word is not found
        {
            for (int i = size++; i>=pos; i--) // move the items which are right to where our str will be inserted
            {
                Array[i + 1] = Array[i]; // one position to the right
                count[i + 1] = count[i]; // do the same for their count
            }
            Array[pos] = str; // str is saved to its postion
            count[pos] = 1;
        }
    }
}

int SortedArray::search(string target) const // simple binary seach, returns index or -1 (if argument not found)
{
    int L, R, pos;
    L = 0; // 'left' points to the first index of the array
    R = size; // 'right' points to the last index of the array
    while (L <= R) // while 'left' has 'right' to its right
    {
        pos = (L + R) / 2; // pos is at half of the two
        if (Array[pos].compare(target) < 0)
        {
            L = pos + 1; // move 'left' to the right
        }
        else if (Array[pos].compare(target) > 0)
        {
            R = pos - 1; // move 'right' to the left
        }
        else // if target is found
        {
            return count[pos]; // return count (times in array)
        }
    }
    return 0; // item is not found, so we return 0 (0 times in array)
}

//same implementation as above but with a few tweaks
bool SortedArray::searchForInsertion(string target, int &pos) const // find position to insert an item using binary search
{
    int L, R;
    L = 0;
    R = size;
    while (L <= R)
    {
        pos = (L + R) / 2;
        if (Array[pos].compare(target) < 0)
        {
            L = pos + 1;
        }
        else if (Array[pos].compare(target) > 0)
        {
            R = pos - 1;
        }
        else
        {
            return true; // word is already in array
        }
    }
    if(Array[pos].compare(target) < 0)
    {
        pos++;
    }
    if(pos > size) // oops xD i dont know but it works
    {
        pos = size;
    }
    return false; // word is not yet in array so some other function must insert it alphabetically
}


//operators
ostream &operator<<(ostream &o, const SortedArray &a)
{
    o << "SortedArray with " << a.getSize() <<" unique words";
    return o;

}
