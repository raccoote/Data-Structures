#ifndef BST_h
#define BST_h
#include<iostream>
#include <string.h>
#include <fstream>
using namespace std;

class BinaryTree
{
  public:
  struct node//δημιουργούμε ένα struct που να περιέχει την λέξη και το πόσες φορές εμφανίζεται στο κείμενο ,και τα παιδιά του κόμβου
  {
    string word;//η λέξη
    int times;//πόσες φορές εμφανίζεται η λέξη
    node *left;//αριστερο παιδί
    node *right;//δεξί παιδί

  }*root;//δημιουργούμε ενα node
  int size;
  BinaryTree();//κατασκευαστής
  void insert(string);
  int search(string) const;
  node *insert(node *, string);// συνάρτηση που προσθέτει την λέξη στο δυαδικό δέντρο
  int searchword(node *, string) const;//συνάρτηση που κάνει αναζήτηση μια λέξη
  node *deleteword(node *, string);//συνάρτηση που διαγράφει μια λέξη
  node *min(node *);//συνάρτηση που βρίσκει την πιο μικρή λέξη αλφαβητικά
  void inorder(node *);//τυπώνει τις λέξεις με inorder σειρά
  void preorder(node *);//τυπώνει τις λέξεις με preorder σειρά
  void postorder(node *);//τυπώνει τις λέξεις με postorder σειρά
};

ostream &operator<<(ostream &o, const BinaryTree &a);
#endif
