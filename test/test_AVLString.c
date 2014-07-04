#include "unity.h"
#include "AVL.h"
#include "AVLString.h"
#include "AVLInt.h"
#include "Rotation.h"
#include "mock_Rotation_r.h"

void setUp(void){}
void tearDown(void){}

/**
 *   "Ali"                  "Bozo"
 *      \                   /    \
 *      "Dave"   =>     "Ali"   "Dave"
 *      /
 *  "Bozo"
 */
void test_avlAddString_given_Ali_Dave_Bozo_should_double_left_rotate(void){
  NodeString nodeAli = {.string = "Ali", .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeString nodeDave = {.string = "Dave", .balance = 0, .leftChild = NULL, .rightChild = NULL};
  NodeString nodeBozo = {.string = "Bozo", .balance = 0, .leftChild = NULL, .rightChild = NULL};
	NodeString *root = NULL;
  
  root = (NodeString *)avlAddString(root, &nodeAli);
  root = (NodeString *)avlAddString(root, &nodeDave);
  root = (NodeString *)avlAddString(root, &nodeBozo);
  
  TEST_ASSERT_EQUAL_PTR(&nodeBozo, root);
  TEST_ASSERT_EQUAL_PTR(&nodeAli, root->leftChild);
  TEST_ASSERT_EQUAL_PTR(&nodeDave, root->rightChild);
}
