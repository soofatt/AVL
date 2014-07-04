#ifndef AVL_H
#define AVL_H

#define ERR_ALREADY_IN_TREE 1

typedef struct Node Node;

struct Node{
	int balance;
	Node *leftChild;
	Node *rightChild;
	int data;
};

Node *avlAdd(Node *root, Node *nodeToAdd, int (*compare)(void *, void*));
Node *avlRemove(Node **ptrToRoot, Node *nodeToRemove, int (*compare)(void *, void *));
Node *avlRemoveRootNode(Node *root);
Node *avlGetReplacer(Node **ptrToRoot);



#endif // AVL_H
