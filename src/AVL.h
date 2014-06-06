#ifndef AVL_H
#define AVL_H

typedef struct Node{
	int rank;
	struct Node *leftChild;
	struct Node *rightChild;
	int data;
} Node;

#endif // AVL_H
