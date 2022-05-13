#include "sl_list.h"

// Function interface:

// Default constructor, sets values head_(NULL) and size_(0)
SLList::SLList() {
  head_ = NULL;
  tail_ = NULL;
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
    tail_= head_;
    size_ = size_ + 1;
    } else {
  SLNode* new_node = new SLNode(contents);
  new_node->set_next_node(head_);
  head_ = new_node;
  size_ = size_ + 1;
    }
  }

void SLList::InsertTail(int contents) {
if (head_ == NULL) {
head_ = new SLNode(contents);
tail_ = head_;
size_ = size_ + 1;
}  else {
    SLNode* new_node = new SLNode(contents);
    tail_->set_next_node(new_node);
    tail_ = new_node;
    size_ = size_ + 1;
    }
}
/*void Insert(int contents) {
 while(temp != tail_){
   if()
 }
}


bool RemoveFirstOccurence() {
int count;
bool isDone = false;
  if (size_== 0) {
  } else {
  SLNode* temp = head_->contents();
   while(temp != to_remove) {
   temp = temp->next_node()->contents;
   if( temp == to_remove){
     delete temp;
     temp = temp->next_node();
     isDone = true;
   } else {
     isDone = false;
   }

 }
 
}
}/*

// Remove head
void SLList::RemoveHead() {
  if (head_ == NULL) {
  size_ = 0;
// If the is only one element in the list
  } else if (head_ != NULL && head_->next_node() == NULL) {
    delete head_;
    head_ = NULL;
    tail_= NULL;
    size_ -=1;

// If there are multiple elements in list
  } else {
    SLNode* temp = head_;
    head_ = head_-> next_node();
    delete temp;
    temp = NULL;
    size_ = size_ - 1;
    }
}

void SLList::RemoveTail() {
    if (head_ == NULL) {
  size_ = 0;
  } else if (head_!= NULL && head_->next_node() == NULL) {
  RemoveHead();
  } else {
     SLNode* temp = head_;
     SLNode* prev;

  while (temp != tail_) {
    prev = temp;
    temp = temp->next_node();
  }
    tail_ = prev;
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
if (head_ == NULL) {
to_return = 0;
} else {
to_return = tail_->contents();
}
return to_return;
}


// Clear the entire list
void SLList::Clear() {
  // if the list is empty;
  if (head_ == NULL) {
    size_ = 0;

  } else if (head_!= NULL && head_->next_node() == NULL) {
  delete head_;
  head_ = NULL;
  tail_ = NULL;
  size_ -=1;

  } else {
    while (head_ != NULL) {
      SLNode* temp = head_;
      head_ = head_->next_node();
      delete temp;
      size_-=1;
    }
    head_ = NULL;
    tail_= NULL;
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

if (size == 0) {
  ss << "";
} else {
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
}

str = ss.str();
return str;
}
