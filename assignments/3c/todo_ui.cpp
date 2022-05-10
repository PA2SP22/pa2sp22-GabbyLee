/*
 * Name        : Assignment 3c/todo_ui.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment 3c
 */
#include "todo_ui.h"
// constructor allocates memory for the todo list
TodoUI() {
 list = new TodoList;
}

//destructor thay frees memory associated with the dynamic TodoList

~TodoUI() {
 delete list;
 list = NULL;
}

void Menu(int user_num) {
cout<<"1 Create New "<<endl;
cout<<"2 Edit"<<endl;
cout<<"3 View List"<<endl;
cout<<"4 View Item"<<endl;
cout<<"5 Delete Item"<<endl;
cout<<"6 Delete List"<<endl;
cout<<"7 Exit"<<endl;
TodoUI();

   if (user_num == 7) {
    Exit();
   } else {
      
    while(user_num != 7) {
   user_num = read.readInt(1, 7);
   Menu(user_num);
   }  
      
   }

switch(user_num) {
  case 1:
  cout<< "Enter new item."
  char user_string[100];
  user_string = read.readChar();
  createNew(user_string);
  break;
  
  case 2:
    break;
    
  case 3:
ViewALL();
  break;
  
  case 4:
  int to_get;
  int size = list.GetSize();
  to_get = read.readInt(0, size);
  ViewItem(to_get);
  break; 
  
  case 5:
  int to_del;
  int size = list.getSiize();
  to_del = read.readInt(0, size);
  DeleteItem(to_del);
  break; 
  
  case 6:
  DeleteAll();
  cout<<"list deleted"<<endl;
  break;
  
  case 7:
  Exit();
  break;
  
  default:
    // code block
}

}

void todoUI::Create(string item) {
  list->AddItem(item);  
}

void todoUI::Edit() {
    list->set_description(string description);
    list->set_priority(int priority);
    list->set_completed(bool isdone);
}

string todoUI::ViewALL() {
    list->sort();
    list->tofile();
}

void todoUI::ViewItem(int to_get) {
    list->GetItem(to_get);
}

void todoUI::Delete(int to_del) {
    list->DeleteItem(to_del);
}

void todoUI::DeleteAll() {
    list->clear();
}
void todoUI::Exit() {
cout<<"Program Closing..."<<endl;
list->~TodoUI();
 exit(1);
}