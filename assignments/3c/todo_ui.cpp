/*
 * Name        : Assignment 3c/todo_ui.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment 3c
 */
#include "todo_ui.h"
// constructor allocates memory for the todo list
TodoUI::TodoUI() {
list = new TodoList;
}

// destructor thay frees memory associated with the dynamic TodoList
TodoUI::~TodoUI() {
delete list;
list = NULL;
}

// Menu function
void TodoUI::Menu() {
int size = list->GetSize();
int to_del;
int user_num1;
cout << "MENU" << endl;
cout << "Choose and option..." << endl;
cout << "1 Create New " << endl;
cout << "2 Edit" << endl;
cout << "3 View List" << endl;
cout << "4 View Item" << endl;
cout << "5 Delete Item" << endl;
cout << "6 Delete List" << endl;
cout << "7 Exit" << endl;
user_num1 = read.readInt(1, 7);

switch(user_num1) {
case 1:
Create();
break;

case 2:
if (size < 1) {
cout << "The list is empty" << endl;
Menu();
} else {
Edit();
}
break;

case 3:
if (size < 1) {
cout << "The list is empty" << endl;
Menu();
} else {
ViewALL();
}
break;

case 4:
if (size < 1) {
cout << "The list is empty" << endl;
Menu();
} else {
ViewItem();
}
break;

case 5:
if (size < 1) {
cout << "The list is empty" <<endl;
} else {
cout << "Enter the number of the Item you want to delete" << endl;
cout << "Enter -1 to return to Menu" << endl;
to_del = read.readInt(-1, size);
if (to_del == -1) {
Menu();
} else {
Delete(to_del);
}
}
cout << "Item deleted" << endl;
Menu();
break;

case 6:
if (size < 1) {
cout << "The list is already empty" << endl;
} else {
DeleteAll();
cout << "List deleted" << endl;
}
Menu();
break;

case 7:
Exit();
break;

default:
Menu();
break;
}
}

void TodoUI::Create() {
cout << "Enter new thing to do" << endl;
string user_string = read.readString();
cout << "Enter priority" << endl;
int user_p = read.readInt(1, 5);
cout << "Enter true or false for completed" << endl;
bool user_c = read.readBool();
list->AddItem(new TodoItem(user_string , user_p, user_c ));
Menu();
}

void TodoUI::Edit() {
int user_n;
int size = list->GetSize();
cout << "Enter the number of the Item you want to edit" << endl;
cout << "Enter -1 to return to menu" << endl;

user_n = read.readInt(-1, size);
if(user_n == -1) {
Menu();
} else {
cout << "Enter 1 to Edit description" << endl;
cout << "Enter 2 to Edit priority" << endl;
cout << "Enter 3 to Edit completed" << endl;
cout << "Enter 0 to return to Menu" <<endl;
int user_n2 = read.readInt(0, 3);

if(user_n == 0) {
Menu();
} else if (user_n2 == 1) {
cout << "Enter Description" << endl;
string user_d = read.readString(true, 50);
list->GetItem(user_n)->set_description(user_d);
Edit();
} else if (user_n2 == 2) {
cout << "Enter priority" << endl;
int user_n3 = read.readInt(1, 5);
list->GetItem(user_n)->set_priority(user_n3);
Edit();
} else {
cout << "Enter true or false for completed" << endl;
bool user_c = read.readBool();
list->GetItem(user_n)->set_completed(user_c);
Edit();
}
}
}

void TodoUI::ViewALL() {
list->Sort();
cout << list->ToFile();
Menu();
}

string TodoUI::ViewItem() {
string to_return;
int to_get;
int size = list->GetSize();
cout << "Enter the number of the item you want to view" << endl;
to_get = read.readInt(0, size);
to_return =  list->GetItem(to_get)->ToFile();
return to_return;
}

void TodoUI::Delete(int to_del) {
list->DeleteItem(to_del);
}

void TodoUI::DeleteAll() {
delete list;
}

void TodoUI::Exit() {
cout << "Program Ended" << endl;
exit(1);
}
