/*
*
*
*   help   https://github.com/PA2SP22/pa2sp22-Adolin42/blob/main/labs/25/bs_tree.cpp
*/


#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;
using std::cout;
using std::endl;
#include "bst_node.h"


#ifndef Lee_BS_Tree_Node_H_
#define Lee_BS_Tree_Node_H_

class BSTree {
 public:
BSTree();

~BSTree();

bool Insert(int contents);

bool Remove(int contents) ;

int FindMin();

void Clear();

unsigned int GetSize() const;

string InOrder();

 private:
BSTNode* root_;
unsigned int size_;

bool Insert(int contents, BSTNode*& subroot);

bool Remove(int contents, BSTNode*& subroot);

int FindMin(BSTNode* subroot);

void Clear(BSTNode*& subroot);

string InOrder(BSTNode*& subroot);
};

#endif
