#include "unity.h"
#include "AVL.h"
#include "Rotation.h"

void setUp(void){}
void tearDown(void){}

/**
 *    (1)               (2)
 *      \               / \
 *      (2)     =>    (1) (3)
 *        \
 *        (3)
 *
 */
void test_leftRotate_given_3_elements_should_rotate_to_balance_tree(){
	Node node3 = {.data = 3, .rank=0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 2, .rank=1, .leftChild = NULL, .rightChild = &node3};
	Node node1 = {.data = 1, .rank=2, .leftChild = NULL, .rightChild = &node2};
  Node *root;
  
  root = leftRotate(&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.rank);
  TEST_ASSERT_EQUAL(0, node2.rank);
  TEST_ASSERT_EQUAL(0, node3.rank);
}

/**
 *        (50)                     (100)
 *        /   \                    /   \
 *      (10) (100)               (50)  (150)
 *            / \         =>     / \      \
 *         (70) (150)          (10)(70)   (200)
 *                \
 *                (200)
 */
void test_leftRotate_given_6_elements_should_rotate_to_balance_tree(){
	Node node6 = {.data = 200, .rank=0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 150, .rank=1, .leftChild = NULL, .rightChild = &node6};
	Node node4 = {.data = 70, .rank=0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 100, .rank=1, .leftChild = &node4, .rightChild = &node5};
	Node node2 = {.data = 10, .rank=0, .leftChild = NULL, .rightChild = NULL};
	Node node1 = {.data = 50, .rank=2, .leftChild = &node2, .rightChild = &node3};
  Node *root;
  
  root = leftRotate(&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node5, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.rank);
  TEST_ASSERT_EQUAL(0, node2.rank);
  TEST_ASSERT_EQUAL(0, node3.rank);
  TEST_ASSERT_EQUAL(0, node4.rank);
  TEST_ASSERT_EQUAL(1, node5.rank);
  TEST_ASSERT_EQUAL(0, node6.rank);
}

/**
 *      (3)           (2)
 *      /             / \
 *    (2)     =>    (1) (3)
 *    /
 *  (1)
 *
 */
void test_rightRotate_given_3_elements_should_rotate_to_balance_tree(){
	Node node1 = {.data = 1, .rank=0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 2, .rank=1, .leftChild = &node1, .rightChild = NULL};
	Node node3 = {.data = 3, .rank=2, .leftChild = &node2, .rightChild = NULL};
  Node *root;
  
  root = rightRotate(&node3);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.rank);
  TEST_ASSERT_EQUAL(0, node2.rank);
  TEST_ASSERT_EQUAL(0, node3.rank);
}

/**
 *        (50)                  (20)
 *        /  \                  /  \
 *     (20)  (100)            (5)  (50)
 *     /  \           =>      /    /  \
 *   (5)  (30)              (1)  (30) (100)
 *  /
 *(1) 
 *
 */
void test_rightRotate_given_6_elements_should_rotate_to_balance_tree(){
	Node node6 = {.data = 1, .rank=0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 30, .rank=0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 5, .rank=-1, .leftChild = &node6, .rightChild = NULL};
	Node node3 = {.data = 100, .rank=0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 20, .rank=-1, .leftChild = &node4, .rightChild = &node5};
	Node node1 = {.data = 50, .rank=-2, .leftChild = &node2, .rightChild = &node3};
  Node *root;
  
  root = rightRotate(&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.rank);
  TEST_ASSERT_EQUAL(0, node2.rank);
  TEST_ASSERT_EQUAL(0, node3.rank);
  TEST_ASSERT_EQUAL(-1, node4.rank);
  TEST_ASSERT_EQUAL(0, node5.rank);
  TEST_ASSERT_EQUAL(0, node6.rank);
}