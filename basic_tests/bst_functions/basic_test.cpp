#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
//Files we are testing:

#include "../../includes/bst_functions/bst_functions.h"

//------------------------------------------------------------------------------------------

using namespace std;

bool test_bst_functions_basic(bool debug = false){
  cout << "\n\n---------- bst basic -----------" << endl;
  tree_node<int> *root = nullptr;
  int size = 11;
  int arr[20] = {5, 3, 4, 1, 7, 9, 6, 5, 2, 8,0};
  //int arr[20] = {0,1,2,3,4,5,6,7,8,9,8};
  
  for (int i = 0; i < size; i++)
  {
    tree_insert(root, arr[i]);
  }
  
  cout << "Here is your tree: " << endl;
  tree_print(root);
  
  cout << "\n\nHere is the debug version: " << endl;
  cout << "   (height and balance factor of each node)" << endl;

  tree_print_debug(root);

  bool found = false;
  int key;
 
  key = 5;
  found = tree_search(root, key);
  if (found){
    cout << key << " was found in this tree" << endl;
  }
  else{
    cout << key << " was not found in this tree" << endl;
  }

  key = 9;
  found = tree_search(root, key);
  if (found){
    cout << key << " was found in this tree" << endl;
  }
  else{
    cout << key << " was not found in this tree" << endl;
  }

  key = 0;
  found = tree_search(root, key);
  if (found){
    cout << key << " was found in this tree" << endl;
  }
  else{
    cout << key << " was not found in this tree" << endl;
  }

  key = 15;
  found = tree_search(root, key);
  if (found){
    cout << key << " was found in this tree" << endl;
  }
  else{
    cout << key << " was not found in this tree" << endl;
  }

  cout << "\n\n- - - - - - end bst basic - - - - - - - - -" << endl;
  return true;
}
bool test_bst_functions_more(bool debug = false){
  cout << "\n\n---------- bst more -----------" << endl;
  tree_node<int> *root=nullptr;
  tree_node<int> *root_copy=nullptr;
  int a[40];
  int size = 20;
  for (int i = 0; i < size; i++)
  {
    a[i] = i;
  }
  root = tree_from_sorted_list(a, size);

  cout << "\nMaking a copy of the tree: " << endl;
  root_copy = tree_copy(root);
  cout << "Here is your copy: " << endl;
  tree_print(root_copy);

  cout << "\nHere is your tree from sorted  list: " << endl;
  tree_print(root);

  for (int i = 0; i < size; i++)
  {
    cout << "\nErasing " << i << endl;
    tree_erase(root, i);
    tree_print(root);
  }
  cout << "\nroot == nullptr?: " << boolalpha << (root==nullptr) << endl;

  cout << "\n\n . . . . . \n\nHere is the copy again: " << endl;
  tree_print(root_copy);

  cout << "\n\nClearing the copy tree: " << endl;
  tree_clear(root_copy);
  cout << "root_copy == nullptr?: " << boolalpha << (root_copy==nullptr) << endl;
  cout << "- - - - - - end bst more - - - - - - - - -" << endl;
  return true;
}
bool test_bst_functions_add(bool debug = false){
  cout << "\n\n---------- bst add -----------" << endl;
  tree_node<int> *root_1 = nullptr;
  tree_node<int> *root_2 = nullptr;

  int a[40];
  int size = 10;
  for (int i = 0; i < size; i++)
  {
    a[i] = i*2;
  }

  root_1 = tree_from_sorted_list(a, size);
  cout << "Here is the first tree: " << endl;
  tree_print(root_1);

  for (int i = 0; i < size; i++)
  {
    a[i] = i*2+1;
  }
  root_2 = tree_from_sorted_list(a, size);

  cout << "\n\nHere is the first tree: " << endl;
  tree_print(root_1);

  cout << "\nAdding the two trees: " << endl;
  tree_add(root_1, root_2);
  tree_print(root_1);
  cout << endl
       << endl
       << "The other tree is untouched: " << endl;
  tree_print(root_2);
  cout << "- - - - - - end bst add - - - - - - - - -" << endl;
  return true;
}
bool test_bst_functions_traversals(bool debug = false){
  cout << "\n\n---------- bst traversal test -----------" << endl;
  tree_node<int> *root = nullptr;
  int size = 11;
  int arr[20] = {5, 3, 4, 1, 7, 9, 6, 5, 2, 8, 0};

  for (int i = 0; i < size; i++)
  {
    tree_insert(root, arr[i]);
  }
  cout << "Here is the first tree: " << endl;
  tree_print(root);

  cout << "\n\nTraversals: " << endl;
  cout << "\n  pre-order    : ";
  pre_order(root);
  cout << "\n  in-order     : ";
  in_order(root);
  cout << "\n  post-order   : ";
  post_order(root);
  cout << "\n\n----- tranversal strings: -----" << endl;
  string pre_order = pre_order_string(root);
  string in_order = in_order_string(root);
  string post_order = post_order_string(root);

  string pre_order_expected  = "[5][3][1][0][2][4][7][6][5][9][8]";
  string in_order_expected   = "[0][1][2][3][4][5][5][6][7][8][9]";
  string post_order_expected = "[0][2][1][4][3][5][6][8][9][7][5]";

  cout << "pre_order    : " <<pre_order<< endl;
  cout << "in_order     : " << in_order<<endl;
  cout << "post_order   : " << post_order<<endl;
  if (pre_order != pre_order_expected){
    cout << "FAILED: Expected pre_oder string to be: {"
        << pre_order_expected <<"}"<< endl;
    cout<< "         but found it to be: {" << pre_order <<"}"<< endl;
    return false;
  }
  if (in_order != in_order_expected){
    cout << "FAILED: Expected in_oder string to be: {"
         <<in_order_expected <<"}"<< endl;
    cout<< "         but found it to be: {" << in_order <<"}"<< endl;
    return false;
  }
  if (post_order != post_order_expected){
    cout << "FAILED: Expected post_oder string to be: {"
         <<post_order_expected <<"}"<< endl;
    cout<< "         but found it to be: {" << post_order << "}"<<endl;
    return false;
  }

cout << "\n\n- - - - - - end traversal test - - - - - - - - -" << endl;
return true;

}


