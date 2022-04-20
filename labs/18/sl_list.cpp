#include "sl_list.h"

private:

// function interface:
public: 

	//default constructor, sets values head_(NULL) and size_(0)
	
	SLList::SLList() {
	    head_ = NULL;
	    size_ = 0;
	}
	
	//destructor, calls the clear function
	SLList::~SLList{
		
	}
	
	
	void SLList::InsertHead(int contents){
         head_ = SLNode(contents);                   //, create a new dynamic SLNode with the contents of 
	  	                                           //the parameter and attach as head of list

	}

  //remove the head node from the list, or does nothing if
					   //the list is empty
	void SLList::RemoveHead() {
		
      if head = NULL;) {
      	break;
      } else {
      	head = NULL;
   
      }
	    
	}
	// clear the entire contents of the list, freeing all memory associated with all nodes
	
	void SLList::Clear(){
	    
	}
	unsigned int size() const{
	    
	}
	
	string ToString() const, 
	stringstream ss;
	
	while head!= NULL;
	
	} return a string representation of the contents
	                          of all nodes in the list, in the format
	                          NUM1, NUM2 , ..., LASTNUM
							  return empty string on empty list