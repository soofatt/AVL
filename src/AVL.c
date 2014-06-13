#include "AVL.h"
#include "Rotation.h"
#include "Rotation_r.h"
#include <stdio.h>

Node *avlAdd(Node *root, Node *nodeToAdd){
  
  if(root == NULL)
    root = nodeToAdd;
  else if(nodeToAdd->data < root->data){
    if(root->leftChild != NULL){
      avlAdd(root->leftChild, nodeToAdd);
      if((root->leftChild->balance) - 0 != 0)
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
      avlAdd(root->rightChild, nodeToAdd);
      if((root->rightChild->balance) - 0 != 0)
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