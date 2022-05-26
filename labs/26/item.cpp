/*
 * Name        : lab_26/item.cpp
 * Author      : Gabrielle Lee
 * Description : Working on Inheritance
 */


#include "item.h"

// constuctors /destructor
Item::Item() {
name_ = "item";
value_ = 0;
}

Item::Item(string name, unsigned int value) {
name_ = name;
value_ = value;
}

Item::~Item() {
}

// Setters
void Item::set_name(string name) {
name_ = name;
}

void Item::set_value(unsigned int num) {
value_ = num;
}

// Getters
string Item::name() {
return name_;
}

unsigned int Item::value() {
return value_;
}

string Item::ToString() {
stringstream print;
print.setf(std::ios::showpoint | std::ios::fixed);
print.precision(3);
print << name() << ", $" << value();
return print.str();
}
