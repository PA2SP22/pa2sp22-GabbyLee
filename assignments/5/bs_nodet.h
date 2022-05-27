/*
 * Name        : bs_nodet.h
 * Author      : Gabrielle Lee
 * Description : Assignment_5
 */
#ifndef Lee_BST_Node_H_
#define Lee_BST_Node_H_

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


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
template<typename T>
BSTNodeT<T>::BSTNodeT() {
  leftChild = NULL;
  rightChild = NULL;
  contents = T();
  nodeCount = 0;
}
template<typename T>
BSTNodeT<T> ::BSTNodeT(T data) {
  leftChild = NULL;
  rightChild = NULL;
  contents = data;
  nodeCount = 0;
}
template<typename T>
BSTNodeT<T>::~BSTNodeT() {
  leftChild = NULL;
  rightChild = NULL;
}

// Setters
template<typename T>
void BSTNodeT<T>::SetContents(T data) {
  contents = data;
}
template<typename T>
void BSTNodeT<T>::SetLeft(BSTNodeT<T>* link) {
  leftChild = link;
}
template<typename T>
void BSTNodeT<T>::SetRight(BSTNodeT<T>* link) {
rightChild = link;
}

// counters
template<typename T>
void BSTNodeT<T>::IncreaseCount() {
nodeCount += 1;
}

template<typename T>
void BSTNodeT<T>::DecreaseCount() {
nodeCount -= 1;
}


// Getters
template<typename T>
T BSTNodeT<T>::GetContents() const {
  return contents;
}
template<typename T>
BSTNodeT<T>* BSTNodeT<T>::GetLeft() const {
  return leftChild;
}
template<typename T>
BSTNodeT<T>*& BSTNodeT<T>::GetLeft() {
  return leftChild;
}
template<typename T>
BSTNodeT<T>* BSTNodeT<T>::GetRight() const {
  return rightChild;
}
template<typename T>
BSTNodeT<T>*& BSTNodeT<T>::GetRight() {
  return rightChild;
}
template<typename T>
int BSTNodeT<T>::GetCount() const {
return nodeCount;
}

#endif
