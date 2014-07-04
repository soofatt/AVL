#include "unity.h"
#include "CException.h"
#include "AVL.h"
#include "Rotation.h"
#include "mock_Rotation_r.h"

void setUp(void){}
void tearDown(void){}

/////////////////////////////////////////////////
// Test avlAddInt
/////////////////////////////////////////////////
/**
 *   (100)                    (100)
 *   /   \              =>    /   \
 * (50)  (150)              (50)  (150)
 *
 *
 *
 */
void test_avlAddInt_given_150_should_print_error_because_already_in_tree(){
	CEXCEPTION_T e;
  
  Node node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  Try{
    root = avlAddInt(root, &node1);
    root = avlAddInt(root, &node2);
    root = avlAddInt(root, &node3);
    root = avlAddInt(root, &node4);
  }Catch(e){
    TEST_ASSERT_EQUAL(ERR_ALREADY_IN_TREE, e);
  }
  
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *   (100)                  (100)
 *                 =>          \
 *                             (160)
 *
 *
 *
 */
void test_avlAddInt_given_160_should_change_node1_balance_factor(){
	Node node2 = {.data = 160, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, node1.rightChild);
}

/**
 *   (100)                  (100)
 *   /   \                  /   \
 * (50)  (150)       =>  (50)  (150)
 *       /                     /   \
 *    (120)                 (120)  (200)
 */
void test_avlAddInt_given_200_should_not_change_node1_balance_factor(){
	Node node5 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  
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
void test_avlAddInt_given_120_should_not_change_node1_balance_factor(){
	Node node5 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  
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
void test_avlAddInt_given_200_should_change_node1_balance_factor(){
	Node node4 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  
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
void test_avlAddInt_given_120_should_change_node1_balance_factor(){
	Node node4 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  
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
void test_avlAddInt_should_add_1_50_100(){
  Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  
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
void test_avlAddInt_should_add_1_50_100_75_150_200(){
  Node node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  root = avlAddInt(root, &node6);
  
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
void test_avlAddInt_should_add_1_50_100_75_150_200_120(){
  Node node7 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node5 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  root = avlAddInt(root, &node6);
  root = avlAddInt(root, &node7);
  
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
void test_avlAddInt_should_add_1_50_100_75_150_200_120_110_130_250_140(){
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
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  root = avlAddInt(root, &node6);
  root = avlAddInt(root, &node7);
  root = avlAddInt(root, &node8);
  root = avlAddInt(root, &node9);
  root = avlAddInt(root, &node10);
  root = avlAddInt(root, &node11);
  
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
void test_avlAddInt_should_add_1_50_100_75_150_200_120_110_130_250_105(){
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
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  root = avlAddInt(root, &node6);
  root = avlAddInt(root, &node7);
  root = avlAddInt(root, &node8);
  root = avlAddInt(root, &node9);
  root = avlAddInt(root, &node10);
  root = avlAddInt(root, &node11);
  
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
 *   (100)                  (100)
 *                 =>        /
 *                        (80)
 *
 *
 *
 */
void test_avlAddInt_given_80_should_change_node1_balance_factor(){
	Node node2 = {.data = 80, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, node1.leftChild);
}

/**
 *    (100)                  (100)
 *    /   \        =>        /   \
 *  (50) (150)            (50)   (150)
 *  /                     /  \
 *(25)                  (25) (75)
 *
 */
void test_avlAddInt_given_75_should_not_change_node1_balance_factor(){
	Node node5 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *    (100)                  (100)
 *    /   \        =>        /   \
 *  (50) (150)            (50)   (150)
 *     \                  /  \
 *     (75)             (25) (75)
 *
 */
void test_avlAddInt_given_25_should_not_change_node1_balance_factor(){
	Node node5 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *    (100)                  (100)
 *    /   \        =>        /   \
 *  (50) (150)            (50)   (150)
 *                        /  
 *                     (25) 
 *
 */
void test_avlAddInt_given_25_should_change_node1_balance_factor(){
	Node node4 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *    (100)                  (100)
 *    /   \        =>        /   \
 *  (50) (150)            (50)   (150)
 *                           \  
 *                          (75) 
 *
 */
void test_avlAddInt_given_75_should_change_node1_balance_factor(){
	Node node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(1, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *    (200)            (150)
 *    /         =>     /   \
 *  (150)            (100)  (200)
 *  /           
 *(100)      
 *
 */
void test_avlAddInt_given_200_150_100(){
	Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node3, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
}

/**
 *       (150)                      (100)
 *       /   \                      /   \
 *    (100)  (200)               (75)  (150)
 *    /   \             =>       /     /   \
 *  (75)  (125)                (25)  (125) (200)
 *  /
 *(25)
 *
 */
void test_avlAddInt_given_200_150_100_75_125_25(){
	Node node6 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 125, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  root = avlAddInt(root, &node6);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(-1, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node2, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node2.leftChild);
}

/**
 *      (100)                        (100)
 *      /   \                       /     \
 *    (75)  (150)         =>     (75)     (150)   
 *    /     /   \                /  \     /  \ 
 *  (25)  (125) (200)         (25)  (90)(125)(200)
 *
 *
 *
 */
void test_avlAddInt_given_200_150_100_75_125_25_90(){
	Node node7 = {.data = 90, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 125, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  root = avlAddInt(root, &node6);
  root = avlAddInt(root, &node7);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node2, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node2.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node4.rightChild);
}

/**
 *          (100)                           (90)
 *         /     \                       /        \
 *      (75)     (150)      =>        (75)       (100)
 *      /  \      /  \                /  \        /  \
 *    (25) (90)(125)(200)          (25)  (80)  (95) (150)
 *    /    /  \                    /        \        /  \
 *  (10) (80) (95)               (10)      (85)   (125)(200)
 *         \
 *        (85)
 */
void test_avlAddInt_given_200_150_100_75_125_25_90_80_95_10_85(){
	Node node11 = {.data = 85, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node10 = {.data = 10, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node9 = {.data = 95, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node8 = {.data = 80, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node7 = {.data = 90, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 125, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  root = avlAddInt(root, &node6);
  root = avlAddInt(root, &node7);
  root = avlAddInt(root, &node8);
  root = avlAddInt(root, &node9);
  root = avlAddInt(root, &node10);
  root = avlAddInt(root, &node11);
  
  TEST_ASSERT_EQUAL(1, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node7, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node9, node3.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node4.rightChild);
}

/**
 *          (100)                           (90)
 *         /     \                       /        \
 *      (75)     (150)      =>        (75)       (100)
 *      /  \      /  \                /  \       /    \
 *    (25) (90)(125)(200)          (25)  (80)  (95)   (150)
 *    /    /  \                    /              \    /  \
 *  (10) (80) (95)               (10)            (97)(125)(200)
 *               \
 *               (97)
 */
void test_avlAddInt_given_200_150_100_75_125_25_90_80_95_10_97(){
	Node node11 = {.data = 97, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node10 = {.data = 10, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node9 = {.data = 95, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node8 = {.data = 80, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node7 = {.data = 90, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 125, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 100, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = NULL;
  
  root = avlAddInt(root, &node1);
  root = avlAddInt(root, &node2);
  root = avlAddInt(root, &node3);
  root = avlAddInt(root, &node4);
  root = avlAddInt(root, &node5);
  root = avlAddInt(root, &node6);
  root = avlAddInt(root, &node7);
  root = avlAddInt(root, &node8);
  root = avlAddInt(root, &node9);
  root = avlAddInt(root, &node10);
  root = avlAddInt(root, &node11);
  
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(-1, node4.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node7, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node9, node3.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node4.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node11, node9.rightChild);
}

/////////////////////////////////////////////////
// Test avlRemove
/////////////////////////////////////////////////
/**
 *     (50)    =>    NULL
 *
 *
 *
 *
 */
void test_avlRemove_should_remove_50_and_return_NULL(){
	Node node1 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node nodeRemove = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL_PTR(&node1, result);
  TEST_ASSERT_EQUAL_PTR(NULL, root);
}

/**
 *     (50)    =>     (50)
 *     /  \           /  \
 *  (25) (150)     (25) (150)
 *           \             \
 *          (200)         (200)
 */
void test_avlRemove_should_attempt_to_remove_1_but_will_return_NULL(){
	Node node4 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node4};
	Node node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node1 = {.data = 50, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(1, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(NULL, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
}

/**
 *     (50)    =>     (50)
 *     /  \              \
 *  (25) (150)          (150)
 *  
 *          
 */
void test_avlRemove_should_remove_25_in_the_left_subtree_case1(){
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node1 = {.data = 50, .balance = 0, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(1, root->balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
}

/**
 *       (50)    =>     (50)        =>         (150)
 *       /  \              \                   /   \
 *    (25) (150)          (150)              (50)(200)
 *            \              \
 *           (200)          (200)
 */
void test_avlRemove_should_remove_25_in_the_left_subtree_case2_and_should_leftRotate(){
	Node node4 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node4};
	Node node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node1 = {.data = 50, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, result);
  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node4, root->rightChild);
}

/**
 *       (50)    =>     (50)       
 *       /  \           /  \
 *    (25) (150)      (1) (150) 
 *    /       \              \
 *  (1)       (200)          (200)
 */
void test_avlRemove_should_remove_25_in_the_left_subtree_case3(){
	Node node5 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node5};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
	Node node1 = {.data = 50, .balance = 0, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(1, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *       (100)        =>       (150)       
 *       /   \                /     \
 *    (25)   (200)         (100)    (200) 
 *    /      /   \         /   \    /   \
 *  (1)   (150) (220)   (25) (120)(175)(220)
 *        /   \
 *     (120) (175)
 *
 */
void test_avlRemove_should_remove_1_in_the_left_subtree_case1_should_doubleLeftRotate(){
	Node node8 = {.data = 175, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node7 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 150, .balance = 0, .leftChild = &node7, .rightChild = &node8};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = -1, .leftChild = &node5, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
	Node node1 = {.data = 100, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node4, result);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node3.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node1.rightChild);
}

/**
 *       (100)        =>       (150)       
 *       /   \                /     \
 *    (25)   (200)         (100)    (200) 
 *    /      /   \         /   \        \
 *  (1)   (150) (220)   (25) (120)     (220)
 *        /   
 *     (120) 
 *
 */
void test_avlRemove_should_remove_1_in_the_left_subtree_case2_should_doubleLeftRotate(){
	Node node7 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 150, .balance = -1, .leftChild = &node7, .rightChild = NULL};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = -1, .leftChild = &node5, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
	Node node1 = {.data = 100, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(1, node3.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node4, result);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node3.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node1.rightChild);
}

/**
 *       (100)        =>       (150)       
 *       /   \                /     \
 *    (25)   (200)         (100)    (200) 
 *    /      /   \         /        /   \
 *  (1)   (150) (220)   (25)      (175)(220)
 *            \
 *           (175)
 *
 */
void test_avlRemove_should_remove_1_in_the_left_subtree_case3_should_doubleLeftRotate(){
	Node node7 = {.data = 175, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node7};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = -1, .leftChild = &node5, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
	Node node1 = {.data = 100, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node4, result);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node3.leftChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node1.rightChild);
}

/**
 *       (100)        =>         (200)       
 *       /   \                  /     \
 *    (25)   (200)           (100)    (220) 
 *    /      /   \           /   \        \
 *  (1)   (150) (220)     (25)  (150)     (250)
 *            \    \               \
 *           (175) (250)          (175)
 *
 */
void test_avlRemove_should_remove_1_in_the_left_subtree_case4_should_doubleLeftRotate(){
	Node node8 = {.data = 250, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node7 = {.data = 175, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 220, .balance = 1, .leftChild = NULL, .rightChild = &node8};
	Node node5 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node7};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = 0, .leftChild = &node5, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
	Node node1 = {.data = 100, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(-1, node3.balance);
  TEST_ASSERT_EQUAL(1, node5.balance);
  TEST_ASSERT_EQUAL(1, node6.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node4, result);
  TEST_ASSERT_EQUAL_PTR(&node3, root);
  TEST_ASSERT_EQUAL_PTR(&node1, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node6, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node1.rightChild);
}

/**
 *     (50)    =>      (50)
 *     /  \           /    \
 *  (25) (200)      (40)   (200)
 *     \             
 *    (40)           
 */
void test_avlRemove_should_remove_25_in_the_left_subtree_case4(){
	Node node4 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 25, .balance = 1, .leftChild = NULL, .rightChild = &node4};
	Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *     (50)    =>      (50)
 *     /  \           /    \
 *  (25) (200)      (1)   (200)
 *  /  \              \
 *(1) (40)            (40)
 *
 */
void test_avlRemove_should_remove_25_in_the_left_subtree_case5(){
	Node node5 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 25, .balance = 0, .leftChild = &node4, .rightChild = &node5};
	Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(1, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node2, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node4.rightChild);
}

/**
 *     (150)       =>      (90)
 *     /  \               /    \
 *  (25) (200)          (25)   (200)
 *  /  \    \          /   \      \
 *(1) (40)  (250)    (1)   (40)   (250)
 *       \
 *       (90)
 *
 *
 */
void test_avlRemove_should_remove_150_at_root_case1(){
	Node node7 = {.data = 90, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 250, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 40, .balance = 1, .leftChild = NULL, .rightChild = &node7};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = 1, .leftChild = NULL, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = 1, .leftChild = &node4, .rightChild = &node5};
	Node node1 = {.data = 150, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node7.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node1, result);
  TEST_ASSERT_EQUAL_PTR(&node7, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *     (150)       =>      (90)
 *     /  \               /    \
 *  (25) (200)          (25)   (200)
 *  /  \    \          /   \      \
 *(1) (50)  (250)    (1)   (50)   (250)
 *    /  \                 /
 *  (40)(90)             (40)
 *
 *
 */
void test_avlRemove_should_remove_150_at_root_case2(){
	Node node8 = {.data = 90, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node7 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 250, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 50, .balance = 0, .leftChild = &node7, .rightChild = &node8};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = 1, .leftChild = NULL, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = 1, .leftChild = &node4, .rightChild = &node5};
	Node node1 = {.data = 150, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node8.balance);
  TEST_ASSERT_EQUAL(1, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node1, result);
  TEST_ASSERT_EQUAL_PTR(&node8, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node5.rightChild);
}

/**
 *     (50)               (50)
 *     /  \       =>      /  \
 *   (25)(150)          (25)(150)
 *   /                  /
 * (1)                (1)
 *
 */
void test_avlRemove_should_attempt_to_remove_200_but_will_return_NULL(){
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
  Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(NULL, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node3, root->rightChild);
}

/**
 *     (50)               (50)
 *     /  \       =>      /  
 *   (25)(150)          (25)
 *
 */
void test_avlRemove_should_remove_150_in_the_right_subtree_case1(){
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 50, .balance = 0, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(NULL, root->rightChild);
}

/**
 *     (50)               (50)             (25)
 *     /  \       =>      /      =>        /  \
 *   (25)(150)          (25)             (1)  (50)
 *   /                  /
 * (1)                (1)
 *
 */
void test_avlRemove_should_remove_150_in_the_right_subtree_case2_should_right_rotate(){
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
  Node node1 = {.data = 50, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
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
  TEST_ASSERT_EQUAL_PTR(NULL, node1.rightChild);
}

/**
 *     (50)               (50)           
 *     /  \       =>      /  \ 
 *   (25)(150)          (25) (200)    
 *   /      \           /
 * (1)      (200)     (1)
 *
 */
void test_avlRemove_should_remove_150_in_the_right_subtree_case3(){
	Node node5 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node5};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
  Node node1 = {.data = 50, .balance = 0, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node5, root->rightChild);
}

/**
 *     (100)                          (50)
 *     /   \                         /    \
 *   (25)  (150)                  (25)    (100)
 *   /  \     \         =>        /  \    /   \
 * (1)  (50)  (200)             (1) (40)(75) (150)
 *      /  \
 *    (40)(75)
 *
 */
void test_avlRemove_should_remove_200_in_the_right_subtree_case1_should_double_right_rotate(){
	Node node8 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node7 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 50, .balance = 0, .leftChild = &node7, .rightChild = &node8};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = 1, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 100, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  TEST_ASSERT_EQUAL(0, node8.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node6, result);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node2.rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node3.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node8, node1.leftChild);
}

/**
 *     (100)                          (50)
 *     /   \                         /    \
 *   (25)  (150)                  (25)    (100)
 *   /  \     \         =>        /       /   \
 * (1)  (50)  (200)             (1)     (75) (150)
 *         \
 *        (75)
 *
 */
void test_avlRemove_should_remove_200_in_the_right_subtree_case2_should_double_right_rotate(){
	Node node7 = {.data = 75, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 50, .balance = 1, .leftChild = NULL, .rightChild = &node7};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = 1, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 100, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node6, result);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node2.rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node3.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node1.leftChild);
}

/**
 *     (100)                          (50)
 *     /   \                         /    \
 *   (25)  (150)                  (25)    (100)
 *   /  \     \         =>        /  \       \
 * (1)  (50)  (200)             (1) (40)    (150)
 *      /
 *    (40)
 *
 */
void test_avlRemove_should_remove_200_in_the_right_subtree_case3_should_double_right_rotate(){
	Node node7 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 50, .balance = -1, .leftChild = &node7, .rightChild = NULL};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = 1, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 100, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node6, result);
  TEST_ASSERT_EQUAL_PTR(&node5, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node7, node2.rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node3.rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node1.leftChild);
}

/**
 *       (100)                          (40)
 *       /   \                         /    \
 *     (40)  (150)                  (25)    (100)
 *     /  \     \         =>        /       /   \
 *   (25) (75)  (200)             (1)     (75)  (150)
 *   /     /                              /
 * (1)   (50)                           (50)
 *
 *
 *
 */
void test_avlRemove_should_remove_200_in_the_right_subtree_case4_should_right_rotate(){
	Node node8 = {.data = 50, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node7 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 75, .balance = -1, .leftChild = &node8, .rightChild = NULL};
	Node node4 = {.data = 25, .balance = -1, .leftChild = &node7, .rightChild = NULL};
	Node node3 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node6};
	Node node2 = {.data = 40, .balance = 0, .leftChild = &node4, .rightChild = &node5};
  Node node1 = {.data = 100, .balance = -1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(-1, node1.balance);
  TEST_ASSERT_EQUAL(1, node2.balance);
  TEST_ASSERT_EQUAL(0, node3.balance);
  TEST_ASSERT_EQUAL(-1, node4.balance);
  TEST_ASSERT_EQUAL(-1, node5.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  TEST_ASSERT_EQUAL(0, node8.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node6, result);
  TEST_ASSERT_EQUAL_PTR(&node2, root);
  TEST_ASSERT_EQUAL_PTR(&node4, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node1, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node3.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node1.leftChild);
}

/**
 *     (50)               (50)   
 *     /  \       =>      /  \  
 *   (25)(200)          (25) (150)      
 *        /               
 *     (150)              
 *
 */
void test_avlRemove_should_remove_200_in_the_right_subtree_case5(){
	Node node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = -1, .leftChild = &node4, .rightChild = NULL};
	Node node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 50, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node4, root->rightChild);
}

/**
 *     (50)               (50)   
 *     /  \       =>      /  \  
 *   (25)(200)          (25) (150)      
 *        / \                  \
 *     (150)(220)              (220)
 *
 */
void test_avlRemove_should_remove_200_in_the_right_subtree_case6(){
	Node node5 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node4 = {.data = 150, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = 0, .leftChild = &node4, .rightChild = &node5};
	Node node2 = {.data = 25, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node node1 = {.data = 50, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(0, node2.balance);
  TEST_ASSERT_EQUAL(1, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node4, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node4.rightChild);
}

/**
 *     (50)               (50)   
 *     /  \       =>      /  \  
 *   (25)(200)          (25) (175)      
 *   /    / \           /    /   \
 * (1) (150)(220)     (1)  (150)(220)
 *       \
 *      (175)
 *
 */
void test_avlRemove_should_remove_200_in_the_right_subtree_case7(){
	Node node7 = {.data = 175, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 150, .balance = 1, .leftChild = NULL, .rightChild = &node7};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = -1, .leftChild = &node5, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
  Node node1 = {.data = 50, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(0, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node7, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node7.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node6, node7.rightChild);
}

/**
 *     (50)               (50)   
 *     /  \       =>      /  \  
 *   (25)(200)          (25) (175)      
 *   /    / \           /    /   \
 * (1) (150)(220)     (1)  (150)(220)
 *      / \                /
 *   (120)(175)          (120)
 *
 */
void test_avlRemove_should_remove_200_in_the_right_subtree_case8(){
	Node node8 = {.data = 175, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node7 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node6 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node5 = {.data = 150, .balance = 0, .leftChild = &node7, .rightChild = &node8};
	Node node4 = {.data = 1, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node3 = {.data = 200, .balance = -1, .leftChild = &node5, .rightChild = &node6};
	Node node2 = {.data = 25, .balance = -1, .leftChild = &node4, .rightChild = NULL};
  Node node1 = {.data = 50, .balance = 1, .leftChild = &node2, .rightChild = &node3};
  Node nodeRemove = {.data = 200, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node1;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(1, node1.balance);
  TEST_ASSERT_EQUAL(-1, node2.balance);
  TEST_ASSERT_EQUAL(0, node4.balance);
  TEST_ASSERT_EQUAL(-1, node5.balance);
  TEST_ASSERT_EQUAL(0, node6.balance);
  TEST_ASSERT_EQUAL(0, node7.balance);
  TEST_ASSERT_EQUAL(-1, node8.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node3, result);
  TEST_ASSERT_EQUAL_PTR(&node1, root);
  TEST_ASSERT_EQUAL_PTR(&node2, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node8, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node5, node8.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node6, node8.rightChild);
  TEST_ASSERT_EQUAL_PTR(NULL, node5.rightChild);
}

/**
 *             (175)                                                    (175)
 *        /              \                                        /               \
 *     (100)             (400)                                 (100)             (350)
 *    /     \          /       \                              /     \          /       \
 *  (50)   (150)    (250)      (500)         =>            (50)    (150)    (250)       (500)
 *  /  \    /      /    \      /   \                       /  \     /       /   \       /   \
 *(25)(65)(120) (200)   (300)(450) (550)                (25) (65) (120) (200)   (300) (450)(550)
 *  \             \     /   \        \                    \               \     /   \         \
 *  (40)         (220)(270)(350)     (600)                (40)           (220)(270) (330)     (600)
 *                          /
 *                       (330)
 *
 *
 */
void test_avlRemove_should_remove_400_in_the_right_subtree(){
	Node node330 = {.data = 330, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node600 = {.data = 600, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node350 = {.data = 350, .balance = -1, .leftChild = &node330, .rightChild = NULL};
	Node node270 = {.data = 270, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node220 = {.data = 220, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node40 = {.data = 40, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node550 = {.data = 550, .balance = 1, .leftChild = NULL, .rightChild = &node600};
	Node node450 = {.data = 450, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node300 = {.data = 300, .balance = 1, .leftChild = &node270, .rightChild = &node350};
	Node node200 = {.data = 200, .balance = 1, .leftChild = NULL, .rightChild = &node220};
	Node node120 = {.data = 120, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node65 = {.data = 65, .balance = 0, .leftChild = NULL, .rightChild = NULL};
	Node node25 = {.data = 25, .balance = 1, .leftChild = NULL, .rightChild = &node40};
	Node node500 = {.data = 500, .balance = 1, .leftChild = &node450, .rightChild = &node550};
	Node node250 = {.data = 250, .balance = 1, .leftChild = &node200, .rightChild = &node300};
	Node node150 = {.data = 150, .balance = -1, .leftChild = &node120, .rightChild = NULL};
	Node node50 = {.data = 50, .balance = -1, .leftChild = &node25, .rightChild = &node65};
	Node node400 = {.data = 400, .balance = -1, .leftChild = &node250, .rightChild = &node500};
	Node node100 = {.data = 100, .balance = -1, .leftChild = &node50, .rightChild = &node150};
  Node node175 = {.data = 175, .balance = 1, .leftChild = &node100, .rightChild = &node400};
  Node nodeRemove = {.data = 400, .balance = 0, .leftChild = NULL, .rightChild = NULL};
  Node *root = &node175;
  Node *result;
  
  result = avlRemove(&root, &nodeRemove);
  
  TEST_ASSERT_EQUAL(0, node175.balance);
  TEST_ASSERT_EQUAL(0, node250.balance);
  TEST_ASSERT_EQUAL(1, node200.balance);
  TEST_ASSERT_EQUAL(0, node300.balance);
  TEST_ASSERT_EQUAL(0, node220.balance);
  TEST_ASSERT_EQUAL(0, node270.balance);
  TEST_ASSERT_EQUAL(0, node350.balance);
  TEST_ASSERT_EQUAL(0, node330.balance);
  
  TEST_ASSERT_EQUAL_PTR(&node400, result);
  TEST_ASSERT_EQUAL_PTR(&node175, root);
  TEST_ASSERT_EQUAL_PTR(&node100, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&node350, root->rightChild);
  TEST_ASSERT_EQUAL_PTR(&node250, node350.leftChild);
  TEST_ASSERT_EQUAL_PTR(&node500, node350.rightChild);
  TEST_ASSERT_EQUAL_PTR(&node330, node300.rightChild);
}

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