#include "unity.h"
#include "AVL.h"
#include "Rotation.h"
#include "mock_Rotation_r.h"

void setUp(void){}
void tearDown(void){}

/**
 *   (100)                  (100)
 *                 =>          \
 *                             (160)
 *
 *
 *
 */
void test_avlAdd_given_160_should_change_node1_balance_factor(){
	Node node2 = {.data = 160, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &node1);
  root = avlAdd(root, &node2);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, node1.rightChild);
}

/**
 *   (100)                  (100)
 *                 =>        /
 *                        (80)
 *
 *
 *
 */
void test_avlAdd_given_80_should_change_node1_balance_factor(){
	Node node2 = {.data = 80, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &node1);
  root = avlAdd(root, &node2);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, node1.leftChild);
}

/**
 *   (100)                  (100)
 *   /   \                  /   \
 * (50)  (150)       =>  (50)  (150)
 *       /                     /   \
 *    (120)                 (120)  (200)
 */
void test_avlAdd_given_200_should_not_change_node1_balance_factor(){
	Node node5 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &node1);
  root = avlAdd(root, &node2);
  root = avlAdd(root, &node3);
  root = avlAdd(root, &node4);
  root = avlAdd(root, &node5);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node5, node3.rightChild);
}

/**
 *   (100)                  (100)
 *   /   \                  /   \
 * (50)  (150)       =>  (50)  (150)
 *           \                 /   \
 *          (200)          (120)  (200)
 */
void test_avlAdd_given_120_should_not_change_node1_balance_factor(){
	Node node5 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &node1);
  root = avlAdd(root, &node2);
  root = avlAdd(root, &node3);
  root = avlAdd(root, &node4);
  root = avlAdd(root, &node5);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node5, node3.leftChild);
}

/**
 *   (100)                  (100)
 *   /   \                  /   \
 * (50)  (150)       =>  (50)  (150)
 *                                \
 *                               (200) 
 */
void test_avlAdd_given_200_should_change_node1_balance_factor(){
	Node node4 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &node1);
  root = avlAdd(root, &node2);
  root = avlAdd(root, &node3);
  root = avlAdd(root, &node4);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(1, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node4, node3.rightChild);
}

/**
 *   (100)                  (100)
 *   /   \                  /   \
 * (50)  (150)       =>  (50)  (150)
 *                              /
 *                          (120) 
 */
void test_avlAdd_given_120_should_change_node1_balance_factor(){
	Node node4 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &node1);
  root = avlAdd(root, &node2);
  root = avlAdd(root, &node3);
  root = avlAdd(root, &node4);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(-1, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node4, node3.leftChild);
}

/**
 *    (1)           (1)             (1)                  (50)
 *                    \               \                  /  \
 *                    (50)            (50)            (1)   (100)
 *            =>              =>         \       =>
 *                                       (100)
 * 
 * 
 */
void test_avlAdd_should_add_1_50_100(){
  Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &node1);
  root = avlAdd(root, &node2);
  root = avlAdd(root, &node3);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *    (50)             (50)             (50)                 (50)                   (100)
 *    /  \             /  \             /  \                 /  \                   /   \
 *  (1)  (100)   =>  (1)  (100)  =>   (1)  (100)      =>   (1)  (100)      =>    (50)   (150)
 *                         /               /   \                /   \            /  \     \
 *                      (75)            (75)   (150)          (75)  (150)      (1)  (75)  (200)
 *                                                                    \
 *                                                                    (200)
 *
 */
void test_avlAdd_should_add_1_50_100_75_150_200(){
  Node node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAdd(root, &node1);
  root = avlAdd(root, &node2);
  root = avlAdd(root, &node3);
  root = avlAdd(root, &node4);
  root = avlAdd(root, &node5);
  root = avlAdd(root, &node6);
  
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(1, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);

  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node5, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node4, node2.rightChild);
  
}
