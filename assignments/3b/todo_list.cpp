/*
 * Name        : lab_3b/todo_list.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment 3b
 */
#include "todo_list.h"
#ifndef Lee_Todo_list_CPP_
#define Lee_Todo_list_CPP_


void TodoList::IncreaseSize(){
  unsigned int i, size, new_size;
  size =GetCapacity();
  new_size = size + 10;
  TodoItem** tempArr = new TodoItem*[size];
  
  // Duplicting Array...
  for (i=0; i<size; i++) {
    tempArr[i] = items_array[i];
  } 
  // deleting array...
  delete items_array;

  //creating and filling new bigger array...
  items_array = new TodoItem*[nsize];
  for (i=0; i<size; i++) {
    items_array[i] = tempA[i];
  } 

  delete[] tempA;
  tempA = NULL;
}

// Private Member Funtion 2: Compacting Size
void TodoList::CompactSize() {
  unsigned int i, nsize, size, null_items=0;
  size = GetCapacity();
  
  
  for (i=0; i<size; i++) {
    if (items_array[i] == NULL) {
      null_items++;
    }
  }
  
  nsize = size-null_items;
  TodoItem** tempA = new TodoItem*[size];
  for (i=0; i<size; i++) {
   if (items_array[i] != NULL) {
     tempA[i] = items_array[i];
    }
  }
  delete items_array;
    
   // Creating and filling new smaller array...
  items_array = new TodoItem*[nsize];

  for (i=0; i<nsize; i++) {
    items_array[i] = tempA[i];
  } 

  delete[] tempA;
  tempA = NULL;
} 

 //Constructor
TodoList::TodoList(){
  items_array = new TodoItem*[25];
  }


// ~Destructor
TodoList::~TodoList(){
delete[] items_array;
items_array = NULL;
} 


// Member Function 1: Adding Item
void TodoList::AddItem(TodoItem* item) {

  unsigned int  cSize = GetSize();
 if(cSize < 24){
   items_array[cSize] = item;
 } 
 if(current_size >= 24){
  IncreaseSize();
  cSize = GetSize();
  items_array[cSize] = item;
 }
}
  
  
// Member Function 2: Deleting Item
void TodoList::DeleteItem(int to_delete) {
 items_array[(to_delete-1)] = NULL;
 CompactSize();
} 

// Member Function 3: Retiveing Item
TodoItem* TodoList::GetItem(int locate) {
  TodoItem* to_return;
  
  if(items_array[(locate-1)] == NULL){
   to_return = 0;
  } else {
  to_return = items_array[(locate-1)];
  }
  return to_return;
 }
 
 
// Member Function 4: Retriving current size;
unsigned int TodoList::GetSize() {
  unsigned int i, cSize = GetCapacity();
  current_size = 0;
 for (i=0; i<cSize; i++){
    if(items_array[i] !=NULL) {
      current_size++;
    }
  }
  return current_size;
}

// Member Function 5: Retrieve Capacity
unsigned int TodoList::GetCapacity() {
 max_capacity = 25;
 return max_capacity;
}
 
// Member Function 6: Named Sort. Sorts the array by the priorities of the items. (1 is highest
void TodoList::Sort(){
  unsigned int i, j, size;
  int small;
  
size = GetCapacity();

for (i = 0; i < size; i++) {
small = items_array[0]->priority();

for (j = (i+1); j < size; j++) {
if(items_array[j]->priority() < small) {
small = items_array[j]->priority();
}
if (small != items_array[i]->priority()) {
SwapValues(items_array[i]->priority(), items_array[j]->priority());
}
}
}
}


//Member Function 7:  ToFile.
string TodoList::ToFile(){
  stringstream ss ;
  unsigned int i, size;
  size = GetCapacity();
  
  for (i =0; i<size; i++){
    ss<<items_array[i]->ToFile()<<endl;
  }
 return ss.str(); 
}
  
// Overloaded Friend 
ostream& operator <<(ostream &out, TodoList &list) {
  unsigned int i, size;
  size = GetSize();
  
  for (i=0; i<size; i++) {
      out<< i << ":" << list.GetItem((i+1))->description();
}
return out;
  }
  
  void TodoList::SwapValues(int value_1, int value_2) {
   int temp;
    temp = value_1;
    value_1 = value_2;
    value_2 = temp;
}
#endif