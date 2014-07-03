#include "AVL.h"
#include "Rotation.h"
#include "Rotation_r.h"
#include <stdio.h>

/**
 *Description : To add a node into the AVL tree
 *
 *Inputs : *root -> The pointer to root of the current tree
 *         *nodeToAdd -> The node to be added into the tree
 *
 *Output : root -> The new root of the tree
 *
 */
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

/**
 *Description : To remove a node from the AVL tree
 *
 *Inputs : **ptrToRoot -> The pointer to pointer to the root of the current tree
 *         *nodeToRemove -> The node to be removed from the tree
 *
 *Output : returnNode -> The node that is removed
 *
 */
Node *avlRemove(Node **ptrToRoot, Node *nodeToRemove){
  Node *returnNode = NULL;
  Node *tempNode;
  int tempBalanceLeft, tempBalanceRight, tempBalanceForReplacement;
  
  if((*ptrToRoot) !=NULL){
    if(nodeToRemove->data == (*ptrToRoot)->data){
      returnNode = (*ptrToRoot);
      tempNode = returnNode;
      
      if((*ptrToRoot)->leftChild == NULL){
        (*ptrToRoot) = (*ptrToRoot)->rightChild;
        
        if((*ptrToRoot) != NULL){
          (*ptrToRoot)->leftChild = tempNode->leftChild;
          (*ptrToRoot)->rightChild = tempNode->rightChild;
          (*ptrToRoot)->balance = tempNode->balance;
          (*ptrToRoot)->balance--;
        }
      }
      
      else{
        tempBalanceForReplacement = (*ptrToRoot)->leftChild->balance;
        (*ptrToRoot) = avlGetReplacer(&(*ptrToRoot)->leftChild);
        
        if((*ptrToRoot) != NULL){
          (*ptrToRoot)->leftChild = tempNode->leftChild;
          (*ptrToRoot)->rightChild = tempNode->rightChild;
          (*ptrToRoot)->balance = tempNode->balance;
          if((*ptrToRoot)->leftChild == NULL)
            (*ptrToRoot)->balance++;
          
          else if((*ptrToRoot)->leftChild->balance == 0){
            if(tempBalanceForReplacement - (*ptrToRoot)->leftChild->balance != 0)
              (*ptrToRoot)->balance++;
            else{}
          }
          
          else{}
        }
      }
    }  
    
    else if(nodeToRemove->data < (*ptrToRoot)->data){
      if((*ptrToRoot)->leftChild != NULL)
        tempBalanceLeft = (*ptrToRoot)->leftChild->balance;
        
      returnNode = avlRemove(&(*ptrToRoot)->leftChild, nodeToRemove);
      
      if(returnNode == NULL)
        return returnNode;
      
      if((*ptrToRoot)->leftChild == NULL)
        (*ptrToRoot)->balance++;
        
      else if((*ptrToRoot)->leftChild->balance == 0){
        if(tempBalanceLeft - (*ptrToRoot)->leftChild->balance != 0)
          (*ptrToRoot)->balance++;
        else {}
      }
      
      else{}
    }
    
    else if(nodeToRemove->data > (*ptrToRoot)->data){
      if((*ptrToRoot)->rightChild != NULL)
        tempBalanceRight = (*ptrToRoot)->rightChild->balance;
      
      returnNode = avlRemove(&(*ptrToRoot)->rightChild, nodeToRemove);
      
      if(returnNode == NULL)
        return returnNode;
      
      if((*ptrToRoot)->rightChild == NULL)
        (*ptrToRoot)->balance--;
      
      else if((*ptrToRoot)->rightChild->balance == 0){
        if(tempBalanceRight - (*ptrToRoot)->rightChild->balance != 0)
          (*ptrToRoot)->balance--;
        else{}
      }
      
      else{}
    }
  }  
    
  if((*ptrToRoot) !=NULL){
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
  
  return returnNode;
}

/**
 *Description : To get the replacement node for avlRemove
 *
 *Inputs : **ptrToRoot -> The pointer to pointer to the root of the current tree
 *
 *Output : replacement -> The node that will replace the removed node in avlRemove
 *
 */
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