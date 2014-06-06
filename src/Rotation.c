#include "AVL.h"
#include "Rotation.h"
#include <stdio.h>

Node *leftRotate(Node *elem){
  Node *newParent, *temp;
  
  newParent = elem->rightChild;
  temp = newParent->leftChild;
  
  newParent->leftChild = elem;
  elem->rightChild = temp;
  
  elem->rank = 0;
  newParent->rank = 0;
  
  return newParent;
}

Node *rightRotate(Node *elem){  
  Node *newParent, *temp;
  
  newParent = elem->leftChild;
  temp = newParent->rightChild;
  
  newParent->rightChild = elem;
  elem->rightChild = temp;
  
  elem->rank = 0;
  newParent->rank = 0;
  
  return newParent;
}
