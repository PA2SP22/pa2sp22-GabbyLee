
/*
 * Name        : sl_node.h
 * Author      : Gabrielle Lee
 * Description : Linked List Header File
 *
 */
 #include<iostream>
 

#ifndef Lee_SLNode_H_
#define Lee_SLNode_H_

// ADD HEADER GUARD HERE
class SLNode {
private:
 SLNode* next_node_;
 int contents_;	
 
public:
//Default constructor
SLNode();
// overloaded constuctor
SLNode(int contents);
//empty destructor
~SLNode();	

//mutator functions
void set_contents (int contents);

void set_next_node(SLNode* next);

//accessor functions 
int contents() const;

SLNode* next_node() const;


};  
#endif