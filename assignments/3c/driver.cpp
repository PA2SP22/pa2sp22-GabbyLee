
#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
#include "todo_list.h"
#include "todo_item.h"
#include "todo_ui.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
int main (){
   int user_num;
   
   cout << "Welcome to the To Do list" <<endl;
   cout << "MENU" << endl;
   cout << "Choose and option..."<<endl;
   Menu();
   user_num = read.readInt(1, 7);
   Menu)(user_num);
   return 0;
}