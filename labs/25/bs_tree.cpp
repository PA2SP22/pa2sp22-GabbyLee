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

  
  if (subroot == NULL) {
    // Luke: Memory Leak. You only want to call new when you want to create a node
    BSTNode* new_kid = new BSTNode(contents);
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

bool BSTree::Remove(int to_del, BSTNode*& subroot) {
  bool isDone;
if (subroot != NULL) {
  
// contents smaller than subroot go left
// Luke: Let the next recursion handle the NULL
if (to_del < subroot->GetContents()) {
return Remove(to_del, subroot->GetLeftChild());
    
    
// Contents greater reater than subroot go right 
} else if (to_del > subroot->GetContents()) {
 return Remove(to_del, subroot->GetRightChild());


// contents equal to subroot
  } else if (to_del == subroot->GetContents()) {
    // no kids
    if (subroot->GetLeftChild() == NULL &&
        subroot->GetRightChild() == NULL) {
      delete subroot;
      subroot = NULL;
      size_--;
      isDone = true;
      
// has only right child
    } else if (subroot->GetLeftChild() == NULL && subroot->GetRightChild() != NULL) {
      BSTNode* temp = subroot;
      subroot = subroot->GetRightChild();
      // Luke: Since you're deleting, no need to set to NULL
      // temp->SetRightChild(NULL);
      delete temp;
      size_--;
      isDone = true;
// has only left child
    } else if (subroot->GetRightChild() == NULL && subroot->GetLeftChild() != NULL) {
      BSTNode* temp = subroot;
      subroot = subroot->GetLeftChild();
      delete temp;
      size_--;
      isDone = true;
      
// has leaft and righ child
    } else {
      int temp =(FindMin(subroot->GetRightChild()));
      // Luke: You need to remove the extra, which is the one you're copying
      Remove(temp, subroot->GetRightChild());
      subroot->SetContents(temp);
      // Luke: Don't decrement size as the remove 2 lines above will do it for you
      // size_--;
      return true;
    }

}
} else {
  isDone = false;
}
return isDone;
}


int BSTree::FindMin(BSTNode* subroot) {
 int to_return;
if (subroot == NULL){
to_return = 0;
} else if (subroot != NULL && subroot->GetLeftChild() != NULL) {
    return FindMin(subroot->GetLeftChild());
} else if (subroot != NULL && subroot->GetLeftChild() == NULL ) {
   to_return =  subroot->GetContents();
}
   return to_return;

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
