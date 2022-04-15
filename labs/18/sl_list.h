





class SLList{

private 

	head_, SLNode* that points to the first node in a singly-linked list
head_,	size_, unsigned int the count of the number of nodes in the list
size_,

public:
//constructor
SLList(head_=NULL, size = 0);
	default constructor, sets values head_(NULL) and size_(0)
	
	destructor, calls the clear function
	
	void InsertHead(int); treate a new dynamic SLNode with the contents of 
						  the parameter and attach as head 
}
	
	void RemoveHead(); emove the head node from the list, or does nothing if
					   the list is empty
	
	void Clear(), clear the entire contents of the list, freeing all memory
	              associated with all nodes
	
	unsigned int size() const
	
	string ToString() const, return a string representation of the contents
	                          of all nodes in the list, in the format
	                          NUM1, NUM2 , ..., LASTNUM
							  return empty string on empty list