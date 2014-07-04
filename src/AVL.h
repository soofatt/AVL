#ifndef AVL_H
#define AVL_H

#define ERR_ALREADY_IN_TREE 1
#define avlAddInt(root, nodeToAdd) avlAdd(root, nodeToAdd, compareInt)

typedef struct Node{
	int balance;
	struct Node *leftChild;
	struct Node *rightChild;
	int data;
} Node;

Node *avlAdd(Node *root, Node *nodeToAdd, int (*compare)(void *, void*));
Node *avlRemove(Node **ptrToRoot, Node *nodeToRemove);
Node *avlRemoveRootNode(Node *root);
Node *avlGetReplacer(Node **ptrToRoot);

int compareInt(void *nodeInTree, void *nodeToCompare);

#endif // AVL_H
