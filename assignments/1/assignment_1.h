/*
 * Name        : FILL IN
 * Author      : Gabrielle Lee
 * Description : Assignment 1
 * Sources     : FILL IN
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

// Add any includes and using statements Here
#include <iostream>
#include <string>
#include<cmath>
using std::endl;
using std::string;

// Declare Function Prototypes Here (What goes above main)
bool CheckAlphabetic(string const &stringCA);

bool EncryptString(string &stringE, unsigned int numShift);

bool DecryptString(string &stringDS, unsigned int numShift);

double ComputeAverage(double arr[], unsigned int size);

double FindMinValue(double arr[], unsigned int sizeOfArr);

double FindMaxValue(double arr[], unsigned int sizeOfArr);


#endif
