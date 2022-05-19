#include "bs_tree.h"

BSTree::BSTree() {
  root = NULL;
  size = 0;
}

BSTree::~BSTree(){
  Clear();
}

bool BSTree::Insert(int contents) {
  bool isDone; 
  isDone = Insert(contents, root);
  return isDone;
}

void BSTree::Clear(){
  Clear(root);
}

unsigned int BSTree::GetSize() const {
  return size;
}
	
string BSTree::InOrder() {
  InOrder(root);
}

bool BSTree::Insert (int contents, BSTNode*& root ) {
  bool isDone;
  
  BSTNode* new_kid = new BSTNode(contents); 
  if (root == NULL){
    root = new_kid;
    size++;
    isDone = true;
    
  } else if (root < new_kid){
    new_kid->SetLeftChild(root);
    size++;
    isDone = true;
    
  } else if (root < new_kid){
    new_kid->SetRightChild(root);
    size++;
    isDone = true;
  
  } else if (root == new_kid) {
    isDone = false; 
  }
  return isDone;
}
	
void BSTree::Clear (BSTNode*& root){
  
}
	
string BSTree::InOrder(BSTNode*& root){
  
}