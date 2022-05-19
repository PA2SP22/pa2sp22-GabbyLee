#include "dl_list.h"
#include <iostream>

/*
 * Name        : dl_list.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment_4
 */
 

DLList::DLList() {
  head_ = NULL;
  tail_ = NULL;
}

// destructor
DLList::~DLList() {
  Clear(); 
}

//Setters
// add contents to the front of list 
void DLList::PushFront(int contents) {
    if (head_ == NULL) {
    head_ = new DLNode(contents);
    tail_= head_;
    size_ = size_ + 1;
    } else {
  DLNode* new_node = new DLNode(contents);
  head_->SetPrevious(new_node); 
  new_node->SetNext(head_);
  head_ = new_node;
  size_ = size_ + 1;
    }
  }
// add contents to the end of the list 
void DLList::PushBack(int contents) {
if (head_ == NULL) {
head_ = new DLNode(contents);
tail_ = head_;
size_ = size_ + 1;
}  else {
    DLNode* new_node = new DLNode(contents);
    tail_->SetNext(new_node);
    new_node->SetPrevious(tail_);
    tail_ = new_node;
    size_ = size_ + 1;
    }
}


//remove head;
void DLList::PopFront() {
    if (head_ == NULL) {
  size_ = 0;
// If there is only one element in the list
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
//remove tail 
void DLList::PopBack() {
if (head_ == NULL) {
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
  bool isFound;
  
  DLNode* temp;
  while (temp != NULL) {
    temp = temp->GetNext();
    
    if (temp->GetContents() == to_find) {
      isFound = true;
    } else {
      isFound = false;
    }
  }
}

void DLList::RemoveFirst(int to_find) {
 /* DLNode* temp;
  while(temp != to_find) {
    temp = temp->GetNext()->GetContents();
  }
  temp->SetPrevious(temp->GetNext());*/
}

void DLList::RemoveAll(int num) {
  
}

void DLList::Clear() {
    if (head_ == NULL) {
    size_ = 0;

  } else if (head_!= NULL && head_->GetNext() == NULL) {
  delete head_;
  head_ = NULL;
  tail_ = NULL;
  size_ -=1;

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
  return head_->GetContents();
}

int DLList::GetBack() {
  return tail_->GetContents(); 
}

unsigned int DLList::GetSize() const {
  return size_; 
}

//outputters
string DLList::ToStringBackwards() {
  
}

string DLList::ToStringForwards() {
  
}

