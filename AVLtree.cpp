#include <iostream>
#include <fstream>
#include <string.h>
#include "AVLtree.h"
using namespace std;

AVLtree::AVLtree() //constructor
{
  root = NULL;
  size = 0;
}

void AVLtree::insert(string WORD) // insert function that matches the template function in function.h
{
    size++;
    this->root = insert(this->root, WORD);
}

int AVLtree::search(string WORD) const // search function that matches the template function in function.h
{
    return searchword(this->root, WORD);
}

AVLtree::node *AVLtree::insert(node * root, string WORD) // recursive function that inserts word to the tree
{
  if(root==NULL) // if root is null then word doesnt exist in the tree so we insert it in this node
  {
    root = new node;
    root->times = 1;
    root->right = NULL;
    root->left = NULL;
    root->word = WORD;
  }
  else if(WORD.compare(root->word) > 0) // if the word is alphabetically bigger then we go to the right child of the node
  {
    root->right = insert(root->right, WORD);
    root = balanced(root);
  }
  else if(WORD.compare(root->word) < 0) // if the word is alphabetically smaller then we go to the left child of the node
  {
    root->left = insert(root->left,WORD);
    root = balanced(root);
  }
  else if(WORD.compare(root->word) == 0 && WORD.length() == root->word.length()) // if the word already exists in the tree we icnrement times by 1
  {
      root->times++;
      size--;
  }
  return root;
}


int AVLtree::searchword(node *T,string WORD) const // recursive function that searches for a specific word
{
  if(T == NULL) // if node is NULL then the word doesnt exist
  {
      return -1;
  }
  else if(WORD.compare(T->word) > 0)  // if the word is alphabetically bigger then we go to the right child of the node
  {
      return searchword(T->right, WORD);
  }
  else if(WORD.compare(T->word) < 0) // if the word is alphabetically smaller then we go to the left child of the node
  {
      return searchword(T->left, WORD);
  }

  return T->times; // the word exists and we return how many times the word has appeared in our text

}
AVLtree::node *AVLtree::deleteword(node *root,string WORD) // recursive function that deletes a function
{

  if(root==NULL) // if root is NULL then the word doesnt exist
    return root;
  if( WORD.compare(root->word)<0 )  // if the word is alphabetically bigger then we go to the right child of the node
    root->left=deleteword(root->left,WORD);
  else if(WORD.compare(root->word)>0 ) // if the word is alphabetically smaller then we go to the left child of the node
    root->right=deleteword(root->right,WORD);
  else // if word is found
  {
    if((root->left==NULL) || (root->right==NULL) ) // if at least on of the childs is NULL
    {
        node *T = root->left; // we create a struct T, equal to root's left child
        if(T) // if T isn't NULL
          T = root->left ; // T is equal to root's left child
        else
          T = root->right; // T is equal to root's right child
        if(T == NULL) // if T is NULL
        {
          T = root; // then will be equal to root
          root = NULL; // and root will be equal to NULL
        }
       else
       {
           *root=*T; // then
       }
       free(T);
    }
    else // if none of the root's childs is NULL
    {
      node* T= min(root->right); // T is equal to the smallest node of root's childs
      root->word=T->word; // root's word is equal to T's word
      root->right=deleteword(root->right,T->word); //το δεξί παιδί του root θα γίνει ίσο με αυτό που θα επιστρέψει η συνάρτηση deleteword με ορίσματα το δεξί παιδί του root και την λέξη του Τ
    }
  }
  if (root==NULL)
    return root;
  root=balanced(root); // we call the fun that balances our tree
  return root;
}

AVLtree::node *AVLtree::min(node *start)
{
   node* MIN=start;
  while(MIN->left!=NULL) // while the left child of MIN is NOT null
      MIN=MIN->left; // MIN is equalt to its left child
  return MIN;
}

unsigned long long int AVLtree::height(node* T)
{
  int h=0;
  int lh=0;
  int rh=0;
  int max;
  if(T!=NULL) //αν το Τ δεν είναι NULL μετράμε τα ύψη του δεξιού και του αριστερού υποδέντρου και κρατάμε όποιο είναι το μεγαλύτερο
  {
    rh=height(T->right);
    lh=height(T->left);
    if(lh>rh)
      h=lh+1;
    else
      h=rh+1;
  }
  return h;

}
int AVLtree::difference(node *T)
{
  int rh;
  int lh;
  rh=height(T->right);
  lh=height(T->left);
  int difference;
  difference=lh-rh;
  return difference;
}
AVLtree::node *AVLtree::balanced(node *T)
{
  int balance;
  balance=difference(T);
  if(balance>1) //αν η διαφορά του δεξιού και αριστερού υποδέντρου είναι μεγαλύτερη απο 1 τότε το ύψος του αριστερού υποδέντρου είναι μεγαλύτερο
  {
    if(difference(T->left)>0) //αν το αριστερό υποδέντρο δεν είναι ισορροπημένο
      T=leftleft(T); //τότε κάνουμε left-left rotation
    else //αλλιώς αν είναι ισορροπημένο
      T=leftright(T); //τότε κάνουμε left-right rotation
  }
  else if(balance<-1) //αν η διαφορά του δεξιού και αριστερού υποδέντρου είναι μικρότερη απο -1 τότε το ύψος του δεξιού υποδέντρου είναι μεγαλύτερο
  {
    if(difference(T->right)>0) //αν το δεξί υποδέντρο δεν είναι ισορροπημένο
       T=rightleft(T); //τότε κάνουμε right-left rotation
     else //αλλιώς αν είναι ισορροπημένο
      T=rightright(T); //τότε κάνουμε right-right rotation
  }
  return T;
}
AVLtree::node *AVLtree::rightright(node *T) //συνάρτηση που κάνει right-right rotatiοn που κάνει απλή right περιστροφη
{
  node *t;
  t=T->right;
  T->right=t->left;
  t->left=T;
  return t;
}
AVLtree::node *AVLtree::leftleft(node *T) //συνάρτηση που κάνει left-left rotation που κάνει απλή left περιστροφη
{
  node *t;
  t=T->left;
  T->left= t->right;
  t->right=T;
  return t;
}
AVLtree::node *AVLtree::leftright(node *T) //συνάρτηση που κάνει left-right rotation
{
  node *t;
  t=T->left;
  T->left=rightright(t);
  return leftleft(T);
}
AVLtree::node *AVLtree::rightleft(node *T)//συνάρτηση που κάνει right-left rotation
{
  node *t;
  t=T->right;
  T->right=leftleft(t);
  return rightright(T);
}


void AVLtree::inorder(node *T)
{
  if(T==NULL)
    return;
  inorder(T->left);
  cout<<T->word<< " ";
  inorder(T->right);
}

void AVLtree::preorder(node *T)
{
  if(T==NULL)
    return;
  cout<<T->word << " ";
  preorder(T->left);
  preorder(T->right);
}

void AVLtree::postorder(node *T) //
{
  if(T==NULL)
    return;
  postorder(T->left);
  postorder(T->right);
  cout<<T->word<< " ";
}

void AVLtree::inorder()
{
    inorder(this->root);
}

void AVLtree::preorder()
{
    preorder(this->root);
}

void AVLtree::postorder()
{
    postorder(this->root);
}
//operators
ostream &operator<<(ostream &o, const AVLtree &a) // prints basic info about the array, like type (AVL) and size (total words saved)
{
    o << "AVL tree with " << a.size <<" unique words";
    return o;

}
