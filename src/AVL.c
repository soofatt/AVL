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

Node *avlRemove(Node **ptrToRoot, Node *nodeToRemove){
  Node *tempNode = NULL;
  
  // if(nodeToRemove->data == (*ptrToRoot)->data)
    // return;
  
  if(nodeToRemove->data < (*ptrToRoot)->data){
    tempNode = (*ptrToRoot)->leftChild;
    // avlRemove((*ptrToRoot)->leftChild, nodeToRemove);
    (*ptrToRoot)->leftChild = ((*ptrToRoot)->leftChild->leftChild);
    (*ptrToRoot)->balance++;
  }
    
  if(nodeToRemove->data > (*ptrToRoot)->data){
    tempNode = (*ptrToRoot)->rightChild;
    // avlRemove((*ptrToRoot)->rightChild, nodeToRemove);
    (*ptrToRoot)->rightChild = ((*ptrToRoot)->rightChild->rightChild);
    (*ptrToRoot)->balance--;
  }   
  
  if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == 1)
   (*ptrToRoot) = leftRotate((*ptrToRoot));
  else if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == 0)
   (*ptrToRoot) = leftRotate((*ptrToRoot));
  else if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == -1)
   (*ptrToRoot) = doubleLeftRotate((*ptrToRoot));
  else if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->leftChild->balance == 1)
   (*ptrToRoot) = doubleRightRotate((*ptrToRoot));
  else if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->leftChild->balance == -1)
   (*ptrToRoot) = rightRotate((*ptrToRoot));
  else if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->leftChild->balance == 0)
   (*ptrToRoot) = rightRotate((*ptrToRoot));
  else{}
  
  return tempNode;
}

Node *avlGetReplacer(Node **ptrToRoot){
  Node *replacement;
  int tempBalance;
  
  if((*ptrToRoot)->rightChild == NULL){
    replacement = (*ptrToRoot);
    (*ptrToRoot) = (*ptrToRoot)->leftChild;
  }
  else{
    tempBalance = (*ptrToRoot)->rightChild->balance;
    replacement = avlGetReplacer(&(*ptrToRoot)->rightChild);
    if((*ptrToRoot)->rightChild == NULL)
      (*ptrToRoot)->balance--;
    else if((*ptrToRoot)->rightChild->balance == 0){
      if(tempBalance - (*ptrToRoot)->rightChild->balance != 0)
        (*ptrToRoot)->balance--;
      else {}
    }
    else{}
  }
  
  if((*ptrToRoot) != NULL){
    if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == 1)
     (*ptrToRoot) = leftRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == 0)
     (*ptrToRoot) = leftRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == 2 && (*ptrToRoot)->rightChild->balance == -1)
     (*ptrToRoot) = doubleLeftRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->leftChild->balance == 1)
     (*ptrToRoot) = doubleRightRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->leftChild->balance == -1)
     (*ptrToRoot) = rightRotate((*ptrToRoot));
    else if((*ptrToRoot)->balance == -2 && (*ptrToRoot)->leftChild->balance == 0)
     (*ptrToRoot) = rightRotate((*ptrToRoot));
    else{}
  }
  
  return replacement;
}