TEST(TEST_BST_FUNCS, TestBSTFuncsBasic) {
  bool success = test_bst_functions_basic(false);
  EXPECT_EQ(success, true);
}

TEST(TEST_BST_FUNCS, TestBSTFuncsMore) {
  bool success = test_bst_functions_more(false);
  EXPECT_EQ(success, true);
}

TEST(TEST_BST_FUNCS, TestBSTFuncsAdd) {
  bool success = test_bst_functions_add(false);
  EXPECT_EQ(success, true);
}
TEST(TEST_BST_FUNCS, TestBSTFuncsTraversal) {
  bool success = test_bst_functions_traversals(false);
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*
    build git:(master)  😊 $> tree ../includes
    ../includes
    └── bst_functions
        └── bst_functions.h

    1 directory, 1 file
    build git:(master)  😊 $> ./bin/basic_test


    ----------running basic_test.cpp---------


    [==========] Running 4 tests from 1 test case.
    [----------] Global test environment set-up.
    [----------] 4 tests from TEST_BST_FUNCS
    [ RUN      ] TEST_BST_FUNCS.TestBSTFuncsBasic


    ---------- bst basic -----------
    Here is your tree: 
            [9]
                [8]
        [7]
            [6]
                [5]
    [5]
            [4]
        [3]
                [2]
            [1]
                [0]


    Here is the debug version: 
    (height and balance factor of each node)
            [9:1 (1)]
                [8:0 (0)]
        [7:2 (0)]
            [6:1 (1)]
                [5:0 (0)]
    [5:3 (0)]
            [4:0 (0)]
        [3:2 (1)]
                [2:0 (0)]
            [1:1 (0)]
                [0:0 (0)]
    5 was found in this tree
    9 was found in this tree
    0 was found in this tree
    15 was not found in this tree


    - - - - - - end bst basic - - - - - - - - -
    [       OK ] TEST_BST_FUNCS.TestBSTFuncsBasic (1 ms)
    [ RUN      ] TEST_BST_FUNCS.TestBSTFuncsMore


    ---------- bst more -----------

    Making a copy of the tree: 
    Here is your copy: 
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
                [9]
            [8]
                [7]
                    [6]
        [5]
                [4]
                    [3]
            [2]
                [1]
                    [0]

    Here is your tree from sorted  list: 
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
                [9]
            [8]
                [7]
                    [6]
        [5]
                [4]
                    [3]
            [2]
                [1]
                    [0]

    Erasing 0
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
                [9]
            [8]
                [7]
                    [6]
        [5]
                [4]
                    [3]
            [2]
                [1]

    Erasing 1
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
                [9]
            [8]
                [7]
                    [6]
        [5]
                [4]
                    [3]
            [2]

    Erasing 2
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
                [9]
            [8]
                [7]
                    [6]
        [5]
            [4]
                [3]

    Erasing 3
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
                [9]
            [8]
                [7]
                    [6]
        [5]
            [4]

    Erasing 4
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
                [9]
            [8]
                [7]
                    [6]
        [5]

    Erasing 5
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
            [9]
        [8]
            [7]
                [6]

    Erasing 6
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
            [9]
        [8]
            [7]

    Erasing 7
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
            [9]
        [8]

    Erasing 8
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
        [9]

    Erasing 9
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]

    Erasing 10
            [19]
        [18]
            [17]
                [16]
    [15]
            [14]
        [13]
            [12]
                [11]

    Erasing 11
            [19]
        [18]
            [17]
                [16]
    [15]
            [14]
        [13]
            [12]

    Erasing 12
            [19]
        [18]
            [17]
                [16]
    [15]
            [14]
        [13]

    Erasing 13
            [19]
        [18]
            [17]
                [16]
    [15]
        [14]

    Erasing 14
            [19]
        [18]
            [17]
                [16]
    [15]

    Erasing 15
        [19]
    [18]
        [17]
            [16]

    Erasing 16
        [19]
    [18]
        [17]

    Erasing 17
        [19]
    [18]

    Erasing 18
    [19]

    Erasing 19

    root == nullptr?: true


    . . . . . 

    Here is the copy again: 
                [19]
            [18]
                [17]
                    [16]
        [15]
                [14]
            [13]
                [12]
                    [11]
    [10]
                [9]
            [8]
                [7]
                    [6]
        [5]
                [4]
                    [3]
            [2]
                [1]
                    [0]


    Clearing the copy tree: 
    root_copy == nullptr?: true
    - - - - - - end bst more - - - - - - - - -
    [       OK ] TEST_BST_FUNCS.TestBSTFuncsMore (5 ms)
    [ RUN      ] TEST_BST_FUNCS.TestBSTFuncsAdd


    ---------- bst add -----------
    Here is the first tree: 
            [18]
        [16]
            [14]
                [12]
    [10]
            [8]
                [6]
        [4]
            [2]
                [0]


    Here is the first tree: 
            [18]
        [16]
            [14]
                [12]
    [10]
            [8]
                [6]
        [4]
            [2]
                [0]

    Adding the two trees: 
                [19]
            [18]
                [17]
        [16]
                [15]
            [14]
                    [13]
                [12]
                    [11]
    [10]
                [9]
            [8]
                    [7]
                [6]
                    [5]
        [4]
                [3]
            [2]
                    [1]
                [0]


    The other tree is untouched: 
            [19]
        [17]
            [15]
                [13]
    [11]
            [9]
                [7]
        [5]
            [3]
                [1]
    - - - - - - end bst add - - - - - - - - -
    [       OK ] TEST_BST_FUNCS.TestBSTFuncsAdd (1 ms)
    [ RUN      ] TEST_BST_FUNCS.TestBSTFuncsTraversal


    ---------- bst traversal test -----------
    Here is the first tree: 
            [9]
                [8]
        [7]
            [6]
                [5]
    [5]
            [4]
        [3]
                [2]
            [1]
                [0]


    Traversals: 

    pre-order    :    5   3   1   0   2   4   7   6   5   9   8
    in-order     :    0   1   2   3   4   5   5   6   7   8   9
    post-order   :    0   2   1   4   3   5   6   8   9   7   5

    ----- tranversal strings: -----
    pre_order    : [5][3][1][0][2][4][7][6][5][9][8]
    in_order     : [0][1][2][3][4][5][5][6][7][8][9]
    post_order   : [0][2][1][4][3][5][6][8][9][7][5]


    - - - - - - end traversal test - - - - - - - - -
    [       OK ] TEST_BST_FUNCS.TestBSTFuncsTraversal (1 ms)
    [----------] 4 tests from TEST_BST_FUNCS (8 ms total)

    [----------] Global test environment tear-down
    [==========] 4 tests from 1 test case ran. (8 ms total)
    [  PASSED  ] 4 tests.
    build git:(master)  😊 $> 
*/