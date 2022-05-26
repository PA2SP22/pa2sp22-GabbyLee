/*
 * Name        : lab_26.cpp
 * Author      : Gabrielle Lee
 * Description : Working on Inheritance
 */

#include "item.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

#ifndef Lee_FOODITEM_H_
#define Lee_FOODITEM_H_

class FoodItem : public Item {
 public:
// constuctor /destructor
FoodItem();

FoodItem(string name, unsigned int value, unsigned int calories,
                                   string unitM , double units);

~FoodItem();

// setters
void set_calories(unsigned int calories);

void set_unit_of_measure(string unitM);

void set_units(double units);

// Getters

unsigned int calories();

double units();

string unit_of_measure();

// public function
string ToString();

 private:
unsigned int calories_;
double units_;
string unit_of_measure_;
};

#endif
