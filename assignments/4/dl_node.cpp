/*
 * Name        : dl_node.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment_4
 */

#include "dl_node.h"
#include <iostream>

 // Constructor
 DLNode::DLNode() {
   contents_ = 0;
   prev_ = NULL;
   next_ = NULL;
 }
 
  DLNode::DLNode(int contents) {
   contents_ = contents;
   prev_ = NULL;
   next_ = NULL;
 }
 // Destructor
DLNode::~DLNode() {
 }
 
 // Setters
void DLNode::SetContents(int contents) {
  contents_ = contents;
}
void DLNode::SetNext(DLNode* node) {
  next_ = node;
}

void DLNode::SetPrevious(DLNode* node) {
  prev_ = node; 
}

 // Getters 
int DLNode::GetContents() const {
  return contents_;
}

DLNode* DLNode::GetNext() const {
  return next_;
}

DLNode* DLNode::GetPrevious() const {
  return prev_; 
}
 
