/*
 * Name        : FILL IN
 * Author      : Gabrielle Lee
 * Description : Assignment 1FILL IN
 * Sources     : FILL IN
 */

#include "assignment_1.h"
#include<cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Write Function Definitions Here (What goes below main)

bool checkAlphabetic( string const &stringy){
  int i;
  bool isDone;
  int  size = stringy.length();
  int count = 0;
  //Loop to check if each character in string is alphabetic 
    for (i = 0; i < size; i++) {
    if (isalpha(stringy.at(i)) )
        count++;
    }
 //returns bool    
    if (count == size){
        isDone = true;
    } else { isDone = false; }
    return isDone
}

bool EncryptString(string &stryng, int numShift){
    int i;
    int stringSize = str.length();
    bool isAllAlpha;
    
    isAllAlpha = checkAlphabetic(str);
    
    if (isAllAlpha == true){
    
 for(i=0; i<stringSize; i++){
     str.at(i) += numShift;
 }
return true;
 }
 else {
     return false;
 }
    
}

bool DecryptString (){
      int i;
    int stringSize = str.length();
    bool isAllAlpha;
    
    isAllAlpha = checkAlphabetic(str);
    
    if (isAllAlpha == true){
    
 for(i=0; i<stringSize; i++){
     str.at(i) -= numShift;
 }
return true;
 }
 else {
     return false;
 }
    
}

    
}

double computeAverage(double arr[], unsigned int size){
    int i:
    double arrayAvg;
    double sum = 0.0;
    
    for (i = 0; i < size; i++) {
        sum += arr[i];
    }
    arrayAvg = sum/arrayAvg;
    return arrayAvg;
}

double FindMinValue(double arr[], unsigned int sizeOfArr){
    int i;
    int min = arr[0];
    for (i=0; i<sizeOfArr; i++){
   min = fmin(arr[i], arr[i +1]);    }
}

double FindMaxValue(double arr[],unsigned int sizeOfArr){
    int i;
    int max;
    
    for (i=0; i<sizeOfArr; i++){
        max = fmax(arr[i], arr[i+1]);
    }
}
