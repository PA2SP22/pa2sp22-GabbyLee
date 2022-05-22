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
