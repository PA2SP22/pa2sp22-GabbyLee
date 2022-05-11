
#include <iostream>
#include <sstream>
#include <streambuf>
#include <string>
#include "todo_list.h"
#include "todo_item.h"
#include "todo_ui.h"
#include "CinReader.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
int main() {
cout << "Welcome To The To Do list program" << endl;

TodoUI *new_ui;
new_ui = new TodoUI();
new_ui->Menu();

return 0;
}
