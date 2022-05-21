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
return InOrder(root);
}

bool BSTree::Insert (int contents, BSTNode*& subroot ) {
  bool isDone;
  
  BSTNode* new_kid = new BSTNode(contents); 
  if (subtroot == NULL){
    subroot = new_kid;
    size++;
    isDone = true;
    
  } else if (new_kid < subroot->GetContents()){
   return Insert(new_kid, subroot->GetLeftChild());
    
  } else if (new_kid > subroot->GetContents()){
    return Insert(new_kid, subroot->SetRightChild(root);
  
  } else if (root == new_kid) {
    isDone = false; 
  }
  return isDone;
}
	
void BSTree::Clear (BSTNode*& subroot){
  if(subroot != NULL) {
    
  if (subroot ->GetLeftChild() != NULL {
    Clear(subroot->GetLeftChild());
  }
  if(subroot->GetLeftChild()) {
    Clear(subroot->GetRightChild());
  }
  
  delete subroot;
  subroot = NULL;
}
size =0;
	
string BSTree::InOrder(BSTNode*& subroot){
stringstream print;
  If (subroot == NULL) {
    print << "";
  }
  
  print << InOrder(subroot->GetLeftChild());
  print << subroot->GetContents() <<;
  print<< Inorder(subroot->GetRightChild());
  
 return print.str();
}