/*
 * Name        : bs_treet.h
 * Author      : Gabrielle Lee
 * Description : Assignment_5
 */
#ifndef Lee_BS_Treet_H_
#define Lee_BS_Treet_H_


#include <iostream>
#include <string>
#include <sstream>
#include "bs_nodet.h"
using std::cout;
using std::endl;
using std::string;
using std::stringstream;


template <typename T>
class BSTreeT {

// Constuctors and Destructor
 public:
BSTreeT();
 
~BSTreeT();


// Helper Setters
void Clear();

int Insert(T add);

int Remove(T to_del);


// Helper Checkers
bool Exists(T to_find);


// Helper Getters
unsigned int GetSize() const;

BSTNodeT<T>* Get(T to_get);


// Helper printers
string ToStringForwards();

string ToStringBackwards();


// Private Functions
private:
  BSTNodeT<T>* root_;
  int size_ = 0;

// Setters
void Clear(BSTNodeT<T>*& subroot);

int Insert(T add, BSTNodeT<T>*& subroot);

int Remove(T to_del, BSTNodeT<T>*& subroot);


//Getters
BSTNodeT<T>* Get(T to_get, BSTNodeT<T>*& subroot);


// Checker Functions
bool Exists(T to_find, BSTNodeT<T>*& subroot);

// Printers
string ToStringForwards(BSTNodeT<T>*& subroot);

string ToStringBackwards(BSTNodeT<T>*& subroot);
};

#endif