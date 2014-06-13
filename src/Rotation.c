#include "AVL.h"
#include "Rotation.h"
#include <stdio.h>

Node *leftRotate(Node *elem){
  Node *newParent, *temp;
  
  newParent = elem->rightChild;
  temp = newParent->leftChild;
  
  newParent->leftChild = elem;
  elem->rightChild = temp;
  
  if(elem->balance == 2 && newParent->balance == 1){
    elem->balance = 0;
    newParent->balance = 0;
  }
  else if(elem->balance == 1 && newParent->balance == 1){
    elem->balance = -1;
    newParent->balance = -1;
  }
  else if(elem->balance == 1 && newParent->balance == -1){
    elem->balance = 0;
    newParent->balance = -2;
  }
  else if(elem->balance == 2 && newParent->balance == 2){
    elem->balance = -1;
    newParent->balance = 0;
  }
  else{
  } 
  
  return newParent;
}

Node *rightRotate(Node *elem){  
  Node *newParent, *temp;
  
  newParent = elem->leftChild;
  temp = newParent->rightChild;
  
  newParent->rightChild = elem;
  elem->leftChild = temp;
  
  if(elem->balance == -2 && newParent->balance == -1){
    elem->balance = 0;
    newParent->balance = 0;
  }
  else if(elem->balance == -1 && newParent->balance == -1){
    elem->balance = 1;
    newParent->balance = 1;
  }
  else if(elem->balance == -1 && newParent->balance == 1){
    elem->balance = 0;
    newParent->balance = 2;
  }
  else if(elem->balance == -2 && newParent->balance == -2){
    elem->balance = 1;
    newParent->balance = 0;
  }
  else{
  } 
  
  return newParent;
}

Node *doubleRightRotate(Node *elem){
  Node *newParent, *temp;
  
  temp = leftRotate(elem->leftChild);
  
  elem->leftChild = temp;
  
  newParent = rightRotate(elem);
  
  return newParent;
}

Node *doubleLeftRotate(Node *elem){
  Node *newParent, *temp;
  
  temp = rightRotate(elem->rightChild);
  
  elem->rightChild = temp;
  
  newParent = leftRotate(elem);
  
  return newParent;
}