#include "AVL.h"
#include "Rotation.h"
#include "Rotation_r.h"
#include <stdio.h>

Node *avlAdd(Node *root, Node *nodeToAdd){
  int tempBalanceLeft, tempBalanceRight;
  
  if(root == NULL)
    root = nodeToAdd;
  else if(nodeToAdd->data < root->data){
    if(root->leftChild != NULL){
	  tempBalanceLeft = (root->leftChild->balance);
      avlAdd(root->leftChild, nodeToAdd);
      if(tempBalanceLeft - (root->leftChild->balance) == 0){}
      else if((root->leftChild->balance) - 0 != 0)
        root->balance--;
	  else{}
    }
    else{
      root->leftChild = nodeToAdd;
      root->balance--;
    }
  }
  else if(nodeToAdd->data > root->data){
    if(root->rightChild != NULL){
	  tempBalanceRight = (root->rightChild->balance);
      avlAdd(root->rightChild, nodeToAdd);
      if(tempBalanceRight - (root->rightChild->balance) == 0){}
	  else if((root->rightChild->balance) - 0 != 0)
        root->balance++;
      else{}
    }
    else{
      root->rightChild = nodeToAdd;
      root->balance++;
    }
  }

  if(root->balance == 2 && root->rightChild->balance == 1)
   root = leftRotate(root);
  else if(root->balance == 2 && root->rightChild->balance == -1)
   root = doubleLeftRotate(root);
  else if(root->balance == -2 && root->leftChild->balance == 1)
   root = doubleRightRotate(root);
  else if(root->balance == -2 && root->leftChild->balance == -1)
   root = rightRotate(root);
  else{}
  
  return root;
}

Node *avlRemove(Node *root, Node *nodeToRemove){
  
  if(nodeToRemove->data == root->data)
    return;
  
  if(nodeToRemove->data < root->data){
    avlRemove(root->leftChild, nodeToRemove);
    root->leftChild = (root->leftChild->leftChild);
    root->balance++;
  }
    
  if(nodeToRemove->data > root->data){
    avlRemove(root->rightChild, nodeToRemove);
    root->rightChild = (root->rightChild->rightChild);
    root->balance--;
  }  
  
  if(root->balance == 2 && root->rightChild->balance == 1)
   root = leftRotate(root);
  else if(root->balance == 2 && root->rightChild->balance == 0)
   root = leftRotate(root);
  else if(root->balance == 2 && root->rightChild->balance == -1)
   root = doubleLeftRotate(root);
  else if(root->balance == -2 && root->leftChild->balance == 1)
   root = doubleRightRotate(root);
  else if(root->balance == -2 && root->leftChild->balance == -1)
   root = rightRotate(root);
   else if(root->balance == -2 && root->leftChild->balance == 0)
   root = rightRotate(root);
  else{}
  
  return root;
}