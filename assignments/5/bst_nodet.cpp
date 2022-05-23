#include

template<typename T>
BSTNodeT<T>::BSTNode() {
  leftChild = NULL;
  rightChild = NULL;
  contents = 0; 
}

template<typename T>
BSTNodeT<T>::BSTNode(int data) {
  leftChild = NULL;
  rightChild = NULL;
  contents = data; 
}

template<typename T>
BSTNodeT<T>::~BSTNode() {
  delete leftChild;
  leftChild = NULL;
  
  delete rightChild;
  rightChild = NULL;
}
 
 //Setters
 template<typename T>
void BSTNodeT<T>::SetContents(int data) {
  contents = data;
}
 template<typename T>
void BSTNodeT<T>::SetLeftChild(BSTNode* link) {
  leftChild = link;
}
template<typename T>
void BSTNodeT<T>::SetRightChild(BSTNode* link) {
  rightChild = link;
}
 
// Getters
template<typename T>
int BSTNodeT<T>::GetContents() const {
  return contents;
}
template<typename T>
int& BSTNodeT<T>::GetContents() {
  return contents;
}
template<typename T>
BSTNodeT<T>* BSTNodeT<T>::GetLeftChild() const {
  return leftChild;
}
template<typename T>
BSTNode*&T<T> BSTNodeT<T>::GetLeftChild() {
  return leftChild;
}
template<typename T>
BSTNode*T<T> BSTNodeT<T>::GetRightChild() const {
  return rightChild;
}
template<typename T>
BSTNodeT*&<T> BSTNodeT<T>::GetRightChild() {
  return rightChild;
}