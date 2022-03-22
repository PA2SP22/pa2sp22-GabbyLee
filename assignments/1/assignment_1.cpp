/*
 * Name        : FILL IN
 * Author      : Gabrielle Lee
 * Description : Assignment 1
 * Sources     : https://stackoverflow.com/questions/70113741/caesar-cipher
          -outputting-characters-with-accents-after-character-goes-6-past-z
 */

#include "assignment_1.h"
#include <iostream>
#include <string>
#include<cmath>
#include <climits>
using std::cout;
using std::cin;
using std::endl;
using std::string;



// Write Function Definitions Here (What goes below main)
bool CheckAlphabetic(string const &stringCA) {
  int i;
  bool isDone;
  int signed size = stringCA.length();
  int count = 0;
// check for spaces
  if (stringCA =="" || stringCA == " " || stringCA.empty() == 1) {
    return false;
  } else {
// Loop to check if each character in string is alphabetic
    for ( i = 0; i < size; i++ ) {
    if (isalpha(stringCA.at(i)))
        count++;
  }
// returns bool
  if (count == size) {
        isDone = true;
    } else { isDone = false; }
    return isDone;
  }
}


bool EncryptString(string &stringE, int numShift) {
    int i;
    int signed stringSize = stringE.length();
    bool isAllAlpha;

  if (numShift < 0) {
      numShift=(26 + (numShift % 26)) % 26;
    }

    // use checkAlphabetic function to make sure string is alphabetic
    isAllAlpha = CheckAlphabetic(stringE);


    if (isAllAlpha) {
    // loop to shift letters in the given string upper and lowercase
for (i = 0; i < stringSize; i++) {
if (islower(stringE.at(i))) {
stringE.at(i) = ( ( (stringE.at(i)-97+26) + numShift) % 26)+97;
}


  if (isupper(stringE.at(i))) {
  stringE.at(i) = ( ( (stringE.at(i)-65+26) + numShift) % 26) + 65;
  if (stringE.at(i) > 'Z'|| stringE.at(i) < 'A') {
         stringE.at(i)='A';
       }
     }
}
// return statments
return true;
} else {
     return false;
}
}

bool DecryptString(string &stringDS, int numShift) {
      int i;
    int signed stringSize = stringDS.length();
    bool isAllAlpha;

    if (numShift < 0) {
      numShift=(26 + (numShift % 26)) % 26;
    }

    // check if string is alphabetic
    isAllAlpha = CheckAlphabetic(stringDS);
    if (isAllAlpha == true) {
        for (i = 0; i < stringSize; i++) {
    // lowercase decryption
     if (islower(stringDS.at(i))) {
       stringDS.at(i) = ( ( (stringDS.at(i) - 97) - numShift+26) % 26) + 97;
}
// uppercase decryption
if (isupper(stringDS.at(i))) {
  stringDS.at(i) =( ( (stringDS.at(i)-65) - numShift+26) % 26) + 65;
}
}
return true;
} else {
return false;
}
}

double ComputeAverage(double arr[], unsigned int size) {
    int i;
    double arrayAvg;
    double sum = 0;
    int signed sizeA = size;

    for (i = 0; i < sizeA; i++) {
        sum += arr[i];
}
    arrayAvg = sum/size;
    return arrayAvg;
}

double FindMinValue(double arr[], unsigned int sizeOfArr) {
    int i;
    double min = arr[0];
    int signed sizeB = sizeOfArr;

    for (i = 0; i < sizeB; i++) {
      if (min > arr[i]) {
        min = arr[i];
      }
}

return min;
}

double FindMaxValue(double arr[], unsigned int sizeOfArr) {
    int i;
    double max;
    max = arr[0];
    int signed sizeC = sizeOfArr;

    for (i = 0; i < sizeC; i++) {
        if ( arr[i] > max ) {
          max = arr[i];
        }
    }
    return max;
}
