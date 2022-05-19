BSTNode::BSTNode() {
  leftChild = NULL;
  rightChild = NULL;
  contents = 0; 
}

BSTNode::BSTNode(int data) {
  leftChild = NULL;
  rightChild = NULL;
  contents = data; 
}
BSTNode::~BSTNode() {
  delete leftChild;
  leftChild = NULL;
  
  delete rightChild;
  rightChild = NULL;
}
 
 //Setters
void BSTNode::SetContents(int data) {
  contents = data;
}
 
void BSTNode::SetLeftChild(BSTNode* link) {
  leftChild = link;
}

void BSTNode::SetRightChild(BSTNode* link) {
  rightChild = link;
}
 
// Getters
int BSTNode::GetContents() const {
  return contents;
}
  
int& BSTNode::GetContents() {
  return contents;
}
 
BSTNode* BSTNode::GetLeftChild() const {
  return leftChild;
}
  
BSTNode*& BSTNode::GetLeftChild() {
  return leftChild;
}
	
BSTNode* BSTNode::GetRightChild() const {
  return rightChild;
}
	
BSTNode*& BSTNode::GetRightChild() {
  return rightChild;
}