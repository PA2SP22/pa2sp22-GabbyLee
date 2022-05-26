#include "bs_nodet.h"
#include <iostream>
/*
 * Name        : bs_nodet.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment_5
 */

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
 
 //Setters
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