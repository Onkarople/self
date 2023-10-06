#include <iostream>
using namespace std;

struct node 
{
  int data;
  struct node *left;
  struct node *right;
};


typedef struct node NODE;
typedef struct node * PNODE;

class BST 
{
  PNODE root;
  void insert(PNODE, int);
  void inOrder(PNODE);
  void preOrder(PNODE);
  

 public:
 
  BST();
  void insert(int);
  void display();
 
};

BST::BST()
{
  root = NULL;
}




void BST::insert(PNODE leaf, int key)
{
    if(root != NULL) {
    insert(root, key);
  } else {
    root = new node;
    root->data = key;
    root->left = NULL;
    root->right = NULL;
  }
  if (key < leaf->data){
    if (leaf->left != NULL) {
      insert(leaf->left, key);
    } else {
      leaf->left = new node;
      leaf->left->data = key;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
  } else {
    if (leaf->right != NULL) {
      insert(leaf->right, key);
    } else {
      leaf->right = new node;
      leaf->right->data = key;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }
  }
}


void BST::inOrder(PNODE t)
{
  if (t != NULL) {
    inOrder(t->left);
    cout << t->data <<" ";
    inOrder(t->right);
  }
}


void BST::preOrder(PNODE t)
{
  if (t != NULL) {
    cout << t->data << " ";
    preOrder(t->left);
    preOrder(t->right);
  }
}

void BST::display()
{
  cout<<"preOrder: ";
  preOrder(root); 

  cout<<"\ninOrder: ";
  inOrder(root);
}



int main() {

  BST* tree = new BST();
  tree->insert(50);
  tree->insert(19);
  tree->insert(28);
  tree->insert(40);
  tree->insert(16);
  tree->insert(70);
  tree->insert(55);
  tree->insert(56);
  tree->insert(17);
  tree->insert(90);
  tree->display();
  return 0;
}
