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
  Node *tempPivot, *tempPivotRight, *temp, *newParent;
  
  tempPivot = elem->leftChild;
  tempPivotRight = tempPivot->rightChild;
  
  tempPivotRight->leftChild = tempPivot;
  elem->leftChild = tempPivotRight;
  
  if(tempPivotRight->rightChild != NULL){
    temp = tempPivotRight->rightChild;
    newParent = tempPivotRight;
    newParent->rightChild = elem;
    elem->leftChild = temp;
  }
  else if(tempPivotRight->leftChild != NULL){
    temp = tempPivotRight->leftChild;
    newParent = tempPivotRight;
    newParent->rightChild = elem;
    tempPivot->rightChild = temp;
  }
  
  return newParent;
}