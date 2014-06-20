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
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(1, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);

  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node5, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node4, node2.rightChild);
  
}

/**
 *      (100)                        (100)
 *     /     \                      /     \
 *  (50)     (150)         =>    (50)     (150)
 *  /  \         \               /  \     /   \
 *(1)  (75)     (200)          (1)  (75)(120)(200)
 *
 */
void test_avlAdd_should_add_1_50_100_75_150_200_120(){
  Node node7 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
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
  root = avlAdd(root, &node7);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);

  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node5, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node4, node2.rightChild);
  
}

/**
 *      (100)                      (100)                           (120)
 *     /     \                  /         \                     /         \
 *  (50)     (150)     =>    (50)        (150)          =>   (100)       (150)
 *  /  \     /   \           /  \       /    \               /   \       /   \
 *(1)  (75)(120)(200)      (1) (75) (120)    (200)        (50)  (110) (130) (200)
 *                                  /   \       \         /  \           \     \
 *                               (110) (130)   (250)    (1) (75)        (140) (250)
 *                                        \
 *                                       (140)
 */
void test_avlAdd_should_add_1_50_100_75_150_200_120_110_130_250_140(){
  Node node11 = {.data = 140, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node10 = {.data = 250, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node9 = {.data = 130, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node8 = {.data = 110, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node7 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
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
  root = avlAdd(root, &node7);
  root = avlAdd(root, &node8);
  root = avlAdd(root, &node9);
  root = avlAdd(root, &node10);
  root = avlAdd(root, &node11);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(-1, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(1, node6.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  TEST_ASSERT_EQUAL(0, node8.balance);
  TEST_ASSERT_EQUAL(1, node9.balance);
  TEST_ASSERT_EQUAL(0, node10.balance);
  TEST_ASSERT_EQUAL(0, node11.balance);

  TEST_ASSERT_EQUAL_PTR(&node7, root);
  TEST_ASSERT_EQUAL_PTR(&node3, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node5, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node9, node5.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node3.rightChild);
  
}

/**
 *      (100)                      (100)                           (120)
 *     /     \                  /         \                     /         \
 *  (50)     (150)     =>    (50)        (150)          =>    (100)       (150)
 *  /  \     /   \           /  \       /    \               /    \       /   \
 *(1)  (75)(120)(200)      (1) (75) (120)    (200)        (50)   (110) (130) (200)
 *                                  /   \       \         /  \    /             \
 *                               (110) (130)   (250)    (1) (75)(105)          (250)
 *                                /
 *                            (105)
 */
void test_avlAdd_should_add_1_50_100_75_150_200_120_110_130_250_105(){
  Node node11 = {.data = 105, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node10 = {.data = 250, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node9 = {.data = 130, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node8 = {.data = 110, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node7 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
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
  root = avlAdd(root, &node7);
  root = avlAdd(root, &node8);
  root = avlAdd(root, &node9);
  root = avlAdd(root, &node10);
  root = avlAdd(root, &node11);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(1, node5.balance);
  TEST_ASSERT_EQUAL(1, node6.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  TEST_ASSERT_EQUAL(-1, node8.balance);
  TEST_ASSERT_EQUAL(0, node9.balance);
  TEST_ASSERT_EQUAL(0, node10.balance);
  TEST_ASSERT_EQUAL(0, node11.balance);

  TEST_ASSERT_EQUAL_PTR(&node7, root);
  TEST_ASSERT_EQUAL_PTR(&node3, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node5, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node9, node5.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node3.rightChild);
  
}

/**
 *     (50)               (25)
 *     /  \       =>      /  \
 *   (25)(75)           (10)(50)
 *   /
 * (10)
 *
 */
void test_avlRemove_should_remove_75(){
	Node node4 = {.data = 10, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
  Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  
  root = avlRemove(root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node1, node2.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node4, node2.leftChild);
}

/**
 *     (50)               (25)
 *     /  \       =>      /  \
 *   (25)(100)          (10)(50)
 *   /  \                    /
 * (10) (35)               (35)
 *
 */
void test_avlRemove_should_remove_100(){
	Node node5 = {.data = 35, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 10, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 25, .balance = 0, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  
  root = avlRemove(root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(1, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node1, node2.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node4, node2.leftChild);
}