/*
 * Name        : lab_26.cpp
 * Author      : Gabrielle Lee
 * Description : Working on Inheritance
 */

#ifndef Lee_ITEM_H_
#define Lee_ITEM_H_

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class Item {
 public:
// constuctors /destructor
Item();

Item(string name, unsigned int value);

~Item();

// Setters
void set_name(string name);

void set_value(unsigned int num);

// Getters
string name();

unsigned int value();

string ToString();

 private:
string name_;
unsigned int value_;
};

#endif
