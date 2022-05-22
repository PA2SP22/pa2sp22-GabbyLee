#include "bs_tree.h"


// Public Member Functions
BSTree::BSTree() {
  root_ = NULL;
  size_ = 0;
}


BSTree::~BSTree() {
  Clear();
}

bool BSTree::Insert(int contents) {
return Insert(contents, root_);
}


bool BSTree::Remove(int contents) {
  return Remove(contents, root_);
}


int BSTree::FindMin() {
  if (root_ == NULL) {
    return 0;
  }
  return FindMin(root_);
}



void BSTree::Clear() {
Clear(root_);
}

unsigned int BSTree::GetSize() const {
return size_;
}

string BSTree::InOrder() {
return InOrder(root_);
}

// Private Member Functions

bool BSTree::Insert(int contents, BSTNode*& subroot ) {
  bool isDone;

  BSTNode* new_kid = new BSTNode(contents);
  if (subroot == NULL) {
    subroot = new_kid;
    size_++;
    isDone = true;

} else if (contents < subroot->GetContents()) {
return Insert(contents, subroot->GetLeftChild());

} else if (contents > subroot->GetContents()) {
return Insert(contents, subroot->GetRightChild());

} else if (subroot->GetContents() == contents) {
isDone = false;
}
return isDone;
}

bool BSTree::Remove(int to_del, BSTNode*& subroot){
    if (subroot == NULL) {
    return false;
  }
// contents smaller than subroot
  if (to_del < subroot->GetContents()
      && subroot->GetLeftChild() != NULL) {
    return Remove(to_del, subroot->GetLeftChild());
    
// Contents greater reater than subroot
  } else if (to_del > subroot->GetContents() &&
           subroot->GetRightChild() != NULL) {
    return Remove(to_del, subroot->GetRightChild());
    
    
// contents equal to subroot
  } else if (to_del == subroot->GetContents()) {
    // Check if subroot has 0 children
    if (subroot->GetLeftChild() == NULL &&
        subroot->GetRightChild() == NULL) {
      delete subroot;
      subroot = NULL;
      size_--;
      return true;
      
// 
    } else if (subroot->GetLeftChild() == NULL) {
      BSTNode* temp = subroot;
      subroot = subroot->GetRightChild();
      delete temp;
      size_--;
      return true;
// 
    } else if (subroot->GetRightChild() == NULL) {
      BSTNode* temp = subroot;
      subroot = subroot->GetLeftChild();
      delete temp;
      size_--;
      
// 
    } else {
      subroot->SetContents(FindMin(subroot->GetRightChild()));
      Remove(subroot->GetContents(), subroot->GetRightChild());
      return true;
    }
  }
  return false;
}


int BSTree::FindMin(BSTNode* subroot) {

  if (subroot->GetLeftChild() != NULL) {
    return FindMin(subroot->GetLeftChild());
  }
  return subroot->GetContents();

}


void BSTree::Clear(BSTNode*& subroot) {
if (subroot != NULL) {
if (subroot->GetLeftChild() != NULL) {
Clear(subroot->GetLeftChild());
}
if(subroot->GetRightChild() != NULL) {
Clear(subroot->GetRightChild());
}
delete subroot;
subroot = NULL;
}
size_ = 0;
}

string BSTree::InOrder(BSTNode*& subroot) {
stringstream print;
if (subroot == NULL) {
print << "";
} else {
  print << InOrder(subroot->GetLeftChild());
  print << subroot->GetContents() << " ";
  print<< InOrder(subroot->GetRightChild());
}
return print.str();
}
