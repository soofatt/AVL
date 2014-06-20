#include "AVL.h"
#include "Rotation.h"
#include "Rotation_r.h"
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
  else if(elem->balance == 1 && newParent->balance == 0){
    elem->balance = 0;
    newParent->balance = -1;
  }
  else if(elem->balance == 2 && newParent->balance == 0){
    elem->balance = 1;
    newParent->balance = -1;
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
  else if(elem->balance == -1 && newParent->balance == 0){
    elem->balance = 0;
    newParent->balance = 1;
  }
  else if(elem->balance == -2 && newParent->balance == 0){
    elem->balance = -1;
    newParent->balance = 1;
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

int getHeight(Node *elem){
  int left = 0, right = 0, currentHeight = 0;
  
  if(elem->leftChild == NULL && elem->rightChild == NULL)
    return 1;
  if(elem->leftChild != NULL)
    left = _getHeight(elem->leftChild);
  if(elem->rightChild != NULL)
    right = _getHeight(elem->rightChild);
  
  if(left >= right)
    currentHeight = left+1;
  else
    currentHeight = right+1;
  
  return currentHeight;
}