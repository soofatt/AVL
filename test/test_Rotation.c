#include "unity.h"
#include "AVL.h"
#include "AVLInt.h"
#include "Rotation.h"
#include "mock_Rotation_r.h"

void setUp(void){}
void tearDown(void){}

/**
 *    (2)  
 *      \ 
 *      (1)
 *       
 *        
 *
 */
void test_getHeight_given_2_elements_should_return_2(){
	NodeInt node2 = {.data = 1, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node1 = {.data = 2, .balance=1, .leftChild = NULL, .rightChild = &node2};
  int height;
  
  _getHeight_ExpectAndReturn((Node *)&node2, 1);
  
  height = getHeight((Node *)&node1);
  
  TEST_ASSERT_EQUAL(2, height);
}

/**
 *    (2)     
 *      \     
 *      (1) 
 *      /
 *    (0)    
 *
 */
void test_getHeight_given_3_elements_should_return_3(){
	NodeInt node3 = {.data = 0, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 1, .balance=-1, .leftChild = &node3, .rightChild = NULL};
	NodeInt node1 = {.data = 2, .balance=2, .leftChild = NULL, .rightChild = &node2};
  int height;
  
  _getHeight_ExpectAndReturn((Node *)&node2, 2);
  
  height = getHeight((Node *)&node1);
  
  TEST_ASSERT_EQUAL(3, height);
}

/**
 *       (10)     
 *       / \     
 *     (6) (15) 
 *     / \   \
 *   (4) (7) (20)   
 *   /
 * (3)
 */
void test_getHeight_given_7_elements_should_return_4(){
	NodeInt node7 = {.data = 3, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node6 = {.data = 20, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node5 = {.data = 7, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node4 = {.data = 4, .balance=-1, .leftChild = &node7, .rightChild = NULL};
	NodeInt node3 = {.data = 15, .balance=1, .leftChild = NULL, .rightChild = &node6};
	NodeInt node2 = {.data = 6, .balance=-1, .leftChild = &node4, .rightChild = &node5};
	NodeInt node1 = {.data = 10, .balance=-1, .leftChild = &node2, .rightChild = &node3};
  int height;
  
  _getHeight_ExpectAndReturn((Node *)&node2, 3);
  _getHeight_ExpectAndReturn((Node *)&node3, 2);
  
  height = getHeight((Node *)&node1);
  
  TEST_ASSERT_EQUAL(4, height);
}

/**
 *    (2)               (1)
 *      \               / 
 *      (1)     =>    (2)
 *       
 *        
 *
 */
void test_leftRotate_given_2_elements_should_rotate_left(){
	NodeInt node2 = {.data = 1, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node1 = {.data = 2, .balance=1, .leftChild = NULL, .rightChild = &node2};
  NodeInt *root;
  
  root = (NodeInt *)leftRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
}

/**
 *    (1)               (2)
 *      \               / \
 *      (2)     =>    (1) (3)
 *        \
 *        (3)
 *
 */
void test_leftRotate_given_3_elements_should_rotate_to_balance_tree(){
	NodeInt node3 = {.data = 3, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 2, .balance=1, .leftChild = NULL, .rightChild = &node3};
	NodeInt node1 = {.data = 1, .balance=2, .leftChild = NULL, .rightChild = &node2};
  NodeInt *root;
  
  root = (NodeInt *)leftRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
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
	NodeInt node6 = {.data = 200, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node5 = {.data = 150, .balance=1, .leftChild = NULL, .rightChild = &node6};
	NodeInt node4 = {.data = 70, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node3 = {.data = 100, .balance=1, .leftChild = &node4, .rightChild = &node5};
	NodeInt node2 = {.data = 10, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node1 = {.data = 50, .balance=2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)leftRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node5, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node4, node1.rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(1, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
}

/**
 *    (2)               (1)
 *    /                   \ 
 *  (1)       =>          (2)
 *       
 *        
 *
 */
void test_rightRotate_given_2_elements_should_rotate_right(){
	NodeInt node2 = {.data = 1, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node1 = {.data = 2, .balance=-1, .leftChild = &node2, .rightChild = NULL};
  NodeInt *root;
  
  root = (NodeInt *)rightRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(1, node2.balance);
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
	NodeInt node1 = {.data = 1, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 2, .balance=-1, .leftChild = &node1, .rightChild = NULL};
	NodeInt node3 = {.data = 3, .balance=-2, .leftChild = &node2, .rightChild = NULL};
  NodeInt *root;
  
  root = (NodeInt *)(NodeInt *)rightRotate((Node *)&node3);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
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
	NodeInt node6 = {.data = 1, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node5 = {.data = 30, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node4 = {.data = 5, .balance=-1, .leftChild = &node6, .rightChild = NULL};
	NodeInt node3 = {.data = 100, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 20, .balance=-1, .leftChild = &node4, .rightChild = &node5};
	NodeInt node1 = {.data = 50, .balance=-2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)(NodeInt *)rightRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node1.leftChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(-1, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
}

/**
 *      (3)           (1)
 *      /             / \
 *    (2)     =>    (2) (3)
 *      \
 *      (1)
 *
 */
void test_doubleRightRotate_given_3_elements_should_rotate_to_balance_tree(){
	NodeInt node3 = {.data = 1, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 2, .balance=1, .leftChild = NULL, .rightChild = &node3};
	NodeInt node1 = {.data = 3, .balance=-2, .leftChild = &node2, .rightChild = NULL};
  NodeInt *root;
  
  root = (NodeInt *)doubleRightRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
}

/**
 *        (50)                  (20)
 *        /  \                  /  \
 *     (10)  (100)            (10)  (50)
 *     /  \           =>      /    /  \
 *   (5)  (20)              (5)  (40) (100)
 *          \
 *          (40)
 *
 */
void test_doubleRightRotate_given_6_elements_should_rotate_to_balance_tree_case1(){
	NodeInt node6 = {.data = 40, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node5 = {.data = 20, .balance=1, .leftChild = NULL, .rightChild = &node6};
	NodeInt node4 = {.data = 5, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node3 = {.data = 100, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 10, .balance=1, .leftChild = &node4, .rightChild = &node5};
	NodeInt node1 = {.data = 50, .balance=-2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)doubleRightRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node6, node1.leftChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
}

/*
 *        (50)                  (40)
 *        /  \                  /  \
 *     (10)  (100)            (10)  (50)
 *     /  \           =>      /  \    \
 *   (5)  (40)              (5)  (20) (100)
 *        /
 *      (20)
 */

void test_doubleRightRotate_given_6_elements_should_rotate_to_balance_tree_case2(){
	NodeInt node6 = {.data = 20, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node5 = {.data = 40, .balance=-1, .leftChild = &node6, .rightChild = NULL};
	NodeInt node4 = {.data = 5, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node3 = {.data = 100, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 10, .balance=1, .leftChild = &node4, .rightChild = &node5};
	NodeInt node1 = {.data = 50, .balance=-2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)doubleRightRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node6, node2.rightChild);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
}

/*
 *        (50)                       (30)
 *        /  \                    /        \
 *     (10)  (100)             (10)        (50)
 *     /  \      \     =>      /  \        /   \
 *   (5)  (30)   (150)       (5)  (20)   (40)  (100)
 *   /    /  \               /           /        \
 * (1) (20) (40)           (1)         (35)       (150)
 *          /
 *        (35)
 */
void test_doubleRightRotate_given_10_elements_should_rotate_to_balance_tree_case1(){
	NodeInt node10 = {.data = 35, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node9 = {.data = 40, .balance=-1, .leftChild = &node10, .rightChild = NULL};
	NodeInt node8 = {.data = 20, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node7 = {.data = 1, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node6 = {.data = 150, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node5 = {.data = 30, .balance=1, .leftChild = &node8, .rightChild = &node9};
	NodeInt node4 = {.data = 5, .balance=-1, .leftChild = &node7, .rightChild = NULL};
	NodeInt node3 = {.data = 100, .balance=1, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 10, .balance=1, .leftChild = &node4, .rightChild = &node5};
	NodeInt node1 = {.data = 50, .balance=-2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)doubleRightRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node2.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node9, node1.leftChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(1, node3.balance);
  TEST_ASSERT_EQUAL(-1, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  TEST_ASSERT_EQUAL(0, node8.balance);
  TEST_ASSERT_EQUAL(-1, node9.balance);
  TEST_ASSERT_EQUAL(0, node10.balance);
}

/**
 *        (50)                       (30)
 *        /  \                    /        \
 *     (10)  (100)             (10)        (50)
 *     /  \      \     =>      /  \        /   \
 *   (5)  (30)   (150)       (5)  (20)   (40)  (100)
 *   /    /  \               /        \           \
 * (1) (20) (40)           (1)       (25)        (150)
 *        \  
 *        (25)
 */
void test_doubleRightRotate_given_10_elements_should_rotate_to_balance_tree_case2(){
	NodeInt node10 = {.data = 25, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node9 = {.data = 40, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node8 = {.data = 20, .balance=1, .leftChild = NULL, .rightChild = &node10};
	NodeInt node7 = {.data = 1, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node6 = {.data = 150, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node5 = {.data = 30, .balance=-1, .leftChild = &node8, .rightChild = &node9};
	NodeInt node4 = {.data = 5, .balance=-1, .leftChild = &node7, .rightChild = NULL};
	NodeInt node3 = {.data = 100, .balance=1, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 10, .balance=1, .leftChild = &node4, .rightChild = &node5};
	NodeInt node1 = {.data = 50, .balance=-2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)doubleRightRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node2.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node9, node1.leftChild);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(1, node3.balance);
  TEST_ASSERT_EQUAL(-1, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  TEST_ASSERT_EQUAL(1, node8.balance);
  TEST_ASSERT_EQUAL(0, node9.balance);
  TEST_ASSERT_EQUAL(0, node10.balance);
}

/**
 *      (2)             (1)
 *        \             / \
 *        (3)     =>  (2) (3)
 *        /
 *      (1)
 *
 */
void test_doubleLeftRotate_given_3_elements_should_rotate_to_balance_tree(){
	NodeInt node3 = {.data = 1, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node2 = {.data = 3, .balance=-1, .leftChild = &node3, .rightChild = NULL};
	NodeInt node1 = {.data = 2, .balance=2, .leftChild = NULL, .rightChild = &node2};
  NodeInt *root;
  
  root = (NodeInt *)doubleLeftRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node2, root->rightChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
}

/**
 *        (50)                     (80)
 *        /  \                     /  \
 *     (10)  (100)               (50) (100)
 *            / \           =>   /  \    \
 *         (80) (110)          (10) (70) (110)
 *          /
 *       (70)
 *
 */
void test_doubleLeftRotate_given_6_elements_should_rotate_to_balance_tree_case1(){
	NodeInt node6 = {.data = 70, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node5 = {.data = 110, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node4 = {.data = 80, .balance=-1, .leftChild = &node6, .rightChild = NULL};
	NodeInt node3 = {.data = 100, .balance=-1, .leftChild = &node4, .rightChild = &node5};
	NodeInt node2 = {.data = 10, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node1 = {.data = 50, .balance=2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)doubleLeftRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node4, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node6, node1.rightChild);
  
  // TEST_ASSERT_EQUAL(0, node1.balance);
  // TEST_ASSERT_EQUAL(-1, node2.balance);
  // TEST_ASSERT_EQUAL(0, node3.balance);
  // TEST_ASSERT_EQUAL(0, node4.balance);
  // TEST_ASSERT_EQUAL(0, node5.balance);
  // TEST_ASSERT_EQUAL(0, node6.balance);
}

/**
 *        (50)                     (80)
 *        /  \                     /  \
 *     (10)  (100)               (50) (100)
 *            / \           =>   /    /   \
 *         (80) (110)          (10) (90) (110)
 *            \
 *           (90)
 *
 */
void test_doubleLeftRotate_given_6_elements_should_rotate_to_balance_tree_case2(){
	NodeInt node6 = {.data = 90, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node5 = {.data = 110, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node4 = {.data = 80, .balance=-1, .leftChild = NULL, .rightChild = &node6};
	NodeInt node3 = {.data = 100, .balance=-1, .leftChild = &node4, .rightChild = &node5};
	NodeInt node2 = {.data = 10, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node1 = {.data = 50, .balance=2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)doubleLeftRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node4, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node6, node3.leftChild);
  
  // TEST_ASSERT_EQUAL(0, node1.balance);
  // TEST_ASSERT_EQUAL(-1, node2.balance);
  // TEST_ASSERT_EQUAL(0, node3.balance);
  // TEST_ASSERT_EQUAL(0, node4.balance);
  // TEST_ASSERT_EQUAL(0, node5.balance);
  // TEST_ASSERT_EQUAL(0, node6.balance);
}

/**
 *        (50)                       (70)
 *        /  \                    /        \
 *     (10)  (100)             (50)        (100)
 *     /     /   \     =>      /  \        /   \
 *   (5)  (70)   (150)       (10)  (60)  (80)  (150)
 *        /  \      \        /       \           \
 *     (60) (80)   (200)   (5)       (65)        (200)
 *        \  
 *        (65)
 */
void test_doubleLeftRotate_given_10_elements_should_rotate_to_balance_tree_case1(){
	NodeInt node10 = {.data = 65, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node9 = {.data = 200, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node8 = {.data = 80, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node7 = {.data = 60, .balance=1, .leftChild = NULL, .rightChild = &node10};
	NodeInt node6 = {.data = 150, .balance=1, .leftChild = NULL, .rightChild = &node9};
	NodeInt node5 = {.data = 70, .balance=-1, .leftChild = &node7, .rightChild = &node8};
	NodeInt node4 = {.data = 5, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node3 = {.data = 100, .balance=-1, .leftChild = &node5, .rightChild = &node6};
	NodeInt node2 = {.data = 10, .balance=-1, .leftChild = &node4, .rightChild = NULL};
	NodeInt node1 = {.data = 50, .balance=2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)doubleLeftRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node1.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node3.leftChild);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(1, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(1, node6.balance);
  TEST_ASSERT_EQUAL(1, node7.balance);
  TEST_ASSERT_EQUAL(0, node8.balance);
  TEST_ASSERT_EQUAL(0, node9.balance);
  TEST_ASSERT_EQUAL(0, node10.balance);
}

/**
 *        (50)                       (70)
 *        /  \                    /        \
 *     (10)  (100)             (50)        (100)
 *     /     /   \     =>      /  \        /   \
 *   (5)  (70)   (150)       (10)  (60)  (80)  (150)
 *        /  \      \        /           /        \
 *     (60) (80)   (200)   (5)        (75)        (200)
 *          /
 *       (75)
 */
void test_doubleLeftRotate_given_10_elements_should_rotate_to_balance_tree_case2(){
	NodeInt node10 = {.data = 75, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node9 = {.data = 200, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node8 = {.data = 80, .balance=-1, .leftChild = &node10, .rightChild = NULL};
	NodeInt node7 = {.data = 60, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node6 = {.data = 150, .balance=1, .leftChild = NULL, .rightChild = &node9};
	NodeInt node5 = {.data = 70, .balance=1, .leftChild = &node7, .rightChild = &node8};
	NodeInt node4 = {.data = 5, .balance=0, .leftChild = NULL, .rightChild = NULL};
	NodeInt node3 = {.data = 100, .balance=-1, .leftChild = &node5, .rightChild = &node6};
	NodeInt node2 = {.data = 10, .balance=-1, .leftChild = &node4, .rightChild = NULL};
	NodeInt node1 = {.data = 50, .balance=2, .leftChild = &node2, .rightChild = &node3};
  NodeInt *root;
  
  root = (NodeInt *)doubleLeftRotate((Node *)&node1);
  
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node1.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node3.leftChild);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(1, node6.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  TEST_ASSERT_EQUAL(-1, node8.balance);
  TEST_ASSERT_EQUAL(0, node9.balance);
  TEST_ASSERT_EQUAL(0, node10.balance);
}