#include "dl_list.h"
#include <iostream>

/*
 * Name        : dl_list.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment_4
 */
 
// Constructor
DLList::DLList() {
  head_ = NULL;
  tail_ = NULL;
}

// Destructor
DLList::~DLList() {
  Clear(); 
}


// Add contents to the front of list 
void DLList::PushFront(int contents) {
    if (head_ == NULL) {
    head_ = new DLNode(contents);
    tail_= head_;
    size_ = size_ + 1;
    } else {
  DLNode* newnode = new DLNode(contents);
  head_->SetPrevious(newnode); 
  newnode->SetNext(head_);
  head_ = newnode;
  size_ = size_ + 1;
    }
  }
// Add to the end of the list 
void DLList::PushBack(int contents) {
  if (head_ == NULL) {
   head_ = new DLNode(contents);
   tail_ = head_;
   size_ = size_ + 1;
   
  // If the size of list is 1
  } else if (head_ != NULL && head_->GetNext() == NULL) {
  DLNode* new_node = new DLNode(contents);
  head_ ->SetNext(new_node);
  tail_ = new_node;
  tail_ ->SetPrevious(head_);
  size_ += 1;
  
  
// If the size of list is greater than one
  } else {
    DLNode* new_node = new DLNode(contents);
    tail_->SetNext(new_node);
    new_node->SetPrevious(tail_);
    tail_ = new_node;
    size_ += 1;
  }
}


// Remove head
void DLList::PopFront() {
  if (head_ == NULL) {
  size_ = 0;
  } else if (head_ != NULL && head_->GetNext() == NULL) {
   delete head_;
   head_ = NULL;
   tail_= NULL;
   size_ -=1;
   
  } else {
    DLNode* temp = head_;
    head_ = head_-> GetNext();
    delete temp;
    temp = NULL;
    size_ = size_ - 1;
    }
}
// Remove tail 
void DLList::PopBack() {
if (head_ == NULL){
size_ = 0;
} else {
    DLNode* temp; 
    temp = tail_->GetPrevious();
    temp->SetNext(NULL);
    delete tail_;
    tail_ = temp;
   }
}

bool DLList::Exists(int to_find) {
  bool isFound = false;
if (size_ == 0 || to_find == 0) {
isFound = false; 
} else {
DLNode* temp = head_;
while (temp != NULL) {
if (temp->GetContents() == to_find) {
isFound = true;
}  else {
temp = temp->GetNext();
}
}
}
return isFound;
}

void DLList::RemoveFirst(int to_find) {
DLNode* temp = head_;
DLNode* temp2;
bool isFound;
isFound = Exists(to_find);


if (isFound == true) {
  // loop to search and delete
for (unsigned int i = 1; i < size_; i++) {
if (temp->GetContents() == to_find) {
temp2 = temp->GetPrevious();
temp2->SetNext(temp->GetNext());
temp->GetNext()->SetPrevious(temp2);
delete temp;
size_ -= 1;
break;
} else {
temp = temp->GetNext();
}
}
} else {
cout << "Not Found";
}
}
// Remove all occurances of num
void DLList::RemoveAll(int to_find) {
  DLNode* temp = head_;
  DLNode* temp2;
  bool isFound;

// Error checking
  isFound = Exists(to_find);
  
if (isFound == true) {
// loop to search and delete
for (unsigned int i = 1; i < size_; i++) {
   //check for matching contents
if (temp->GetContents() == to_find) {
  temp2 = temp->GetPrevious(); 
  temp2->SetNext(temp->GetNext());
  temp->GetNext()->SetPrevious(temp2);
  delete temp;
  size_ -= 1;
 }
}
temp = temp->GetNext();
} else {
cout << "Not Found";
}
}

// Delete dllist
void DLList::Clear() {
  // head is null
  if (head_ == NULL) {
  size_ = 0;

// The list has 2 items
  } else if (head_!= NULL && head_->GetNext() == NULL) {
  delete head_;
  head_ = NULL;
  tail_ = NULL;
  size_ -=1;
// Size of list is greater than 2
  } else {
    while (head_ != NULL) {
      DLNode* temp = head_;
      head_ = head_->GetNext();
      delete temp;
      size_-=1;
    }
    head_ = NULL;
    tail_= NULL;
  }
}

// Getters
int DLList::GetFront() {
int to_return;

if (size_ == 0) {
cout <<"Empty";
to_return = 0;
} else {
to_return = head_->GetContents();
}
 return to_return;
}

int DLList::GetBack() {
int to_return;
if (size_ == 0) {
cout << "List Empty";
to_return = 0;
} else {
to_return = tail_->GetContents();
}
return to_return;
}

unsigned int DLList::GetSize() const {
  return size_; 
}

//outputters
string DLList::ToStringBackwards() {
  stringstream print;
  DLNode* current = head_;
  // If list is emptey
  if (size_ == 0) {
  print <<"";
  cout << "List Empty";
  // If list is not empty
  } else {
  for (unsigned int i = size_; i > 0; i--) {
   if (i == 1) {
   print << current->GetContents();
   } else {
   print << current->GetContents() << ",";
   }
  }
  }
  return print.str(); 
}

string DLList::ToStringForwards() {
  stringstream print;
  DLNode* current = head_;
  if (size_ == 0) {
  print <<"";
 cout << "List Empty";
  } else {
  for (unsigned int i = size_; i > 0; i++) {
   if (i == 1) {
   print << current->GetContents() ;
   } else {
   print << current->GetContents() << ",";
   }
  }
  }
  return print.str();
}

