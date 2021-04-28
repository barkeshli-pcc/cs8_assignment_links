#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/btree_array_functions/btree_array_functions.h"
#include "../../includes/btree/btree.h"


//------------------------------------------------------------------------------------------

using namespace std;

bool basic_test(){
  int a[] = {43, 20, 96, 100, 69};
  BTree<int> bt(a, 5);
  cout << "Here is the tree: " << endl
      << bt << endl;

  cout <<"in order: "<< bt.in_order() << endl;
  cout << "adding 10, 50, 200: " << endl;
  bt.insert(10);
  bt.insert(50);
  bt.insert(200);
  cout << "in order " << bt.in_order() << endl;
  cout << "Here is the tree: " << endl
       << bt << endl;
  cout << "bt.contains(20): " << boolalpha << bt.contains(20) << endl;
  cout << "bt.contains(0): " << boolalpha << bt.contains(0) << endl;
  cout << "bt.find(20): " << *(bt.find(20)) << endl;
  cout << "bt.find(0): " << bt.find(0) << endl;
  
  
  cout << "\n\nexcess + grow: " << endl;

  bt.insert(12);
  cout << "adding 12: " << endl;
  cout << "Here is the tree: " << endl
       << bt << endl;
  cout << "in order " << bt.in_order() << endl;
  bt.insert(300);
  cout << "added 300: " << endl;
  cout << "Here is the tree: " << endl
       << bt << endl;
  cout << "in order " << bt.in_order() << endl;
  bt.insert(55);
  cout << "added 55: " << endl;
  cout << "Here is the tree: " << endl
       << bt << endl;
  cout << "in order " << bt.in_order() << endl;


  cout << "\n\nremove test: " << endl;

  int b[] = {43, 20, 96, 10, 50, 200, 12, 300, 55, 100, 69};
  for (int i = 0; i < 11; i++){
    cout << "\n removing: [" << b[i] << "]" << endl;
    bt.remove(b[i]);
    cout << bt << endl;
    cout <<"in order: "<< bt.in_order() << endl;
    cout << "\nbt.empty()?" <<boolalpha<<bt.empty() << endl;
  }


  cout << "\nremove on empty:" << endl;
  bt.remove(666);
  return true;
}


TEST(TEST_TEMPLATE, TestTemplate) {
  bool success = basic_test();
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
├── btree
│   └── btree.h
└── btree_array_functions
    └── btree_array_functions.h

2 directories, 5 files
build git:(master) ✗  😊 $> ./bin/basic_test


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_TEMPLATE
[ RUN      ] TEST_TEMPLATE.TestTemplate
Here is the tree: 
    ⎴
    100
    ⎵
⎴
96
    ⎴
    69
    ⎵
43
⎵
    ⎴
    20
    ⎵

in order: 20|43|69|96|100|
adding 10, 50, 200: 
in order 10|20|43|50|69|96|100|200|
Here is the tree: 
    ⎴
    200
    100
    ⎵
⎴
96
    ⎴
    69
    50
    ⎵
43
⎵
    ⎴
    20
    10
    ⎵

bt.contains(20): true
bt.contains(0): false
bt.find(20): 20
bt.find(0): 0x0


excess + grow: 
adding 12: 
Here is the tree: 
        ⎴
        200
        100
        ⎵
    ⎴
    96
    ⎵
        ⎴
        69
        50
        ⎵
⎴
43
⎵
        ⎴
        20
        ⎵
    ⎴
    12
    ⎵
        ⎴
        10
        ⎵

in order 10|12|20|43|50|69|96|100|200|
added 300: 
Here is the tree: 
        ⎴
        300
        ⎵
    ⎴
    200
        ⎴
        100
        ⎵
    96
    ⎵
        ⎴
        69
        50
        ⎵
⎴
43
⎵
        ⎴
        20
        ⎵
    ⎴
    12
    ⎵
        ⎴
        10
        ⎵

in order 10|12|20|43|50|69|96|100|200|300|
added 55: 
Here is the tree: 
        ⎴
        300
        ⎵
    ⎴
    200
    ⎵
        ⎴
        100
        ⎵
⎴
96
        ⎴
        69
        ⎵
    ⎴
    55
    ⎵
        ⎴
        50
        ⎵
43
⎵
        ⎴
        20
        ⎵
    ⎴
    12
    ⎵
        ⎴
        10
        ⎵

in order 10|12|20|43|50|55|69|96|100|200|300|


remove test: 

 removing: [43]
        ⎴
        300
        ⎵
    ⎴
    200
    ⎵
        ⎴
        100
        ⎵
⎴
96
⎵
        ⎴
        69
        ⎵
    ⎴
    55
        ⎴
        50
        ⎵
    20
    ⎵
        ⎴
        12
        10
        ⎵

in order: 10|12|20|50|55|69|96|100|200|300|

bt.empty()?false

 removing: [20]
        ⎴
        300
        ⎵
    ⎴
    200
    ⎵
        ⎴
        100
        ⎵
⎴
96
⎵
        ⎴
        69
        ⎵
    ⎴
    55
        ⎴
        50
        ⎵
    12
    ⎵
        ⎴
        10
        ⎵

in order: 10|12|50|55|69|96|100|200|300|

bt.empty()?false

 removing: [96]
        ⎴
        300
        ⎵
    ⎴
    200
    ⎵
        ⎴
        100
        ⎵
⎴
69
⎵
        ⎴
        55
        50
        ⎵
    ⎴
    12
    ⎵
        ⎴
        10
        ⎵

in order: 10|12|50|55|69|100|200|300|

bt.empty()?false

 removing: [10]
        ⎴
        300
        ⎵
    ⎴
    200
    ⎵
        ⎴
        100
        ⎵
⎴
69
⎵
        ⎴
        55
        ⎵
    ⎴
    50
    ⎵
        ⎴
        12
        ⎵

in order: 12|50|55|69|100|200|300|

bt.empty()?false

 removing: [50]
    ⎴
    300
    ⎵
⎴
200
    ⎴
    100
    ⎵
69
⎵
    ⎴
    55
    12
    ⎵
    ⎴
    300
    ⎵
⎴
200
    ⎴
    100
    ⎵
69
⎵
    ⎴
    55
    12
    ⎵

in order: 12|55|69|100|200|300|

bt.empty()?false

 removing: [200]
    ⎴
    300
    ⎵
⎴
100
    ⎴
    69
    ⎵
55
⎵
    ⎴
    12
    ⎵

in order: 12|55|69|100|300|

bt.empty()?false

 removing: [12]
    ⎴
    300
    ⎵
⎴
100
⎵
    ⎴
    69
    55
    ⎵

in order: 55|69|100|300|

bt.empty()?false

 removing: [300]
    ⎴
    100
    ⎵
⎴
69
⎵
    ⎴
    55
    ⎵

in order: 55|69|100|

bt.empty()?false

 removing: [55]
⎴
100
69
⎵
⎴
100
69
⎵

in order: 69|100|

bt.empty()?false

 removing: [100]
⎴
69
⎵

in order: 69|

bt.empty()?false

 removing: [69]
⎴

in order: 

bt.empty()?true

remove on empty:
[       OK ] TEST_TEMPLATE.TestTemplate (1 ms)
[----------] 1 test from TEST_TEMPLATE (1 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 

*/