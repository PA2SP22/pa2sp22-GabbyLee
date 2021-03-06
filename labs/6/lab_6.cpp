/*
 * Name        : lab_6.cpp
 * Author      : Gabrielle Lee
 * Description : Practicing Functions
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <streambuf>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*
 * function name: Hello
 * parameters: none
 * default arguments: n/a
 * return type: void
 *
 * Display "Hello world!" to stdout (no newline character after)
 */
// CODE HERE (FUNCTION PROTOTYPE)
void Hello();


// void Hello();

/*
 * function name: PrintMessage
 * parameters: string message (const call-by-reference)
 * default arguments: none
 * return type: void
 *
 * Display message to stdout (no newline character after)
 */
// CODE HERE (FUNCTION PROTOTYPE)
void PrintMessage(string message);
/*
 * function name: GetAnswer
 * parameters: none
 * default arguments: n/a
 * return type: int
 *
 * Return the value 42
 */
// CODE HERE (FUNCTION PROTOTYPE)
int GetAnswer();

/*
 * function name: FindLarger
 * parameters: int (const call-by-reference), int (const call-by-reference)
 * default arguments: none
 * return type: int
 *
 * Return the larger of the two parameter values. Should work correctly
 * if the values are equivalent.
 */
// CODE HERE (FUNCTION PROTOTYPE)
int FindLarger(int const &x, int const &y);

/*
 * function name: GetStats
 * parameters: string (const call-by-reference), int (call-by-reference),
 *             int (call-by-reference)
 * default arguments: none
 * return type: int
 *
 * Return the length of string. On return second parameter (int) should contain
 * a count of the number of uppercase characters of first parameter (string),
 * third parameter (int) should contain a count of the number of lowercase
 * characters in the first parameter (string)
 */
// CODE HERE (FUNCTION PROTOTYPE)
int GetStats(const string &st,  int &upper, int &lower);
/*
 * function name: BuildMessage
 * parameters: string (const call-by-reference), bool (const call-by-reference)
 * default arguments: string = "" (empty string), bool = false
 * return type: string
 *
 * Return the string "Message: STRING", where STRING is replaced by the value of
 * the first parameter (string). If second parameter (bool) is true, convert
 * first parameter (string) to all uppercase letters before concatenating it
 * with "Message: ". If first parameter is the empty string, return
 * "Message: empty".
 */
// CODE HERE (FUNCTION PROTOTYPE)
string BuildMessage(string const &str= " " ,  bool const &isTrue = false);


// For testing (DO NOT ALTER)
#include <cctype>
#include <vector>
void UnitTest();
void Test(bool test, int line_number, string more_info = "", string yours = "!",
          string actual = "!");
void OutputFailedTests();
unsigned int ut_passed = 0, ut_failed = 0, ut_total = 0, num_of_tests = 0;
std::vector<int> failed_tests;

// Program Execution Starts Here
int main() {
  // To test your code (DO NOT ALTER)
  UnitTest();
  // This ends program execution
  return 0;
}

// CODE HERE (FUNCTION DEFINITIONS)
// Print Hello Message
void Hello() {
  cout << "Hello world!";
}

// Print Message function
void PrintMessage(string message) {
cout << message;
}

// Get answer function
int GetAnswer() {
  return 42;
}

// Find the largest number function
int FindLarger(int const &x, int const &y) {
int largest = fmax(x, y);

  return largest;
}
// GetStats function
int GetStats(const string &st,  int &upper, int &lower ) {
int lcount = 0, ucount = 0, i;
int stringSize = st.length();

// count upper and lower case
for (i = 0; i < stringSize; i++) {
if (isupper(st.at(i))) {
       ucount++;
     }

     if (islower(st.at(i))) {
        lcount++;
}
     }
// Assigns upper and lowercase then returns string size.
upper = ucount;
lower = lcount;
  return stringSize;
}

