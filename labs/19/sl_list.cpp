#include "sl_list.h"

// Function interface:

// Default constructor, sets values head_(NULL) and size_(0)
SLList::SLList() {
  head_ = NULL;
  size_ = 0;
}

// Destructor, calls the clear function
SLList::~SLList() {
Clear();
}

// Insert head
void SLList::InsertHead(int contents) {
// If list is empty
  if (head_ == NULL && tail_ == NULL) {
    head_ = new SLNode(contents);
    size_ = size_ + 1;
    } else {
  SLNode* new_node = new SLNode(contents);
  new_node->set_next_node(head_);
  head_ = new_node;
    size_ = size_ + 1;
    }

  }
  
  
	void SLList::InsertTail(int contents) {
	  
if (head_ == NULL && tail_ == NULL) {
tail_ = new SLNode(contents);
size_ = size_ + 1;
      
} else if (head_ != NULL && tail_ == NULL) {
      
SLNode* new_node = new SLNode(contents);
SLNode* temp;
temp = head_;
while (temp != NULL) { 
temp = temp->next_node();
if (temp == NULL) {
temp =  new_node;
tail_ = temp;
size_ = size_ + 1;
}
}
}  else {
  SLNode* new_node = new SLNode(contents);
  SLNode* temp = tail_; 
  temp->set_next_node(new_node);
  tail_ = new_node;
  size_ = size_ + 1;
}
}

// Remove head
void SLList::RemoveHead() {
  if (head_ == NULL) {
  size_ = 0;

  } else if (head_ != NULL && head_->next_node() == NULL) {
    delete head_;
    head_ = NULL;
    size_ -=1;
    head_ = NULL;

  // If there are multiple elements in list
  } else {
    SLNode* temp = head_;
    head_ = head_-> next_node();
    delete temp;
    size_ = size_ - 1;
    }
}

void SLList::RemoveTail() {
  
    if (head_ == NULL || tail_ == NULL) {
  size_ = 0;
  

  } else if (size_ == 1 && tail_ != NULL) {
    delete tail_;
    tail_ = NULL;
    size_ = size_-1;
    
  } else {
     SLNode* prev = head_;
     SLNode* temp = head_;
     
    while(temp->next_node()!= NULL) {
    prev = temp; 
    temp = temp->next_node();
    }
    delete tail_;
    tail_ =NULL;
    delete temp;
    temp = NULL;
    tail_ = prev;
    size_ = size_-1;
    
  }
}



int SLList::GetHead() const {
  int to_return;
  
  if (head_ == NULL) { 
  to_return = 0; 
  } else { 
    to_return = head_->contents();
  }
  
  return to_return;
  
}


int SLList::GetTail() const {
 int to_return;
if (head_ == NULL){
  to_return = 0; 
} else {
  to_return = tail_->contents();
} 
return to_return;
  
}


// Clear the entire list
void SLList::Clear() {
  // if the list is empty;
  if (head_ == NULL && tail_ == NULL) {
    size_ = 0;

  } else if (head_ != NULL && tail_ != NULL) {
    SLNode* temp = head_;
    
    while (head_ != tail_) {
      head_ = head_->next_node();
      delete temp;
      temp = NULL;
      temp = head_;
      size_-=1;
    }
    delete tail_;
    tail_ = NULL;
  }
 
  
}

unsigned int SLList::size() const {
  return size_;
}
// ToString to print list
string SLList::ToString() const {
std::stringstream ss;
string str;
unsigned int size = size_;

  SLNode* current_node = head_;

for(unsigned int i = 0; i < size; i++) {
if (current_node == NULL) {
ss << "";
}
if (i == (size - 1)) {
ss << current_node->contents();
} else {
ss << current_node->contents() << ", ";
current_node = current_node->next_node();
}
}

str = ss.str();
return str;
}
