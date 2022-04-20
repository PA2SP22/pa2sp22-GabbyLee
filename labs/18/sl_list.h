/*
 * Name        : sl_list.h
 * Author      : Gabrielle Lee
 * Description : Lab_18
 */
#include "sl_node.h"
#include "sl_node.cpp"
#include <iostream>
#include <iterator>
#include <stringstreams>
using std::cout;
using std::endl;
using std::string;


#ifndef Lee_SLList_H_
#define Lee_SLList_H_


class SLList {

private:

SLList head_,
unsigned int size_,

public:
// constructor
  SLList(head_= NULL, size = 0);

// destructor
  ~SLList();

 void SLList::InsertHead(int contents);

 void RemoveHead();
 
 void Clear(); 
 
 unsigned int size() const;
	
 string ToString() const;

} 
#endif
