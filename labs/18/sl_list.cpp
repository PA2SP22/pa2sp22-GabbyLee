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
    } else  {
// If list has multiple items and size is lower than 500
   if(size_ > 499) {
    cout<< "HIGH LOAD"<<endl;
  } else {
  SLNode* temp = new SLNode(contents);
  temp->set_next_node(head_);
  head_ = temp;
    size_++;
 
    }
  }
}

// Remove head
void SLList::RemoveHead() {
  if (head_ == NULL) {
  }
  // If only one element in list
  else if (head_ != NULL && head_->next_node() == NULL) {
    delete(head_);

  // If there are multiple elements in list 
  } else if (head_ != NULL && head_->next_node() != NULL) {
    SLNode* temp = head_;
    head_ = head_->next_node();
    delete(temp);
    }
}
// Clear the entire list
void SLList::Clear() {
  // if the list is empty;
  if (head_ == NULL){
    }
  // cout << "The list is empty";
 // If there is only one element in the list
 /* } else if (head->next_node() == NULL) { 
    head_->set_contents(0);
    delete head;
*/// If there is just one items in list
  else if (head_->next_node() == NULL){
    delete head_;
    head_ = NULL;
    
  } else {
    SLNode *temp, *nxt;
    temp = head_;
    nxt = head_->next_node();
    while (temp != NULL){
      delete temp;
      temp = nxt->next_node();
      nxt = temp->next_node();
    }
 // delete(previous_node);
  }
} 
unsigned int SLList::size() const {
  return size_;
}
// ToString to print list
string SLList::ToString() const {
	std::stringstream ss;
  string str;
  
  
  if (head_ == NULL) {
    ss<<"aa  ";
  }
  if (head_ != NULL) {
  SLNode* current_node = head_; 
		while(current_node != NULL) {
     ss << current_node->contents() << ", ";
		 }
	}
  str = ss.str();
  //  unsigned sz = str.size();

 
	return str;
} 
/*return a string representation of the contents
	                          of all nodes in the list, in the format
	                          NUM1, NUM2 , ..., LASTNUM
							  return empty string on empty list*/