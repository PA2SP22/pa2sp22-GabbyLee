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

void Clear();

unsigned int GetSize() const;
	
string InOrder();
	
private:
BSTNode* root;
unsigned int size; 


bool Insert (int contents, BSTNode*& root); 
	
void Clear (BSTNode*& root);
	
string InOrder(BSTNode*& root);

};
#endif