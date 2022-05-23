



BSTreeT<T>::BSTreeT(){
    root_ = NULL;
    size_ = 0; 
}
 
BSTreeT<T>::~BSTree(){
 Clear();   
}

unsigned int BSTreeT<T>::GetSize() const{
    return size_
}

void BSTreeT<T>::Clear(){
    Clear(root_);
}

bool BSTreeT<T>::Insert(int add){
    return Insert(add, root_);
}

bool BSTreeT<T>::Exsist(to_find){
bool to_return;
if (root == NULL){
to_return =  0;
    } else {
  to_retrun = FindMin(root_);
}

int BSTreeT<T>::Remove(to_del){
int to_return;
to_return = Remove(to_del, root_);
}

BSTreeT<T>* BSTreeT<T>::Get(to_find) {
 BSTreeT<T>* to_return;  
    
}

string BSTreeT<T>::ToStringForwards() {
  return  ToStringForwards(root_);

}

string BSTreeT<T>::ToStringBackwards(){
  return  ToStringBackwards(root_);
}


 
void BSTreeT<T>::Clear(BSTNodeT*& subroot) {
    
if (subroot != NULL) {
if (subroot->GetLeftChild() != NULL) {
Clear(subroot->GetLeftChild());
}
if(subroot->GetRightChild() != NULL) {
Clear(subroot->GetRightChild());
}
delete subroot;
subroot = NULL;
}
size_ = 0;
}


bool BSTreeT<T>::Insert(int add, BSTNode*&<T> subroot){
bool isDone;

 BSTNode* new_kid = new BSTNode(contents);
 if (subroot == NULL) {
subroot = new_kid;
size_++;
isDone = true;

} else if (contents < subroot->GetContents()) {
return Insert(contents, subroot->GetLeftChild());

} else if (contents > subroot->GetContents()) {
return Insert(contents, subroot->GetRightChild());

} else if (subroot->GetContents() == contents) {
isDone = false;
}
return isDone;
}

bool BSTreeT<T>::Remove(int contents, BSTNode*&<T> subroot){
    
}

BSTreeT<T>*::BSTreeT<T>Get(int to_get, BSTNode* subroot) {

if (subroot == NULL){
return NULL;


// Go left
} else if (to_get < subroot->GetContents()) {
if(subroot->GetContents() == to_get) {
    return subroot;
}  else if(subroot-> GetLeftChild() != NULL) {
return Get(to_get, subroot->GetleftChild());
} else {
    return NULL;
}


   
// Go right 
} else if (to_get > subroot->GetContents()) {
if(subroot->GetContents() == to_get) {
    to_return = subroot;
} else if(subroot-> GetRightChild() != NULL) {
return Get(to_get, subroot->GetRightChild());
} else {
    return NULL;
}

}

}

bool BSTreeT<T>::Exsist(int to_find, BSTNode*<T> subroot) {
if (subroot == NULL){
return NULL;
}

// Go left
if (to_find < subroot->GetContents()) {

if(subroot->GetContents() == to_get) {

    return true;

} else if(subroot-> GetLeftChild() != NULL) {
 
return Get(to_get, subroot->GetleftChild());

} else {

    return NULL;

}
   
// Go right 
} else if (to_get > subroot->GetContents()) {
if (subroot->GetContents() == to_get) {
   return true;
} else if (subroot->GetRightChild() != NULL) {

return Get(to_get, subroot->GetRightChild());

} else {
return NULL;
}

}
    
}

void BSTreeT<T>::Clear(BSTNode*&<T> subroot){
  if (subroot != NULL) {
if (subroot->GetLeftChild() != NULL) {
Clear(subroot->GetLeftChild());
}
if(subroot->GetRightChild() != NULL) {
Clear(subroot->GetRightChild());
}
delete subroot;
subroot = NULL;
}
size_ = 0;  
}

string BSTreeT<T>::ToStringForwards(BSTNode*&<T> subroot){
if (size_ = 0){
    print<<"";
} else {

print << (ToStringForwards(subroot)); 
}
}

string BSTreeT<T>::ToStringForwards(BSTNode*&<T> subroot){
    
}