#ifndef AVL_H
#define AVL_H

typedef struct Node{
	int balance;
	struct Node *leftChild;
	struct Node *rightChild;
	int data;
} Node;

Node *avlAdd(Node *root, Node *nodeToAdd);
Node *avlRemove(Node *root, Node *nodeToRemove);
Node *avlRemoveRootNode(Node *root);

#endif // AVL_H
