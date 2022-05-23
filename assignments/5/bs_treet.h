#include <iostream>
#include <string>
#include <sstream>
#include "bs_nodet.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream



#ifndef Lee_BS_Treet_H_
#define Lee_BS_Treet_H_

template <class T>

class BSTreeT {

  
  
 public:
BSTree();
 
~BSTree();

unsigned int GetSize() const;

void Clear();

bool Insert(int add);

bool Exsist(to_find);

int Remove(to_del);

BSTreeT<T>* Get(to_find);

string ToStringForwards();

string ToStringBackwards();


private:
  BSTreeT<T>* root_;
  int size_ = 0;
 
void Clear();

bool Insert(int add, BSTNode*&<T> subroot);

bool Remove(int contents, BSTNode*&<T> subroot);

BSTreeT<T>* Get(BSTNode* subroot);

int Exsist(BSTNode*<T> subroot);

void Clear(BSTNode*&<T> subroot);

string ToStringForwards(BSTNode*&<T> subroot);

string ToStringForwards(BSTNode*&<T> subroot);

};

#endif