/*
 * Name        : bs_treet.h
 * Author      : Gabrielle Lee
 * Description : Assignment_5
 */
#ifndef BS_Treet_H_
#define BS_Treet_H_


#include <iostream>
#include <string>
#include <sstream>
#include "bs_nodet.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


template <typename T>
class BSTreeT {
// Constuctors and Destructor
 public:
BSTreeT();

~BSTreeT();


// Helper Setters
void Clear();

int Insert(T add);

int Remove(T to_del);


// Helper Checkers
bool Exists(T to_find);

T FindMin();

// Helper Getters
unsigned int GetSize() const;

BSTNodeT<T>* Get(T to_get);


// Helper printers
string ToStringForwards();

string ToStringBackwards();


// Private Functions

 private:
BSTNodeT<T>* root_;
int size_ = 0;

// Setters
void Clear(BSTNodeT<T>*& subroot);

int Insert(T add, BSTNodeT<T>*& subroot);

int Remove(T to_del, BSTNodeT<T>*& subroot);


// Getters
BSTNodeT<T>* Get(T to_get, BSTNodeT<T>*& subroot);


// Checker Functions
bool Exists(T to_find, BSTNodeT<T>*& subroot);

T FindMin(BSTNodeT<T>* subroot);

// Printers
string ToStringForwards(BSTNodeT<T>*& subroot);

string ToStringBackwards(BSTNodeT<T>*& subroot);
};

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

// Helper Functions Setters

template<typename T>
void BSTreeT<T>::Clear() {
Clear(root_);
}

template<typename T>
int BSTreeT<T>::Insert(T add) {
return Insert(add, root_);
}

template<typename T>
int BSTreeT<T>::Remove(T to_del) {
int to_return;
if (Exists(to_del, root_) == true) {
to_return = Remove(to_del, root_);
} else {
to_return = -1;
}
return to_return;
}

// Helper checker functions
template<typename T>
bool BSTreeT<T>::Exists(T to_find) {
return Exists(to_find, root_);
}

template<typename T>
T BSTreeT<T>::FindMin() {
if (root_ == NULL) {
return 0;
}
return FindMin(root_);
}

// Helper Getters

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
if(size_ == 0) {
} else if (subroot != NULL) {
if (subroot->GetLeft() != NULL) {
Clear(subroot->GetLeft());
}
if(subroot->GetRight() != NULL) {
Clear(subroot->GetRight());
}
delete subroot;
subroot = NULL;
} else {
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
return Insert(add, subroot->GetLeft());
} else if (add > subroot->GetContents()) {
return Insert(add, subroot->GetRight());
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
bool check;
check = Exists(to_del);

if (check == false) {
    to_return = -1;
}

if (subroot != NULL && check == true) {
// contents smaller than subroot go left
if (to_del < subroot->GetContents()) {
return Remove(to_del, subroot->GetLeft());


// Contents greater reater than subroot go right
} else if (to_del > subroot->GetContents()) {
return Remove(to_del, subroot->GetRight());


// contents equal to subroot
} else if (to_del == subroot->GetContents() && subroot->GetCount() == 1) {
    // no kids
    if (subroot->GetLeft() == NULL &&
      subroot->GetRight() == NULL) {
      delete subroot;
      subroot = NULL;
      size_--;
      to_return = 0;
// has only right child
    } else if (subroot->GetLeft() == NULL && subroot->GetRight() != NULL) {
      BSTNodeT<T>* temp = subroot;
      subroot = subroot->GetRight();
      delete temp;
      size_--;
      to_return = 0;
// has only left child
    } else if (subroot->GetRight() == NULL && subroot->GetLeft() != NULL) {
      BSTNodeT<T>* temp = subroot;
      subroot = subroot->GetLeft();
      delete temp;
      size_--;
      to_return = 0;

// has left and right child
    } else {
      T temp =(FindMin(subroot->GetRight()));
      Remove(temp, subroot->GetRight());
      subroot->SetContents(temp);
      to_return = subroot->GetCount();
    }
} else if (to_del == subroot->GetContents() && subroot->GetCount() > 1) {
subroot->DecreaseCount();
to_return = subroot->GetCount();
}

} else {
to_return = 0;
}

return to_return;
}




// function to check if contents exsist
template<typename T>
bool BSTreeT<T>::Exists(T to_find, BSTNodeT<T>*& subroot ) {
bool to_return;

if (subroot == NULL) {
to_return = false;
}

if (subroot->GetContents() == to_find) {
to_return = true;
// Go Left
} else if (to_find < subroot->GetContents() && subroot->GetLeft() != NULL) {
return Exists(to_find, subroot->GetLeft());
// Go Right
} else if (to_find > subroot->GetContents() && subroot->GetRight() != NULL) {
return Exists(to_find, subroot->GetRight());
// Not Found
} else {
to_return = false;
}
return to_return;
}




// Function to retive input
template<typename T>
BSTNodeT<T>* BSTreeT<T>::Get(T to_get, BSTNodeT<T>*& subroot) {
BSTNodeT<T>* to_return;
if (subroot == NULL) {
return NULL;

// Go left
} else if (to_get > subroot->GetContents()) {
if(subroot->GetContents() == to_get) {
to_return = subroot;
} else if (subroot-> GetLeft() != NULL) {
return Get(to_get, subroot->GetLeft());
} else {
return NULL;
}
// Go right
} else if (to_get < subroot->GetContents()) {
  if (subroot->GetContents() == to_get) {
  to_return = subroot;
  } else if (subroot-> GetRight() != NULL) {
  return Get(to_get, subroot->GetRight());
  } else {
  return NULL;
}
}
return to_return;
}


template<typename T>
string BSTreeT<T>::ToStringForwards(BSTNodeT<T>*& subroot) {
stringstream print;
if (subroot == NULL) {
print << "";
} else {
if(subroot->GetLeft() != NULL) {
  print << ToStringForwards(subroot->GetLeft()) << ", ";
}
  print << subroot->GetContents();
if(subroot->GetRight() != NULL) {
  print << ", "  << ToStringForwards(subroot->GetRight());
}
}
return print.str();
}


template<typename T>
string BSTreeT<T>::ToStringBackwards(BSTNodeT<T>*& subroot) {
stringstream print;
if (subroot == NULL) {
print << "";
} else {
if(subroot->GetRight() != NULL) {
  print << ToStringBackwards(subroot->GetRight() )<< ", ";
}
print << subroot->GetContents();

if(subroot->GetLeft() != NULL) {
print << ", " << ToStringBackwards(subroot->GetLeft());
}
}
return print.str();
}

template<typename T>
T BSTreeT<T>::FindMin(BSTNodeT<T>* subroot) {
T to_return;
if (subroot == NULL) {
to_return = 0;
} else if (subroot != NULL && subroot->GetLeft() != NULL) {
return FindMin(subroot->GetLeft());
} else if (subroot != NULL && subroot->GetLeft() == NULL) {
to_return =  subroot->GetContents();
}
return to_return;
}

#endif
