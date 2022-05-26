/*
 * Name        : bs_nodet.h
 * Author      : Gabrielle Lee
 * Description : Assignment_5
 */

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

#ifndef Lee_BST_Node_H_
#define Lee_BST_Node_H_



template<typename T>
class BSTNodeT {
    
 private:
BSTNodeT<T>* leftChild;
BSTNodeT<T>* rightChild;
int nodeCount; 
T contents;
 public:
 
// constructors /destructor

BSTNodeT();

BSTNodeT(T data);
 
~BSTNodeT();
 
// Setters

void SetContents(T data);
 
void SetLeft(BSTNodeT<T>* link);

void SetRight(BSTNodeT<T>* link);

void IncreaseCount();

void DecreaseCount();
 
// Getters

T GetContents() const;

  
BSTNodeT* GetLeft() const;
  
BSTNodeT*& GetLeft();
	
BSTNodeT* GetRight() const;
	
BSTNodeT*& GetRight();

int GetCount() const;


};
#endif