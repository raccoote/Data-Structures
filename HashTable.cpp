#include <iostream>
#include <fstream>
#include <cstring>
#include "HashTable.h"
using namespace std;

HashTable::HashTable()
{
  size = 0;
  Array=new hashtable[26];
}


int HashTable::search(const string &word) const
{
    return searchword(this->Array, word);
}

void HashTable::insert(const string &word)
{
    this->Array = insertword(this->Array, word);
}


HashTable::hashtable *HashTable::insertword(hashtable *Array, string str1)
{
  int k;
  k = str1[0] - 97;
  if(Array[k].times == 0)
  {
    Array[k].times = 1;
    Array[k].right = new hashtable;
    Array[k].str = str1;
    //cout << "new word " << str1 << endl;
    size++;
  }
  else if(str1.compare(Array[k].str)>0 || str1.compare(Array[k].str) < 0)
  {
      Array[k].right=insertword1(Array[k].right,str1);
  }
  else
  {
      Array[k].times++;
  }
  return Array;
}

HashTable::hashtable *HashTable::insertword1(hashtable *A, string str1)
{
  int k;
  k = (int) str1[0] - 97;
  if(A->times == 0)
  {
    A->times = 1;
    A->right = new hashtable;
    A->str = str1;
    size++;
    //cout << "new word " << str1 << endl;
  }
  else if(str1.compare(A->str) > 0 || str1.compare(A->str) < 0)
  {
      A->right = insertword1(A->right, str1);
  }
  else
  {
      A->times++;
  }
  return A;
}

int HashTable::searchword(hashtable *Array, string str1) const
{
  int k;
  k = str1[0] - 97;
  if(Array[k].times == 0)
    return -1;

  else if(str1.compare(Array[k].str) == 0 && str1.length() == Array[k].str.length())
    return Array[k].times;
  else
    return searchword1(Array[k].right, str1);
}

int HashTable::searchword1(hashtable *A, string str1) const
{

  if(A->times==0)
    return -1;

  else if(str1.compare(A->str)==0 && str1.length() == A->str.length())
    return A->times;
  else
    return searchword1(A->right, str1);
}


//operators
ostream &operator<<(ostream &o, const HashTable &a)
{
    o << "Hash Table with " << a.size <<" unique words";
    return o;

}