// BuildMessage function
string BuildMessage(string const &str, bool const &isTrue) {
  string string1 = "Message: ";
  string str2;
  string finalString;
  int size;
  int i;
if ((str.empty() == 1 || str == " ") && (isTrue == false)) {
     str2 = "empty";

} else if (str.empty() == 0 && isTrue == false) {
    str2 = str;
  } else if (isTrue == true) {
    str2 = str;
    size = str2.length();

  for (i = 0; i < size;  i++) {
  str2.at(i) = toupper(str2.at(i));
}

} else { str2 = "empty";
}

finalString = string1 + str2;

return finalString;
}
// For testing (DO NOT ALTER)
void UnitTest() {
  cout << string(40, '-') << endl;
  cout << "UNIT TEST:\n" << string(40, '-') << endl;
  if (num_of_tests != 0)
    cout << "Total Number of Test: " << num_of_tests << endl;
  string yours = "", actual = "";

  // Tests
  std::streambuf* oldCout = cout.rdbuf();
  std::ostringstream captureCout;
  cout.rdbuf(captureCout.rdbuf());
  Hello();
  cout.rdbuf(oldCout);
  yours = captureCout.str();
  actual = "Hello world!";
  Test(yours == actual, __LINE__, "Hello()", yours, actual);
  captureCout.str("");
  cout.rdbuf(captureCout.rdbuf());
  PrintMessage("Hello again!");
  cout.rdbuf(oldCout);
  yours = captureCout.str();
  actual = "Hello again!";
  Test(yours == actual, __LINE__, "PrintMessage(\"Hello again!\")", yours,
       actual);
  Test(GetAnswer() == 42, __LINE__, "GetAnswer()");
  Test(FindLarger(-1, 1) == 1, __LINE__, "FindLarger(-1, 1)");
  Test(FindLarger(1, -1) == 1, __LINE__, "FindLarger(1, -1)");
  Test(FindLarger(1, 1) == 1, __LINE__, "FindLarger(1, 1)");
  int upper = 0, lower = 0;
  Test(GetStats("abc ABC", upper, lower) == 7 && upper == 3 && lower == 3,
       __LINE__, "GetStats(\"abc 123\", upper, lower)");
  Test(GetStats("abc", upper, lower) == 3 && upper == 0 && lower == 3, __LINE__,
       "GetStats(\"abc\", upper, lower)");
  Test(GetStats("ABC", upper, lower) == 3 && upper == 3 && lower == 0, __LINE__,
       "GetStats(\"ABC\", upper, lower)");
  Test(GetStats("", upper, lower) == 0 && upper == 0 && lower == 0, __LINE__,
       "GetStats(\"\", upper, lower)");
  yours = BuildMessage("hello");
  actual = "Message: hello";
  Test(yours == actual, __LINE__, "BuildMessage(\"hello\")", yours, actual);
  yours = BuildMessage("hello", true);
  actual = "Message: HELLO";
  Test(yours == actual, __LINE__, "BuildMessage(\"hello\", true)", yours,
       actual);
  yours = BuildMessage("HELLO", false);
  actual = "Message: HELLO";
  Test(yours == actual, __LINE__, "BuildMessage(\"HELLO\", false)", yours,
       actual);
  yours = BuildMessage("HELLO", true);
  actual = "Message: HELLO";
  Test(yours == actual, __LINE__, "BuildMessage(\"HELLO\", true)", yours,
       actual);
  yours = BuildMessage();
  actual = "Message: empty";
  Test(yours == actual, __LINE__, "BuildMessage()", yours, actual);

  cout << string(40, '-') << endl;
  cout << "Passed: " << ut_passed << " / " << ut_total << endl;
  OutputFailedTests();
  cout << string(40, '-') << endl;
  cout << "END OF UNIT TEST!\n";
  cout << string(40, '-') << endl;
  cout << "Be sure to run 'make style' to check for any style errors.\n"
       << "Please note that 'make style' does NOT check variable names or"
       << " indentation" << endl << endl;
}

// For testing (DO NOT ALTER)
void Test(bool test, int line_number, string more_info, string yours,
          string actual) {
  ut_total++;
  if (test) {
    cout << "PASSED TEST ";
    ut_passed++;
  } else {
    cout << "FAILED TEST ";
    ut_failed++;
    failed_tests.push_back(ut_total);
  }
  cout << ut_total << " " << more_info << "!" << endl;
  if (!test) {
    if (yours != "!")
      cout << "Yours:  \"" << yours << '"' << endl;
    if (actual != "!")
      cout << "Actual: \"" << actual << '"' << endl;
    cout << "  Check Line " << line_number << " for more info" << endl;
  }
}

void OutputFailedTests() {
  if (failed_tests.size()) {
    cout << "Failed test number(s): ";
    for (unsigned int i = 0; i < failed_tests.size() - 1; i++)
      cout << failed_tests.at(i) << ", ";
    cout << failed_tests.at(failed_tests.size() - 1) << endl;
  }
}
