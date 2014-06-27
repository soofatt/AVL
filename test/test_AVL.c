#include "unity.h"
#include "AVL.h"
#include "Rotation.h"
#include "mock_Rotation_r.h"

void setUp(void){}
void tearDown(void){}

/////////////////////////////////////////////////
// Test avlAdd
/////////////////////////////////////////////////
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

/////////////////////////////////////////////////
// Test avlRemove
/////////////////////////////////////////////////
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
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
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
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(1, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
}

/**
 *     (50)               (50)
 *     /  \       =>      /  \
 *   (25)(120)          (25)(150)
 *   /  \    \          /  \
 * (10) (35) (150)    (10) (35)
 *
 */
void test_avlRemove_should_remove_120(){
	Node node6 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 35, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 10, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 120, .balance = 1, .leftChild = NULL, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = 0, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 50, .balance = 0, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node6, root->rightChild);
}

/**
 *        (50)                      (50)
 *     /         \       =>      /         \
 *   (25)       (110)          (25)       (75)
 *   /  \       /   \          /  \       /   \
 * (10) (35)  (75) (150)    (10) (35)   (65) (150)
 *             /    / \                      /   \
 *          (65)(120)(175)                 (120) (175)
 *
 *
 */
// void test_avlRemove_should_remove_110(){
	// Node node10 = {.data = 175, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	// Node node9 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	// Node node8 = {.data = 65, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	// Node node7 = {.data = 150, .balance = 0, .leftChild = &node9, .rightChild = &node10};
	// Node node6 = {.data = 75, .balance =-1, .leftChild = &node8, .rightChild = NULL};
	// Node node5 = {.data = 35, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	// Node node4 = {.data = 10, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	// Node node3 = {.data = 110, .balance = 0, .leftChild = &node6, .rightChild = &node7};
	// Node node2 = {.data = 25, .balance = 0, .leftChild = &node4, .rightChild = &node5};
  // Node node1 = {.data = 50, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  // Node nodeRemove = {.data = 110, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  // Node *root = &node1;
  
  // root = avlRemove(root, &nodeRemove);
  
  // TEST_ASSERT_EQUAL(1, node1.balance);
  // TEST_ASSERT_EQUAL(0, node2.balance);
  // TEST_ASSERT_EQUAL(1, node6.balance);
  // TEST_ASSERT_EQUAL(0, node7.balance);
  
  // TEST_ASSERT_EQUAL_PTR(&node1, root);
  // TEST_ASSERT_EQUAL_PTR(&node6, node1.rightChild);
  // TEST_ASSERT_EQUAL_PTR(&node2, node1.leftChild);
// }

/////////////////////////////////////////////////
// Test avlGetReplacer
/////////////////////////////////////////////////
/**
 *
 *    (20)       =>   NULL
 *
 *
 */
void test_avlGetReplacer_should_get_20(){
  Node node1 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL_PTR(&node1, result);
  TEST_ASSERT_EQUAL_PTR(NULL, root);

}

/**
 *     (30)
 *     /            =>    (10)
 *   (10)
 *
 */
void test_avlGetReplacer_should_get_30(){
  Node node2 = {.data = 10, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 30, .balance = -1, .leftChild = &node2, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node1, result);
  TEST_ASSERT_EQUAL_PTR(&node2, root);

}

/**
 *     (10)
 *        \               =>  (10)
 *        (50)
 *
 */
void test_avlGetReplacer_should_get_50(){
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 10, .balance = 1, .leftChild = NULL, .rightChild = &node2};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);

}

/**
 *     (10)                   (10)
 *     /  \           =>      /
 *   (5) (60)               (5)
 *
 */
void test_avlGetReplacer_should_get_60(){
  Node node3 = {.data = 60, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 5, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 10, .balance = 0, .leftChild = &node2, .rightChild = &node3};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(NULL, root->rightChild);

}

/**
 *     (10)                       (10)
 *     /  \                       /  \
 *   (5) (55)          =>       (5)  (25)
 *        /
 *      (25)
 */
void test_avlGetReplacer_should_get_55(){
  Node node4 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 55, .balance = -1, .leftChild = &node4, .rightChild = NULL};
  Node node2 = {.data = 5, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 10, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->rightChild);

}

/** 
 *     (10)                      (10)
 *     /  \                      /  \
 *   (5) (55)          =>      (5)  (55)
 *       /  \                       /
 *    (25)  (220)                 (25)
 */
