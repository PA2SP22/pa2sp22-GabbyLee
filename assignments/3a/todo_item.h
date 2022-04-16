/*
 * Name        : lab_13.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment 3a
 */
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
using std::stringstream;
using std::string;
using std::ostream;
using std::cout;
using std::endl;

// HEADER GUARD
#ifndef Lee_Todo_item_H_
#define Lee_Todo_item_H_

class TodoItem {
 public:
TodoItem(string description, int priority = 1, bool completed = false);

// Mutators
void set_description(string description);

void set_priority(int priority);

void set_completed(bool compled);

// Accessors
string description() const;

int priority() const;

bool completed() const;

string ToFile();


 private:
string Scrub(string to_scrub);
string description_;
int priority_;
bool completed_;
};

#endif

