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
void SLList::InsertHead(int contents){
// If list is empty
   if (head_ == NULL) {
    head_ = new SLNode(contents);
    size_ = size_ + 1;
    } else {
  SLNode* new_node = new SLNode(contents);
  new_node->set_next_node(head_);
  head_ = new_node;
    size_ =size_ + 1;
    }
  }


// Remove head
void SLList::RemoveHead() {
  if (head_ == NULL) {
   size_ = 0; 
  }
  // If only one element in list
  else if (head_ != NULL && head_->next_node() == NULL) {
    delete head_;
    size_ -=1;
    // Luke: You also need to set head_ back to NULL
    head_ = NULL;

  // If there are multiple elements in list 
  } else {
    SLNode* temp = head_;
    head_ = head_->next_node();
    delete temp;
    size_ = size_ - 1;
    }
}


// Clear the entire list
void SLList::Clear() {
  // if the list is empty;
  if (head_ == NULL) {
    size_ = 0;
    }

  else if (head_!= NULL && head_->next_node() == NULL){
   delete head_;
    size_ -=1;
    // Luke: You also need to set head_ back to NULL
    head_ = NULL;
    
  } else {
    while (head_ != NULL) {
      SLNode* temp = head_;
      head_ = head_->next_node();
      delete temp;
      size_-=1;
    }
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
  // Luke: This part isn't needed
  /*
  if (size_>= 500 && size_< 1000){
       ss<< "High Load / 2";
       size = size_/2;
     } else {
       size = size_;
     }
  */
  SLNode* current_node = head_; 
  
		for(unsigned int i = 0; i<size; i++) {
		  if (current_node == NULL ){
		    ss<<"";
		  }
		  if (i == (size - 1) ) {
		    ss << current_node->contents();
		} else {
     ss << current_node->contents() << ", ";
     current_node = current_node->next_node();
		}
	}

 str = ss.str();
	return str;
} 
