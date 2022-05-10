/*
 * Name        : lab_3b_todo_list.h
 * Author      : Gabrielle Lee
 * Description : Assignment 3c
 */
#include <iostream>
#include <string>
#include <sstream>
#include <ostream>
#include <cstdlib>
using std::stringstream;
using std::string;
using std::ostream;
using std::cout;
using std::endl;
#include "todo_item.h"

// HEADER GUARD
#ifndef Lee_Todo_list3c_H_
#define Lee_Todo_list3c_H_

class TodoList {
 private:
TodoItem** items_array;
unsigned int current_size;
unsigned int max_capacity;

// Private Member fucntion 1: Increasing size
void IncreaseSize();

// Private Member Function 2: Compacting size
void CompactSize(int to_delete);


 public:
TodoList();

~TodoList();

// Member function 1
void AddItem(TodoItem* item);

// Member function 2
void DeleteItem(int to_delete);

// member function 3
TodoItem* GetItem(int locate);

// Member Function 4:
unsigned int GetSize();

// member function 5:
unsigned int GetCapacity();

// member function 6:
void Sort();

// member function 7
string ToFile();

// Overloaded Friend
friend ostream& operator <<(ostream &out, TodoList &list);
};
#endif
