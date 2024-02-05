#include<iostream>
#include<cstring>
using namespace std;

class HashTable
{
  public:

  struct hashtable
  {
    int key;
    string str; //η λέξη
    int times = 0; //πόσες φορές εμφανίζεται η λέξη
    hashtable *right;
  }*Array;
  int size;
  HashTable();

  int search(const string &) const;
  void insert(const string &);
  hashtable *insertword(hashtable *, string);
  hashtable *insertword1(hashtable *, string);
  int searchword(hashtable *, string) const;
  int searchword1(hashtable *, string) const;
};

ostream &operator<<(ostream &, const HashTable &); // prints basic info about the array, like type (HashTable) and size (total words saved)
