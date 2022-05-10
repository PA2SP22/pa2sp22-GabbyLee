/*
 * Name        : Assignment 3c/todo_ui.h
 * Author      : Gabrielle Lee
 * Description : Assignment 3c
 */
#include "todo_list.h"
#include "todo_item.h"
#include "CinReader.h"
#include <string>
#include <sstream>
#include <cstdlib>
using std::stringstream;
using std::string;
using std::ostream;
using std::cout;
using std::endl;


#ifndef Lee_Todo_UI_H_
#define Lee_Todo_UI_H_

class TodoUI {

private:
CinReader* read;
TodoList* list;

public:
// Constructor 
TodoUI();

// Destructor 
~TodoUI();

//Member functions:
void Menu(int user_num);

void Create(string item);

void Edit();

string ViewALL();

string ViewItem(int to_get);

void Delete(int to_del);

void DeleteAll();

void Exit();



};
# endif 
