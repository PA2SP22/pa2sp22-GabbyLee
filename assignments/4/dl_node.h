/*
 * Name        : dl_node.h
 * Author      : Gabrielle Lee
 * Description : Assignment_4
 */

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

#ifndef Lee_DLNode_H_
#define Lee_DLNode_H_

class DLNode {
 private: 
  int contents_;
  DLNode* prev_; 
  DLNode* next_;
  
 public:
 
// Constructor
DLNode();
 
DLNode(int contents);
 
// Destructor
~DLNode();
 
// Setters
void SetContents(int contents);

void SetNext(DLNode* node);

void SetPrevious(DLNode* node);

// Getters 
int GetContents() const;

DLNode* GetNext() const;

DLNode* GetPrevious() const; 
 
}; 

#endif