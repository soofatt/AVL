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