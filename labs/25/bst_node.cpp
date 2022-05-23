#include "bst_node.h"

BSTNode::BSTNode() {
  leftChild_ = NULL;
  rightChild_ = NULL;
  contents_ = 0;
}

BSTNode::BSTNode(int data) {
  leftChild_ = NULL;
  rightChild_ = NULL;
  contents_ = data;
}
BSTNode::~BSTNode() {
  // Luke: Let the tree delete the node
  // delete leftChild_;
  leftChild_ = NULL;
  // Luke: Let the tree delete the node
  // delete rightChild_;
  rightChild_ = NULL;
}


// Setters
void BSTNode::SetContents(int data) {
contents_ = data;
}

void BSTNode::SetLeftChild(BSTNode* link) {
leftChild_ = link;
}

void BSTNode::SetRightChild(BSTNode* link) {
rightChild_ = link;
}


// Getters
int BSTNode::GetContents() const {
return contents_;
}

int& BSTNode::GetContents() {
return contents_;
}

BSTNode* BSTNode::GetLeftChild() const {
return leftChild_;
}

BSTNode*& BSTNode::GetLeftChild() {
return leftChild_;
}

BSTNode* BSTNode::GetRightChild() const {
return rightChild_;
}

BSTNode*& BSTNode::GetRightChild() {
return rightChild_;
}
