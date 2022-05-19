/*
 * Name        : dl_list.h
 * Author      : Gabrielle Lee
 * Description : Assignment_4
 */

#include <iostream>
#include <string>
#include <sstream>
#include "dl_node.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

#ifndef Lee_DLList_H_
#define Lee_DLList_H_

class DLList {
  private: 
  unsigned int size_;
  DLNode* head_;
  DLNode* tail_; 
  

 public: 

DLList();

~DLList();

void PushFront(int contents);

void PushBack(int contents);

void PopFront(); 

void PopBack();

bool Exists(int to_find);

void RemoveFirst(int to_find);

void RemoveAll(int num);

void Clear();

int GetFront(); 

int GetBack();

unsigned int GetSize() const;

string ToStringBackwards();

string ToStringForwards();
};

#endif

