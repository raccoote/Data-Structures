#ifndef AVL_h
#define AVL_h
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

class AVLtree : public BinaryTree
{
  public:
      struct node
      {
          string word; // the word
          int times;   // how many times the word appears
          node * left; // left child
          node * right;// right child
      }* root;       // tree root creation
      int size;      // total words our data structure has so far saved


      AVLtree(); // basic constructor
      node *insert(node *, string); //function that inserts a word in the tree
      int searchword(node *, string) const; // function that searches for a specific word
      node *deleteword(node *, string);  // function that deletes a specific word
      node *min(node *); // finds the alphabetically smallest word
      unsigned long long int height(node *); // function that calculates the height of the tree
      int difference(node *); // function that calculates the difference between the right and left subtree
      node *balanced(node *); // function that balances our tree
      node *rightright(node *); // function that makes a right-right rotation
      node *leftleft(node *); // function that makes a left-left rotation
      node *leftright(node *); // function that makes a left-right rotation
      node *rightleft(node *); // function that makes a right-left rotation
      void inorder(node *); // prints nodes in inorder and works recursively
      void preorder(node *);  // prints nodes in preorder and works recursively
      void postorder(node *);  // prints nodes in postorder and works recursively

      //same functions but easier to call in main
      void insert(string);
      int search(string) const;
      void inorder();
      void preorder();
      void postorder();
};

ostream &operator<<(ostream &, const AVLtree &); // prints basic info about the array, like type (AVL) and size (total words saved)


#endif