void test_avlGetReplacer_should_get_220(){
  Node node5 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node4 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 55, .balance = 0, .leftChild = &node4, .rightChild = &node5};
  Node node2 = {.data = 5, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 10, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(-1, node3.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node5, result);
  TEST_ASSERT_EQUAL_PTR(NULL, node3.rightChild);

}

/**
 *     (10)                           (10)
 *     /  \                           /  \
 *   (5)  (55)            =>        (5)  (55)
 *   /    /  \                      /    /  \
 * (1)  (25) (75)                 (1)  (25) (65)
 *           /
 *         (65)
 */
void test_avlGetReplacer_should_get_75(){
  Node node7 = {.data = 65, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node6 = {.data = 75, .balance = -1, .leftChild = &node7, .rightChild = NULL};
  Node node5 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 55, .balance = 1, .leftChild = &node5, .rightChild = &node6};
  Node node2 = {.data = 5, .balance = -1, .leftChild = &node4, .rightChild = NULL};
  Node node1 = {.data = 10, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node1.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node6, result);
  TEST_ASSERT_EQUAL_PTR(&node7, node3.rightChild);

}

/**
 *     (10)                      (5)
 *     /  \                      / \
 *   (5)  (100)       =>       (1) (10)
 *   /
 * (1)
 *
 */
void test_avlGetReplacer_should_get_100(){
  Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 5, .balance = -1, .leftChild = &node4, .rightChild = NULL};
  Node node1 = {.data = 10, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);

}

/**
 *      (50)                          (25)
 *     /    \                       /      \
 *   (10)   (100)                (10)     (50)
 *   /  \     \           =>     /  \     /  \     
 * (1)  (25)  (150)            (1) (20)(30)(100)
 *      /  \           
 *    (20) (30)          
 *
 */
void test_avlGetReplacer_should_get_150(){
  Node node8 = {.data = 30, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node7 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node6 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node5 = {.data = 25, .balance = 0, .leftChild = &node7, .rightChild = &node8};
  Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 100, .balance = 1, .leftChild = NULL, .rightChild = &node6};
  Node node2 = {.data = 10, .balance = 1, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node6, result);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);

}

/**
 *      (50)                          (25)
 *     /    \                       /      \
 *   (10)   (100)                (10)     (50)
 *   /  \     \           =>     /        /  \     
 * (1)  (25)  (300)            (1)      (30)(100)
 *         \           
 *         (30)          
 *
 */
void test_avlGetReplacer_should_get_300(){
  Node node7 = {.data = 30, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node6 = {.data = 300, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node5 = {.data = 25, .balance = 1, .leftChild = NULL, .rightChild = &node7};
  Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 100, .balance = 1, .leftChild = NULL, .rightChild = &node6};
  Node node2 = {.data = 10, .balance = 1, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, root->balance);
  
  TEST_ASSERT_EQUAL_PTR(&node6, result);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node1.leftChild);

}

/**
 *      (50)                          (25)
 *     /    \                       /      \
 *   (10)   (100)                (10)     (50)
 *   /  \     \           =>     /  \        \     
 * (1)  (25)  (350)            (1)  (20)     (100)
 *      /           
 *   (20)          
 *
 */
void test_avlGetReplacer_should_get_350(){
  Node node7 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node6 = {.data = 350, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node5 = {.data = 25, .balance = -1, .leftChild = &node7, .rightChild = NULL};
  Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 100, .balance = 1, .leftChild = NULL, .rightChild = &node6};
  Node node2 = {.data = 10, .balance = 1, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, root->balance);
  
  TEST_ASSERT_EQUAL_PTR(&node6, result);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node2.rightChild);

}

/**
 *        (50)                          (10)
 *       /    \                       /      \
 *     (10)   (100)                (5)       (50)
 *     /  \     \           =>     /         /  \     
 *   (5)  (25)  (225)            (1)       (25) (100)
 *   /    /                                /
 * (1)  (20)                            (20)
 *
 */
void test_avlGetReplacer_should_get_225(){
  Node node8 = {.data = 20, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node7 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node6 = {.data = 225, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node5 = {.data = 25, .balance = -1, .leftChild = &node8, .rightChild = NULL};
  Node node4 = {.data = 5, .balance = -1, .leftChild = &node7, .rightChild = NULL};
  Node node3 = {.data = 100, .balance = 1, .leftChild = NULL, .rightChild = &node6};
  Node node2 = {.data = 10, .balance = 0, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node *root = &node1;
  Node *result;
  
  result = avlGetReplacer(&root);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(1, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(1, root->balance);
  
  TEST_ASSERT_EQUAL_PTR(&node6, result);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node1.leftChild);

}