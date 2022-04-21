/*
 * Name        : sl_node.cpp
 * Author      : Gabrielle Lee
 * Description : Linked List class definitions File
 *
 */
#include "sl_node.h"


// Default constructor
SLNode::SLNode() {
    next_node_ = NULL;
    contents_ = 0;
}
// Overloaded Constuctor
SLNode::SLNode(int contents) {
  contents_ = contents;
  next_node_ = NULL;
}
// Empty destructor
SLNode::~SLNode{
}

// Mutator Functions
void SLNode::set_contents(int contents) {
  contents_ = contents;
}

void SLNode::set_next_node(SLNode* next) {
  next_node_ = next;
}

// Accessor functions
int SLNode::contents() const {
  return contents_;
}

SLNode* SLNode::next_node() const {
  return next_node_;
}

