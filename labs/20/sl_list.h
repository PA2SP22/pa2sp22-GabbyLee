/*
 * Name        : sl_list.h
 * Author      : Gabrielle Lee
 * Description : Lab_18
 */
#include "sl_node.h"
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::string;


#ifndef Lee_SLList_H_
#define Lee_SLList_H_


class SLList {
 public:
// constructor
  SLList();

// destructor
  ~SLList();

void InsertHead(int contents);

void InsertTail(int contents);

void Insert(int contents);

void RemoveHead();

void RemoveTail();

int GetHead() const;

int GetTail() const;

void Clear();

unsigned int size() const;

string ToString() const;

 private:
SLNode* head_;
SLNode* tail_;
unsigned int size_;
};
#endif
