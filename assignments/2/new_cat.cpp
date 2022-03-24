/*
 * Name        : Assignment 2
 * Author      : Gabrielle Lee
 * Description : Making a new utility cat
 *               
 */
#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;

int main(int argc, char *argv[]) {
string user_input;
string line;
ifstream fin;
int count = 0;
int i;


if (argc == 1) {
cout << "Welcome to the New Cat" << endl;
cout << "Waiting for input..."<< endl;
cout << "(press ctrl+d/ctrl+z to exit)" << endl;
while (!cin.eof()) {
getline(cin, user_input);
cout << user_input << endl;
}
} else if (argc > 1) {
for (i = 1; i < argc; i++) {
fin.open(argv[i]);

if (!fin.is_open()) {
cout << "Invalid filename" << endl;
count--;
exit(1);
}

count++;
fin.close();
}

if ( count == (argc-1) ) {
for (i = 1; i < argc; i++) {
fin.open(argv[i]);

if (fin.fail()||fin.bad()) {
cout << "file failed to open" << endl;
exit(1);
}

cout << argv[i] << ":" << endl;

while (!fin.eof()) {
getline(fin, line);
cout << line << endl;
}
  fin.close();
}

} else {
    cout << "Something went wrong, try again";
}
}
  return 0;
}
