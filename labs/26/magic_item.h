/*
 * Name        : magic_item.h
 * Author      : Gabrielle Lee
 * Description : Working on Inheritance
 */

#include "item.h"
#ifndef Lee_MAGITEM_H_
#define Lee_MAGITEM_H_

#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

class MagicItem : public Item {
 public:
// Constructor / Destructor
MagicItem();

MagicItem(string name, unsigned int value,
           string descript, unsigned int mana_required);

~MagicItem();

// Setters
void set_description(string descript);

void set_mana_required(unsigned int mana);

// Getters
string description();

unsigned int mana_required();

// public function
string ToString();

 private:
string description_;
unsigned int mana_required_;
};

#endif
