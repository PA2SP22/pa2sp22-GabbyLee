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
 public:
 
BSTNodeT();

BSTNodeT(int data);
 
~BSTNodeT();
 
 //Setters

void SetContents(int data);
 
void SetLeftChild(BSTNode* link);

void SetRightChild(BSTNode* link);
 
// Getters
int GetContents() const;
  
int& GetContents();
 
BSTNodeT<T>* GetLeftChild() const;
  
BSTNodeT<T>*& GetLeftChild();
	
BSTNodeT<T>* GetRightChild() const;
	
BSTNodeT<T>*& GetRightChild();
  
};
#endif