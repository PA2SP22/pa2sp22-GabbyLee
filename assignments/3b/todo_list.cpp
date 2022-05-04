/*
 * Name        : lab_3b/todo_list.cpp
 * Author      : Gabrielle Lee
 * Description : Assignment 3b
 */
#include "todo_list.h"
#ifndef Lee_Todo_list_CPP_
#define Lee_Todo_list_CPP_


void TodoList::IncreaseSize(){
  unsigned int i, size;
  size = GetCapacity();
  max_capacity = max_capacity + 10;
  TodoItem** tempArr = new TodoItem*[size];
  
  // Duplicting Array...
  for (i = 0; i < size; i++) {
    tempArr[i] = items_array[i];
  } 
  // deleting array...
  delete[] items_array;
  items_array = NULL;

  //creating and filling new bigger array...
  items_array = new TodoItem*[max_capacity];
  for (i=0; i<size; i++) {
    items_array[i] = tempArr[i];
  } 

  delete[] tempArr;
  tempArr = NULL;
}

// Private Member Funtion 2: Compacting Size
void TodoList::CompactSize(int to_delete) {
  unsigned int del = (to_delete-1), size, i;
  size = GetSize();
  
   for (i = del; i < size-1; i++) {
     items_array[i] = items_array[i +1];
  }
  
  /*TodoItem** tempA = new TodoItem*[size];
  
  for (i = 0; i < size; i++) {
   if ( items_array[i] != NULL){
  }
  
  delete[] items_array;
  items_array = NULL;
    
   // Creating and filling new smaller array...
  items_array = new TodoItem*[max_capacity];
  for (i = 0; i < size-1; i++) {
    if(tempA[i] != NULL) {
     items_array[i] = tempA[i];
    }
  } 
  
  delete[] tempA;
  tempA = NULL;
*/
}

 //Constructor
TodoList::TodoList(){
  items_array = new TodoItem*[25];
  max_capacity = 25;
  current_size = 0;
  }


// ~Destructor
TodoList::~TodoList(){
delete[] items_array;
items_array = NULL;
} 


// Member Function 1: Adding Item
void TodoList::AddItem(TodoItem* item) {

  unsigned int  cSize = GetSize();
 if(cSize <= max_capacity) {
   items_array[cSize] = item;
   // Luke: Increment Size here
   current_size++;
 } 
 else {
  IncreaseSize();
  cSize = GetSize();
  items_array[cSize + 1] = item;
 }
 
}
  
  
// Member Function 2: Deleting Item
void TodoList::DeleteItem(int to_delete) {
  int size = GetSize(); 
if (to_delete <= 0 || to_delete > size){

} else {
  // Luke: Before you compact, you need to delete the actual TodoItem
  delete items_array[to_delete - 1];
 CompactSize(to_delete);
  // Luke: After compaction, since we removed an Item we need to decrease size
  current_size--;
} 

}

// Member Function 3: Retiveing Item
TodoItem* TodoList::GetItem(int locate) {
  int size = GetSize();
  TodoItem* to_return;
  
  if (locate < 0 || locate > size){
    to_return = 0; 
  }
  
  else if(items_array[(locate-1)] == NULL){
   to_return = 0;
  } else {
  to_return = items_array[(locate-1)];
  }
  return to_return;
 }
 
 
// Member Function 4: Retriving current size;
unsigned int TodoList::GetSize() {
  // Luke: Your current_size variable should be tracking the size
  // Luke: So we just return the size
  /*
  unsigned int i, cSize = GetCapacity();
  current_size = 0;
 for (i=0; i<cSize; i++){
    if(items_array[i] !=NULL) {
      current_size++;
    }
  }
  */
  return current_size;
}

// Member Function 5: Retrieve Capacity
unsigned int TodoList::GetCapacity() {
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
  stringstream ss;
  string stringF;
  unsigned int i, size;
  size = GetSize();
  
  for (i = 0; i< size; i++){
    ss << items_array[i]->ToFile() << endl;
  }
  stringF = ss.str();
 return stringF; 
}
  
// Overloaded Friend 
ostream& operator <<(ostream &out, TodoList &list) {
  unsigned int i, size;
  
  size = list.GetSize();
  for (i = 0; i < size; i++) {
      out << list.GetItem((i+1))->description();
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