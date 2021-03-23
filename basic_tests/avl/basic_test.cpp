#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include "../../includes/avl/avl.h"
#include "../../includes/avl/avl_functions.h"

int random(int low, int high){
  //call srand in main if you want better random numbers.
  return static_cast<int>(low + (rand() % static_cast<int>((high - low + 1))));
}
//------------------------------------------------------------------------------------------
//Files we are testing:

#include "../../includes/avl/avl.h"

//------------------------------------------------------------------------------------------

using namespace std;
bool basic_random_test(bool debug = true){
  cout << "\n\nROLLING: " << endl;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++){
      int n = random(1, 6);
      if (n<1){
        cout << "FAILED: random number out of bounds: (1): "<<n << endl;
        return false;
      }
      if (n>6){
        cout << "FAILED: random number out of bounds: (2)" <<n<< endl;
        return false;
      }
      cout << setw(3) << random(1, 6);
    }
    cout << endl;
  }
  cout << "\n\n---- end test random --------" << endl;
  return true;
}
bool basic_test_avl(bool debug = false){
  int a[50];
  int i = 0;
  while (i<40){
      a[i] = i;
      if (i%3==0){
          a[++i] = i;
      }
      i++;
  }

  AVL<int> avl(a,40);
  cout << "here is the tree: " << endl
       << avl << endl;
  cout << "\n\ninsert(): " << endl;
  for (int i = 0; i < 5; i++){
    int n = random(1, 50);
    avl.insert(n);
    cout << avl << endl;
    cout << "----------------------------" << endl;
}

  cout << "\n\nsearch: " << endl;
  for (int i = 0; i < 5; i++){
    int n = random(0, 19);
    if (!avl.contains(n)){
      cout << "FAILED: searched for ["<<n<<"]: failed to find." << endl;
      return false;
    }
  }
  AVL<int> avl2(avl); //copy ctor (you should also test assignment!)
  for (int i = 0; i < 5; i++){
    avl2.erase(a[i]);
    cout << "avl2 after erasing [" << a[i] <<"]"<< endl;
    cout << avl2 << endl;
    cout << "----------------------------" << endl;
  }

  cout << "\n\ntraversals(avl): " << endl;
  cout << "pre-order:  " << avl.pre_order() << endl;
  cout << "in-order:   " << avl.in_order() << endl;
  cout << "post-order: " << avl.post_order() << endl;

  cout << "\n\nAVL::operator+=( ) \n\navl += avl2 (because why not!): " << endl;
  avl += avl2;

  cout << "avl after add: " << avl << endl;
  cout << "\n\nclear avl2: " << endl;
  avl2.clear_all();
  if (!avl2.empty()){
    cout << "FAILED: Tree not empty after call to clear_all() " << endl;
    return false;
  }
  return true;
}


// TEST(TEST_TEMPLATE, TestTemplate) {
//   bool success = test_template();
//   EXPECT_EQ(success, true);
// }
TEST(TEST_RANDOM, TestRandom) {
  bool success = basic_random_test();
  EXPECT_EQ(success, true);
}
TEST(TEST_AVL, TestAVL) {
  bool success = basic_test_avl();
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*

build git:(master) ✗  😊 $> tree ../includes
../includes
├── avl
│   └── avl.h
└── avl_functions
    └── avl_functions.h

2 directories, 2 files
build git:(master) ✗  😊 $> ./bin/basic_test


----------running basic_test.cpp---------


[==========] Running 2 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from TEST_RANDOM
[ RUN      ] TEST_RANDOM.TestRandom


ROLLING: 
  2  3  3  3  2
  6  3  6  2  5
  2  6  4  1  2
  3  2  4  2  4
  3  1  6  2  2


---- end test random --------
[       OK ] TEST_RANDOM.TestRandom (0 ms)
[----------] 1 test from TEST_RANDOM (0 ms total)

[----------] 1 test from TEST_AVL
[ RUN      ] TEST_AVL.TestAVL
here is the tree: 
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



insert(): 
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

----------------------------
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

----------------------------
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

----------------------------
                [45]
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

----------------------------
                [45]
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

----------------------------


search: 
avl2 after erasing [0]
                [45]
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

----------------------------
avl2 after erasing [1]
                [45]
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

----------------------------
avl2 after erasing [2]
                [45]
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

----------------------------
avl2 after erasing [3]
                [45]
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

----------------------------
avl2 after erasing [4]
                [45]
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

----------------------------


traversals(avl): 
pre-order:  [10][5][2][1][0][4][3][8][7][6][9][15][13][12][11][14][18][17][16][19][45]
in-order:   [0][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16][17][18][19][45]
post-order: [0][1][3][4][2][6][7][9][8][5][11][12][14][13][16][17][45][19][18][15][10]


AVL::operator+=( ) 

avl += avl2 (because why not!): 
avl after add:                 [45]
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



clear avl2: 
[       OK ] TEST_AVL.TestAVL (3 ms)
[----------] 1 test from TEST_AVL (3 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test cases ran. (3 ms total)
[  PASSED  ] 2 tests.
build git:(master)  😊 $> 
*/