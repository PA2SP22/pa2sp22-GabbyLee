class name: SLList

private data members:

	head_, SLNode* that points to the first node in a singly-linked list
	size_, unsigned int the count of the number of nodes in the list

public function interface:

	default constructor, sets values head_(NULL) and size_(0)
	SLList::SLList(){
	    
	}
	
	destructor, calls the clear function
	
	void InsertHead(int), create a new dynamic SLNode with the contents of 
						  the parameter and attach as head of list
	void SLList::InsertHead(int contents){
	    
	}
	
	void RemoveHead(), remove the head node from the list, or does nothing if
					   the list is empty
	voide SLList::RemoveHead(){
	    
	}
	void Clear(), clear the entire contents of the list, freeing all memory
	              associated with all nodes
	void SLList::Clear(){
	    
	}
	unsigned int size() const{
	    
	}
	
	string ToString() const, 
	
	} return a string representation of the contents
	                          of all nodes in the list, in the format
	                          NUM1, NUM2 , ..., LASTNUM
							  return empty string on empty list