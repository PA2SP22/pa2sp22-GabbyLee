#include <iostream>
using std::endl;


#ifndef Lee_BST_Node_H_
#define Lee_BST_Node_H_

class BSTNode {
 public:
BSTNode();

BSTNode(int data);

~BSTNode();

// Setters
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

 private:
BSTNode* leftChild_;
BSTNode* rightChild_;
int contents_;
};

#endif
