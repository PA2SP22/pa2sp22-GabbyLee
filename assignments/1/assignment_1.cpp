/*
 * Name        : FILL IN
 * Author      : Gabrielle Lee
 * Description : Assignment 1
 * Sources     : FILL IN
 */

#include "assignment_1.h"
#include<cmath>
#include <string>
#include <climits>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  return 0;
}
// Write Function Definitions Here (What goes below main)
bool CheckAlphabetic(string const &stringy) {
]int i;
bool isDone;
int size = stringy.length();
  int count = 0;
  //check for spaces
  if(stringy == "" || stringy == " " || stringy.empty() == 1 ){
    return false;
  }
  else{
  //Loop to check if each character in string is alphabetic 
    for (i = 0; i < size; i++) {
    if (isalpha(stringy.at(i)) )
        count++;
    }
 //returns bool    
    if (count == size){
        isDone = true;
    } else { isDone = false; }
    return isDone;
  }
}


bool EncryptString(string &str, int numShift){
    int i;
    int stringSize = str.length();
    bool isAllAlpha;

    // use checkAlphabetic function to make sure string is alphabetic
    isAllAlpha = CheckAlphabetic(str);
    
    if (isAllAlpha){
      
    
    // loop to shift letters inthe given string upper and lowercase
 for(i=0; i<stringSize; i++){
     if (islower(str.at(i))){
       str.at(i) =( ( (str.at(i)-97+26) + numShift) % 26) + 97;
       if(str.at(i) > 'z'){
         str.at(i)-'a';
       
       }
       
   /*  if (str.at(i) > 'z'){
       str.at(i) = 'a';
    }*/
     }
    
  if (isupper(str.at(i))){
  str.at(i) =( ( (str.at(i)-65+26) + numShift) % 26) + 65;
   if(str.at(i) > 'Z'|| str.at(i)<'A'){
         str.at(i)-'A';
       
       }
    /*if (str.at(i) > 'Z'){
         ;
    }
    */
  }
    
 }
return true;
 }
 else {
     return false;
 }
    
}
bool DecryptString (string &st, int numShift){
      int i;
    int stringSize = st.length();
    bool isAllAlpha;
    
    isAllAlpha = CheckAlphabetic(st);
    
    if (isAllAlpha == true){
    
 for(i =0; i < stringSize; i++){
   
   if (islower(st.at(i))){
       st.at(i) =( ( (st.at(i)-97) - numShift+26) % 26) + 97;
   }
    if (isupper(st.at(i))){
  st.at(i) =( ( (st.at(i)-65) - numShift+26) % 26) + 65;
    
 }
 }
return true;
 }
 else {
     return false;
 }
    
}
double ComputeAverage(double arr[], unsigned int size){
    int i;
    double arrayAvg;
    double sum = 0;
    
    for (i=0; i < size; i++) {
        sum += arr[i];
    }
    arrayAvg = sum/size;
    return arrayAvg;
}

double FindMinValue(double arr[], unsigned int sizeOfArr){
    int i;
    double min = arr[0];
    
    for (i=0; i<sizeOfArr; i++){
      if (min > arr[i] ){
        min = arr[i];
      }
      return min;
}
}
double FindMaxValue(double arr[],unsigned int sizeOfArr){
    int i;
    double max;
    max = arr[0];
    
    for (i=0; i<sizeOfArr; i++){
        if(arr[i]>max){
          max = arr[i];
        }
    }
    return max;
}
