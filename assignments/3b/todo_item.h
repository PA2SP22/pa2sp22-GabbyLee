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
/*In this lab you will be creating a TodoList application. The application will allow you to 
add/edit/delete Todo Items from a Todo List. You will end up with three classes, TodoItem, 
TodoList and TodoUI. 
 
For Part B (This Assignment) you will be creating a TodoList class that will create dynamic 
instances of TodoItems. You will be using the TodoItem class you created from Part A for this 
assignment. 
 
The TodoItem class has already been created for you and will be used by the TodoList class. 
The TodoList class will create dynamic instances of TodoItems. 
 
You will turn your assignment in by adding/committing/pushing to GitHub 
 
Class - TodoList 
This is the data manager class. Contains a dynamic array of dynamic TodoItems 
 
Private Data Members: A pointer that can point to a dynamic array of TodoItem*  
- The type of this pointer should be TodoItem** 
An unsigned integer to hold the maximum capacity of your list 
An unsigned integer to hold the current size of your list 
 
Constructor: Creates a dynamic array of 25 elements and initializes the elements 
to NULL 
 
Destructor: Frees the memory for all TodoItems 
Frees the memory for the dynamic TodoItem* array 
 
Member Function 1: Named AddItem. Has one parameter, a dynamic instance of 
TodoItem (i.e. TodoItem*). If there is room in the array add the new 
dynamic instance to the first available spot (i.e. the current size). If 
the array is full, increase capacity by 10 and then add the item. */
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

string Scrub(string to_scrub);

 private:
string description_;
int priority_;
bool completed_;
#endif
};
