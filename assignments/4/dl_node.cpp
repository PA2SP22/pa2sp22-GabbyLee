/*
 * Name        : dl_node.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment_4
 */

#include "dl_node.h"
#include <iostream>

 // Constructor
 DLNode::DLNode() {
   contents = 0;
   prev = NULL;
   next = NULL;
 }
 
  DLNode::DLNode(int contents) {
   contents =contents;
   prev = NULL;
   next = NULL;
 }
 // Destructor
DLNode::~DLNode() {
 }
 
 // Setters
void DLNode::SetContents(int contents) {
  contents = contents;
}
void DLNode::SetNext(DLNode* node) {
  next = node;
}

void DLNode::SetPrevious(DLNode* node) {
  prev = node; 
}

 // Getters 
int DLNode::GetContents() {
  return contents;
}

DLNode* DLNode::GetNext() const {
  return next;
}

DLNode* DLNode::GetPrevious() const {
  return prev; 
}
 
