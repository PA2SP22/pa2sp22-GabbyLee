#include "bs_treet.h"
/*
 * Name        : bs_treet.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment_5
 */


// Constuctors and Destructor
 template<typename T>
BSTreeT<T>::BSTreeT() {
    root_ = NULL;
    size_ = 0; 
}
 template<typename T>
BSTreeT<T>::~BSTreeT() {
 Clear();   
}

// Helper Functions

// Setters
 template<typename T>
void BSTreeT<T>::Clear() {
    Clear(root_);
}
 template<typename T>
int BSTreeT<T>::Insert(T add) {
 return Insert(add, root_);
}
 template<typename T>
int BSTreeT<T>::Remove(T to_del){
 return Remove(to_del, root_);
}

// Helper checker functions
 template<typename T>
bool BSTreeT<T>::Exists(T to_find) {
  return  Exists(to_find, root_);
}


// Helper Getters
// To get size
template<typename T>
unsigned int BSTreeT<T>::GetSize() const {
 return size_;
}

// helper to Get user defined tree node
 template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T to_get) {
 return Get(to_get, root_);
}

// helper to print string forwards
 template<typename T>
string BSTreeT<T>::ToStringForwards() {
 return ToStringForwards(root_);
}

// helper to print string backwards
 template<typename T>
string BSTreeT<T>::ToStringBackwards() {
 return ToStringBackwards(root_);
    
}


// Private functions 
 template<typename T>
void BSTreeT<T>::Clear(BSTNodeT<T>*& subroot) {
            
if (subroot != NULL) {
if (subroot->GetLeftd() != NULL) {
Clear(subroot->GetLeft());
}
if(subroot->GetRight() != NULL) {
Clear(subroot->GetRight());
}
delete subroot;
subroot = NULL;
}
size_ = 0;
}


 template<typename T>
 int BSTreeT<T>::Insert(T add, BSTNodeT<T>*& subroot) {
 int to_return;


if (subroot == NULL) {
BSTNodeT<T>* new_kid = new BSTNodeT<T>(add);    
subroot = new_kid;
size_++;
subroot->IncreaseCount();
to_return = subroot->GetCount();

} else if (add < subroot->GetContents()) {
return Insert(add, subroot->GetLeftChild());

} else if (add > subroot->GetContents()) {
return Insert(add, subroot->GetRightChild());

} else if (subroot->GetContents() == add) {
subroot->IncreaseCount();
to_return = subroot->GetCount();
}
return to_return;
}

// to remove contents from tree
 template<typename T>
int BSTreeT<T>::Remove(T to_del, BSTNodeT<T>*& subroot) {
int to_return;
    if (subroot != NULL) {
  
// contents smaller than subroot go left
if (to_del < subroot->GetContents()) {
return Remove(to_del, subroot->GetLeft());
    
    
// Contents greater reater than subroot go right 
} else if (to_del > subroot->GetContents()) {
 return Remove(to_del, subroot->GetRight());


// contents equal to subroot
  } else if (to_del == subroot->GetContents()) {
    // no kids
    if (subroot->GetLeft() == NULL &&
        subroot->GetRight() == NULL) {
      delete subroot;
      subroot = NULL;
      size_--;
      subroot->DecreaseCount();
      to_return = subroot->GetCount();
      
// has only right child
    } else if (subroot->GetLeft() == NULL && subroot->GetRight() != NULL) {
      BSTNodeT<T>* temp = subroot;
      subroot = subroot->GetRight();
      // Luke: Since you're deleting, no need to set to NULL
      // temp->SetRightChild(NULL);
      delete temp;
      size_--;
      to_return = subroot->GetCount();
// has only left child
    } else if (subroot->GetRight() == NULL && subroot->GetLeft() != NULL) {
      BSTNodeT<T>* temp = subroot;
      subroot = subroot->GetLeft();
      delete temp;
      size_--;
      subroot->DecreaseCount();
      to_return = subroot->GetCount();
      
// has left and right child
    } else {
      int temp =(FindMin(subroot->GetRight()));
      Remove(temp, subroot->GetRight());
      subroot->SetContents(temp);
      subroot->DecreaseCount();
      to_return = subroot->GetCount();
    }

}
} else {
to_return = 0;
}
return to_return;
}




// function to check if contents exsist
 template<typename T>
bool BSTreeT<T>::Exists(T to_find, BSTNodeT<T>*& subroot ) {
if (subroot == NULL){
return false;
}

// Go left
if (to_find < subroot->GetContents()) {
 if(subroot->GetContents() == to_find) {
    return true;

} else if(subroot-> GetLeftChild() != NULL) {
return Get(to_find, subroot->Getleft());

} else {

    return false;

}
   
// Go right 
} else if (to_find > subroot->GetContents()) {
if (subroot->GetContents() == to_find) {
   return true;
} else if (subroot->GetRightChild() != NULL) {

return Get(to_find, subroot->GetRight());

} else {
return false;
}

}

}




// Function to retive input
 template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T to_get, BSTNodeT<T>*& subroot) {

if (subroot == NULL){
return NULL;


// Go left
} else if (to_get < subroot->GetContents()) {
if(subroot->GetContents() == to_get) {
    return subroot;
}  else if(subroot-> GetLeft() != NULL) {
return Get(to_get, subroot->Getleft());
} else {
    return NULL;
}


// Go right 
} else if (to_get > subroot->GetContents()) {
if(subroot->GetContents() == to_get) {
    return subroot;
} else if(subroot-> GetRight() != NULL) {
return Get(to_get, subroot->GetRight());
} else {
    return NULL;
}

}

}


 template<typename T>
string BSTreeT<T>::ToStringForwards(BSTNodeT<T>*& subroot) {
stringstream print;
if (subroot == NULL) {
print << "";
} else {
  print << InOrder(subroot->GetLeft());
  print << subroot->GetContents() << " ";
  print<< InOrder(subroot->GetRight());
}
return print.str();
}
 template<typename T>
string BSTreeT<T>::ToStringBackwards(BSTNodeT<T>*& subroot) {
stringstream print;
if (subroot == NULL) {
print << "";
} else {
  print << InOrder(subroot->GetLeft());
  print << subroot->GetContents() << " ";
  print<< InOrder(subroot->GetRight());
}
return print.str();
}
