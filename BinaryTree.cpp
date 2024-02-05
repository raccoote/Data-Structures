#include <iostream>
#include <fstream>
#include <string.h>
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree()//κατασκευαστής
{
    size = 0;
    root=NULL;//θέτει το root ίσο με NULL
}

void BinaryTree::insert(string WORD)
{
    size++;
    this->root = insert(this->root, WORD);
}

int BinaryTree::search(string WORD) const
{
    return searchword(this->root, WORD);
}

BinaryTree::node *BinaryTree::insert(node *root,string WORD)// συνάρτηση που προσθέτει την λέξη στο δυαδικό δέντρο
{
  if(root==NULL)//αν το root είναι κενό τότε η λέξη δεν υπάρχει στο δυαδικό δέντρο και την προσθέτουμε σε αυτόν τον κόμβο
  {
    root=new node;
    root->times=1;
    root->right=NULL;
    root->left=NULL;
    root->word = WORD;
    return root;
  }
  else if(WORD.compare(root->word)>0)//αν η λέξη είναι αλφαβητικά μεγαλύτερη τότε παίρνουμε το δεξί παιδί του κόμβου
  {
    root->right=insert(root->right,WORD);
    return root;
  }
  else if(WORD.compare(root->word)<0)//αν η λέξη είναι αλφαβητικά μικρότερη τότε παίρνουμε το αριστερό παιδί του κόμβου
  {
    root->left=insert(root->left,WORD);
    return root;
  }
  else if(WORD.compare(root->word)==0 && WORD.length() == root->word.length())//αν υπάρχει η λέξη στο δέντρο τότε αυξάνουμε το times κατά 1
  {
      root->times++;
      size--;
  }

  return root;
}
int BinaryTree::searchword(node *T,string WORD) const//συνάρτηση που κάνει αναζήτηση μια λέξη
{

  if(T==NULL)//αν ο κόμβος είναι κενός τότε η λέξη δεν υπάρχει
    return -1;
  else if(WORD.compare(T->word)>0)//αν η λέξη είναι αλφαβητικά μεγαλύτερη τότε παίρνουμε το δεξί παιδί του κόμβου
    return searchword(T->right,WORD);
  else if(WORD.compare(T->word)<0)//αν η λέξη είναι αλφαβητικά μικρότερη τότε παίρνουμε το αριστερό παιδί του κόμβου
    return searchword(T->left,WORD);

  return T->times;//διαφορετικά η λέξη υπάρχει και επιστρέφουμε πόσες φορές εμφανίστηκε η λέξη στο κείμενο

}
BinaryTree::node *BinaryTree::deleteword(node *root,string WORD)//συνάρτηση που διαγράφει μια λέξη
{

  if(root==NULL) //αν ο κόμβος είναι κενός δεν υπάρχει η λέξη
    return root;
  if( WORD.compare(root->word)<0 ) //αν η λέξη είναι αλφαβητικά μικρότερη τότε παίρνουμε το αριστερό παιδί του κόμβου
    root->left=deleteword(root->left,WORD);
  else if(WORD.compare(root->word)>0 )//αν η λέξη είναι αλφαβητικά μεγαλύτερη τότε παίρνουμε το δεξί παιδί του κόμβου
    root->right=deleteword(root->right,WORD);
  else//αν βρεθεί η λέξη
  {
    if((root->left==NULL) || (root->right==NULL) ) //αν ένα τουλάχιστον από τα  παιδιά είναι NULL
    {
      node *T=root->left;//δημιουργούμε ένα struct T που θα έιναι ίσο με το αριστερό παιδί του root
      if(T) //αν το Τ δεν είναι NULL
        T=root->left ;//τότε το T θα έιναι ίσο με το αριστερό παιδί του root
      else //αλλιώς τότε το T θα έιναι ίσο με το δεξί παιδί του root
        T=root->right;
      if(T==NULL)// αν το Τ είναι NULL
      {
        T=root;//τότε το Τ θα γίνει ίσο με το root
        root = NULL;// και το root  θα γίνει NULL
      }
      else //αν το Τ δεν είναι NULL
        *root=*T;//τότε η διέθυνση του root θα δείχνει στην διέυθυνση του Τ
      free(T);
    }
    else// αν κανένα απο τα παιδιά του root δεν είναι NULL
    {
      node* T= min(root->right); //τότε το Τ θα είναι ίσο με τον μικρότερο κόμβο με ρίζα το δεξί παιδί του root
      root->word=T->word;//η λέξη του root γίνεται ίση με την λέξη του Τ
      root->right=deleteword(root->right,T->word);//το δεξί παιδί του root θα γίνει ίσο με αυτό που θα επιστρέψει η συνάρτηση deleteword με ορίσματα το δεξί παιδί του root και την λέξη του Τ
    }
  }
  return root;
}
BinaryTree::node *BinaryTree::min(node *start)//συνάρτηση που βρίσκει την πιο μικρή λέξη αλφαβητικά
{
   node* MIN=start;
  while(MIN->left!=NULL)//όσο το αριστερό παιδί του MIN δεν είναι NULL
      MIN=MIN->left;//τότε το MIN θα γίνεται ίσο με το αριστερό παιδί του
  return MIN;
}
void BinaryTree::inorder(node *T)//τυπώνει τις λέξεις με inorder σειρά και λειτουργεί αναδρομικά
{
  if(T==NULL)//όταν το Τ θα είναι NULL θα σταματάει η συνάρτηση
    return;
  inorder(T->left);
  cout<<T->word<< " ";
  inorder(T->right);
}
void BinaryTree::preorder(node *T)//τυπώνει τις λέξεις με preorder σειρά και λειτουργεί αναδρομικά
{
  if(T==NULL)
    return;
  cout<<T->word << " ";
  preorder(T->left);
  preorder(T->right);
}
void BinaryTree::postorder(node *T)//τυπώνει τις λέξεις με postorder σειρά και λειτουργεί αναδρομικά
{
  if(T==NULL)
    return;
  postorder(T->left);
  postorder(T->right);
  cout<<T->word<< " ";
}
//operators
ostream &operator<<(ostream &o, const BinaryTree &a)
{
    o << "Binary Search Tree with " << a.size <<" unique words";
    return o;

}
