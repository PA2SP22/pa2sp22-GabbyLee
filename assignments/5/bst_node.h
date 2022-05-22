#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

#ifndef Lee_BST_Node_H_
#define Lee_BST_Node_H_


template<typename t>
class BSTNode{
private:
BSTNodeT* leftChild;
BSTNode* rightChild;
 public:
 
BSTNode();

BSTNode(int data);
 
~BSTNode();
 
 //Setters
void SetContents(int data);
 
void SetLeftChild(BSTNode* link);

void SetRightChild(BSTNode* link);
 
// Getters
int GetContents() const;
  
int& GetContents();
 
BSTNode* GetLeftChild() const;
  
BSTNode*& GetLeftChild();
	
BSTNode* GetRightChild() const;
	
BSTNode*& GetRightChild();
  
};
#endif