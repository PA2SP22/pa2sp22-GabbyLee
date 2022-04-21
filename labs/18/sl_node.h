
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

 public:
// Default constructor
SLNode();

// Overloaded constuctor
SLNode(int contents);

// Empty destructor
~SLNode();

// Mutator functions
void set_contents(int contents);

void set_next_node(SLNode* next);

// Accessor functions
int contents() const;

SLNode* next_node() const;

 private:
SLNode* next_node_;
int contents_;

};
#endif
