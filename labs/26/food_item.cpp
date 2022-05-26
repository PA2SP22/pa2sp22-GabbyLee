/*
 * Name        : lab_26.cpp
 * Author      : Gabrielle Lee
 * Description : Working on Inheritance
 */

#include "food_item.h"
// constuctor / destructor
FoodItem::FoodItem() {
set_name("fooditem");
set_value(0);
calories_ = 0;
unit_of_measure_ = "nounits";
units_ = 0.0;
}

FoodItem::FoodItem(string name, unsigned int value,
               unsigned int calories, string unitM , double units ) {
set_name(name);
set_value(value);
calories_ = calories;
unit_of_measure_ = unitM;
units_ = units;
}

FoodItem::~FoodItem() {
}

// setters
void FoodItem::set_calories(unsigned int calories) {
calories_ = calories;
}

void FoodItem::set_unit_of_measure(string unitM) {
unit_of_measure_ = unitM;
}

void FoodItem::set_units(double units) {
units_ = units;
}

// Getters

unsigned int FoodItem:: calories() {
return calories_;
}

double FoodItem::units() {
return units_;
}

string FoodItem::unit_of_measure() {
return unit_of_measure_;
}

// public function
string FoodItem::ToString() {
stringstream print;
print.setf(std::ios::showpoint | std::ios::fixed);
print.precision(2);
print <<Item::ToString();
print << ", " << units() <<" " << unit_of_measure();
print << ", " << calories() << " calories";
return print.str();
}
