/*
 * Name        : template.cpp
 * Author      : Gabrielle Lee
 * Description : Various functions using templates. Please note you can just
 *               write the definitions in here. No need for prototypes.
 */
#include <iostream>
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

/*
 * Function Name: PrepareForDisplay
 * Create a string containing the contents of an array, each element separated
 * by a specified character. For example, if the array contents
 * are {1, 2, 3} and the separator character is ':', the string returned
 * will be "1:2:3". Please note the array can be of any type.
 * If the template function outputs doubles, they should be to a precision of 2.
 * @uses stringstream
 * @param T values[] - An array of any type
 * @param unsigned int size - The size of the array
 * @param char separator - The separator character to use in the returned
 *                         string. Defaults to ','
 * @return string - A string containing the contents of values separated by the
 *                  specified separator character
 */
template <typename T>
string PrepareForDisplay(T values[], unsigned int size, char sep =',') {
stringstream ss;
unsigned int i;
ss.setf(std::ios::fixed|std::ios::showpoint);
ss.precision(2);

if (size == 0) {
ss << "";
} else {
for(i = 0; i < size; i++) {
  if (i == size - 1) {
  ss << values[i];
} else {
  ss <<  values[i] << sep;
}
}
}
return ss.str();
}


/*
 * Function Name: HasValue
 * Test to see if an array contains a specified value.
 * @param T values[] -  An array of any type
 * @param unsigned int size - The size of the array
 * @param T value_to_find - The value to search for within the array
 * @return bool - true if value is found in the array, otherwise false
 */
template <typename T>
bool HasValue(T values[], unsigned int size, T value_to_find ) {
  unsigned int i, count;
  bool isFound;
  count = 0;

if (size == 0 || value_to_find == T()) {
isFound = false;
} else {
for (i = 0; i < size; i++) {
if(values[i] == value_to_find) {
count++;
}
}
if (count >= 1) {
  isFound = true;
} else {
isFound = false;
}
}
return isFound;
}
/*
 * Function Name: ValueAt
 * Return the value from an array at a specified index.
 * @param T values[] -  An array of any type
 * @param unsigned int size - The size of the array
 * @param unsigned int index - The position in the array from which to return a
 *                             value
 * @param bool &error - A flag that will be set to true if index is invalid for
 *                     the array, else it will be set to false
 * @return T - The value at the specified index in the array when error is set
 *               to false. if index is invalid, returns a zero representation of
 *               the type and sets error to true. To get a zero representation
 *               you can return T()
 */

template <typename T>
T ValueAt(T values[], unsigned int size, unsigned int index, bool &error) {
T to_return;

if (size <= index) {
  error = true;
to_return = T();
} else {
  to_return = values[index];
  error = false;
  }
return to_return;
}

/*
 * Function Name: Sum
 * Return the "sum" of the values in the array. Your initial sum should be set
 * to "zero" in your algorithm. To do this use T().
 * @param T values[] - An array of any type
 * @param unsigned int size - The size of the array
 * @return T - The sum of the values in the array
 */

template <typename T>
T Sum(T values[], unsigned int size) {
unsigned int i;
T sum = T();

if (size == 0) {
sum = T();
} else {
sum = values[0];
for (i = 1; i< size; i++) {
sum += values[i];
}
}
return sum;
}

/*
 * Function Name: SwapValues
 * Swap the positions of two values in an array. The two index values must be
 * valid for the array.
 * @param T values[] - An array of any type
 * @param unsigned int size - The size of the array
 * @param unsigned int index1 - The position of the first value to be swapped
 * @param unsigned int index2 - The position of the second value to be swapped
 * @return bool - true if the swap was successful, otherwise false
 */
template <typename T>
bool SwapValues(T values[], unsigned int size, unsigned int index1,
                unsigned int index2) {
bool has_v1, has_v2, isDone;
T temp;

if (size < index1 || size-1 < index2 || index1 < 0 || index2 < 0) {
isDone = false;
} else {
  has_v1 = HasValue(values, size, values[index1]);
  has_v2 = HasValue(values, size, values[index2]);

  if (has_v1 == true && has_v2 == true) {
  temp = values[index1];
  values[index1] = values[index2];
  values[index2] = temp;
  isDone = true;
  } else {
  isDone = false;
  }
  }
return isDone;
}

