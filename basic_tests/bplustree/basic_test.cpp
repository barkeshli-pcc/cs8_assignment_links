#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/bplustree/btree_array_funcs.h"
#include "../../includes/bplustree/bplustree.h"
#include "../../includes/bplustree/map.h"
#include "../../includes/bplustree/multimap.h"


//------------------------------------------------------------------------------------------

using namespace std;

bool bplustree_test(){
  int a[] = {43, 20, 96, 100, 69};
  BPlusTree<int> bt(a, 5);
  cout << "Here is the tree: " << endl
      << bt << endl;

  cout << "in order:    " << bt.in_order() << endl;
  cout << "pre order:   " << bt.pre_order() << endl;
  cout << "post order:  " << bt.post_order() << endl;
  cout << "adding 10, 50, 200: " << endl;
  bt.insert(10);
  bt.insert(50);
  bt.insert(200);
  cout << "in order:    " << bt.in_order() << endl;
  cout << "pre order:   " << bt.pre_order() << endl;
  cout << "post order:  " << bt.post_order() << endl;

  cout << "Here is the tree: " << endl
       << bt << endl;
  cout << "bt.contains(20): " << boolalpha << bt.contains(20) << endl;
  cout << "bt.contains(0): " << boolalpha << bt.contains(0) << endl;
  cout << "bt.find(20): " << *(bt.find(20)) << endl;
  
  cout << "\nfind nonexisting key: " << endl;
  cout << "bt.find(0): ";
  bt.find(0).print_Iterator();
  cout << endl;

  cout << "\n\nexcess + grow: " << endl;

  bt.insert(12);
  cout << "adding 12: " << endl;
  cout << "Here is the tree: " << endl
       << bt << endl;
  cout << "in order:    " << bt.in_order() << endl;
  cout << "pre order:   " << bt.pre_order() << endl;
  cout << "post order:  " << bt.post_order() << endl;
  bt.insert(300);
  cout << "added 300: " << endl;
  cout << "Here is the tree: " << endl
       << bt << endl;
  cout << "in order:    " << bt.in_order() << endl;
  cout << "pre order:   " << bt.pre_order() << endl;
  cout << "post order:  " << bt.post_order() << endl;
  bt.insert(55);
  cout << "added 55: " << endl;
  cout << "Here is the tree: " << endl
       << bt << endl;
  cout << "in order:    " << bt.in_order() << endl;
  cout << "pre order:   " << bt.pre_order() << endl;
  cout << "post order:  " << bt.post_order() << endl;
  
  
  //Iterator test:
  cout << "\n---- iterator test: list of data: ------------\n\n";
  BPlusTree<int>::Iterator it = bt.begin();
  for (; it != bt.end(); it++){
      cout<<setw(5) << *it;

  }
  cout <<"\n---------------------------------------------\n\n";

  cout << "\n\nremove test: " << endl;

  int b[] = {43, 20, 96, 10, 50, 200, 12, 300, 55, 100, 69};
  for (int i = 0; i < 11; i++){
    cout << "\n removing: [" << b[i] << "]" << endl;
    bt.remove(b[i]);
    cout << bt << endl;
    cout << "in order:    " << bt.in_order() << endl;
    cout << "pre order:   " << bt.pre_order() << endl;
    cout << "post order:  " << bt.post_order() << endl;
    cout << "\nbt.empty()?" <<boolalpha<<bt.empty() << endl;
  }



  cout << "\nremove on empty:" << endl;
  bt.remove(666);
  return true;
}

bool map_test(){
  int keys[] = {43, 20, 96, 100, 69};
  string values[] = {"430", "200", "960", "1000", "690"};
  Map<int, string> map;
  for (int i = 0; i < 5; i++){
    map[keys[i]] = values[i];
  }
  for (int i = 0; i < 5; i++){
    cout << "map[" << keys[i] << "]: " << map[keys[i]] << endl;
  }
  for (int i = 0; i < 5; i++){
    map[keys[i]] = to_string(keys[i]*10+1);
  }
  cout << "\n----------\n";
  cout << map << endl;
  cout << "\n----------\n";
  for (int i = 0; i < 5; i++)
  {
    cout << "map[" << keys[i] << "]: " << map[keys[i]] << endl;
  }

  cout << "\n\n\n-------- iterator / range test ----------\n\n";
  Map<int, string>::Iterator it;
  for (it = map.begin(); it != map.end(); it++)
  {
    cout << *it << " | ";
  }
  
  cout << endl;
  cout << ". . .  lower_bound(): greater or equal to" << endl;
  it = map.lower_bound(10);
  cout << "lower_bound(10): " << *it << endl;
  //((it != map.end()) ? "NULL" : *it) << endl;
  it = map.lower_bound(20);
  cout << "lower_bound(20): " << *it << endl;
  it = map.lower_bound(42);
  cout << "lower_bound(42): " << *it << endl;
  it = map.lower_bound(150);
  if (it!=map.end())
    cout << "lower_bound(150): " << *it << endl;
  else
      cout << "lower_bound(150): " <<  "NULL"  << endl;
  
  
  cout << endl;
  cout << ". . .  upper_bound(): greater than" << endl;
  it = map.upper_bound(10);
  cout << "upper_bound(10): " << *it << endl;
  //((it != map.end()) ? "NULL" : *it) << endl;
  it = map.upper_bound(20);
  cout << "upper_bound(20): " << *it << endl;
  it = map.upper_bound(42);
  cout << "upper_bound(42): " << *it << endl;
  it = map.upper_bound(150);
  if (it!=map.end())
    cout << "upper_bound(150): " << *it << endl;
  else
      cout << "upper_bound(150): " <<  "NULL"  << endl;

  cout << "\n\n--- other functions --------\n\n";
  cout << "map.size():        " << map.size() << endl;
  cout << "map.empty():       " << map.empty() << endl;
  cout << "map.at(20):        " << map.at(20) << endl;
  cout << "map.find(43):      " << *map.find(43) << endl;
  cout << "map.contains(45):  " << boolalpha << map.contains(45) << endl;
  cout << "map.contains(100): " << boolalpha << map.contains(100) << endl;
  cout << "map.contains(150): " << boolalpha << map.contains(150) << endl;
  cout << "map.is_valud():    " << map.is_valid() << endl;
  return true;
}


bool multimap_test(){
  int keys[] = {43, 20, 96, 100, 69};
  string values[] = {"430", "200", "960", "1000", "690"};
  MMap<int, string> mmap;
  for (int i = 0; i < 5; i++){
    mmap[keys[i]] += values[i];
  }
  for (int i = 0; i < 5; i++){
    cout << "mmap[" << keys[i] << "]: " << mmap[keys[i]] << endl;
  }
  for (int i = 0; i < 5; i++){
    mmap[keys[i]] += to_string(keys[i]*10+1);
  }
  for (int i = 0; i < 5; i++){
    mmap[keys[i]] += to_string(keys[i]*10+3);
  }
  cout << "\n----------\n";
  cout << mmap << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << "mmap[" << keys[i] << "]: " << mmap[keys[i]] << endl;
  }

  cout << "\n\n\n-------- iterator / range test ----------\n\n";
  MMap<int, string>::Iterator it;
  for (it = mmap.begin(); it != mmap.end(); it++)
  {
    cout << *it << " | ";
  }
  
  cout << endl;
  cout << ". . .  lower_bound(): greater or equal to" << endl;
  it = mmap.lower_bound(10);
  cout << "lower_bound(10): " << *it << endl;
  //((it != mmap.end()) ? "NULL" : *it) << endl;
  it = mmap.lower_bound(20);
  cout << "lower_bound(20): " << *it << endl;
  it = mmap.lower_bound(42);
  cout << "lower_bound(42): " << *it << endl;
  it = mmap.lower_bound(150);
  if (it!=mmap.end())
    cout << "lower_bound(150): " << *it << endl;
  else
      cout << "lower_bound(150): " <<  "NULL"  << endl;
  
  
  cout << endl;
  cout << ". . .  upper_bound(): greater than" << endl;
  it = mmap.upper_bound(10);
  cout << "upper_bound(10): " << *it << endl;
  //((it != mmap.end()) ? "NULL" : *it) << endl;
  it = mmap.upper_bound(20);
  cout << "upper_bound(20): " << *it << endl;
  it = mmap.upper_bound(42);
  cout << "upper_bound(42): " << *it << endl;
  it = mmap.upper_bound(150);
  if (it!=mmap.end())
    cout << "upper_bound(150): " << *it << endl;
  else
      cout << "upper_bound(150): " <<  "NULL"  << endl;
  
  cout << "\n\n--- other functions --------\n\n";
  cout << "mmap.size():        " << mmap.size() << endl;
  cout << "mmap.empty():       " << mmap.empty() << endl;
  cout << "mmap.at(20):        " << mmap.at(20) << endl;
  cout << "mmap.find(43):      " << *mmap.find(43) << endl;
  cout << "mmap.contains(45):  " << boolalpha << mmap.contains(45) << endl;
  cout << "mmap.contains(100): " << boolalpha << mmap.contains(100) << endl;
  cout << "mmap.contains(150): " << boolalpha << mmap.contains(150) << endl;
  cout << "mmap.is_valud():    " << mmap.is_valid() << endl;
  
  
  return true;
}

TEST(TEST_BPLUS_TREE, BPlusTreeTest) {
  bool success = bplustree_test();
  EXPECT_EQ(success, true);
}

TEST(Map_Test, MapTest) {
  bool success = map_test();
  EXPECT_EQ(success, true);
}

TEST(Multimap_Test, ultiMapTest) {
  bool success = multimap_test();
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
├── bplustree
│   ├── bplustree.h
│   ├── btree_array_funcs.h
│   ├── map.h
│   ├── multimap.h
│   └── set_class.h
└── stl_utils
    └── vector_utilities.h

2 directories, 6 files
build git:(master) ✗  😊 $> ./bin/basic_test

----------running basic_test.cpp---------


[==========] Running 3 tests from 3 test cases.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BPLUS_TREE
[ RUN      ] TEST_BPLUS_TREE.BPlusTreeTest
Here is the tree: 
|     ⎴
|     100
|     96
|     ⎵
| ^
| ⎴
| 96
|     ^
|     ⎴
|     69
|     43
|     ⎵
| 43
| ⎵
|     ^
|     ⎴
|     20
|     ⎵

in order:    20|43|43|69|96|96|100|
pre order:   43|20|96|43|69|96|100|
post order:  20|43|69|43|96|100|96|
adding 10, 50, 200: 
in order:    10|20|43|43|50|50|69|96|96|100|100|200|
pre order:   50|43|10|20|43|96|50|69|100|96|100|200|
post order:  10|20|43|43|50|69|96|96|100|200|100|50|
Here is the tree: 
|         ⎴
|         200
|         100
|         ⎵
|     ⎴
|     100
|         ^
|         ⎴
|         96
|         ⎵
|     96
|     ⎵
|         ^
|         ⎴
|         69
|         50
|         ⎵
| ^
| ⎴
| 50
| ⎵
|         ^
|         ⎴
|         43
|         ⎵
|     ⎴
|     43
|     ⎵
|         ^
|         ⎴
|         20
|         10
|         ⎵

bt.contains(20): true
bt.contains(0): false
bt.find(20): 20

find nonexisting key: 
bt.find(0): iterator: NULL, key_ptr: 0



excess + grow: 
adding 12: 
Here is the tree: 
|         ⎴
|         200
|         100
|         ⎵
|     ⎴
|     100
|         ^
|         ⎴
|         96
|         ⎵
|     96
|     ⎵
|         ^
|         ⎴
|         69
|         50
|         ⎵
| ^
| ⎴
| 50
| ⎵
|         ^
|         ⎴
|         43
|         ⎵
|     ⎴
|     43
|         ^
|         ⎴
|         20
|         12
|         ⎵
|     12
|     ⎵
|         ^
|         ⎴
|         10
|         ⎵

in order:    10|12|12|20|43|43|50|50|69|96|96|100|100|200|
pre order:   50|12|10|43|12|20|43|96|50|69|100|96|100|200|
post order:  10|12|20|12|43|43|50|69|96|96|100|200|100|50|
added 300: 
Here is the tree: 
|         ⎴
|         300
|         200
|         ⎵
|     ⎴
|     200
|     ⎵
|         ^
|         ⎴
|         100
|         ⎵
| ^
| ⎴
| 100
|         ^
|         ⎴
|         96
|         ⎵
|     ⎴
|     96
|     ⎵
|         ^
|         ⎴
|         69
|         50
|         ⎵
| 50
| ⎵
|         ^
|         ⎴
|         43
|         ⎵
|     ⎴
|     43
|         ^
|         ⎴
|         20
|         12
|         ⎵
|     12
|     ⎵
|         ^
|         ⎴
|         10
|         ⎵

in order:    10|12|12|20|43|43|50|50|69|96|96|100|100|200|200|300|
pre order:   50|12|10|43|12|20|43|100|96|50|69|96|200|100|200|300|
post order:  10|12|20|12|43|43|50|69|96|96|50|100|200|300|200|100|
added 55: 
Here is the tree: 
|         ⎴
|         300
|         200
|         ⎵
|     ⎴
|     200
|     ⎵
|         ^
|         ⎴
|         100
|         ⎵
| ^
| ⎴
| 100
|         ^
|         ⎴
|         96
|         ⎵
|     ⎴
|     96
|         ^
|         ⎴
|         69
|         55
|         ⎵
|     55
|     ⎵
|         ^
|         ⎴
|         50
|         ⎵
| 50
| ⎵
|         ^
|         ⎴
|         43
|         ⎵
|     ⎴
|     43
|         ^
|         ⎴
|         20
|         12
|         ⎵
|     12
|     ⎵
|         ^
|         ⎴
|         10
|         ⎵

in order:    10|12|12|20|43|43|50|50|55|55|69|96|96|100|100|200|200|300|
pre order:   50|12|10|43|12|20|43|100|55|50|96|55|69|96|200|100|200|300|
post order:  10|12|20|12|43|43|50|55|69|55|96|96|50|100|200|300|200|100|

---- iterator test: list of data: ------------

   10   12   20   43   50   55   69   96  100  200  300
---------------------------------------------



remove test: 

 removing: [43]
|         ⎴
|         300
|         200
|         ⎵
|     ⎴
|     200
|     ⎵
|         ^
|         ⎴
|         100
|         ⎵
| ^
| ⎴
| 100
|         ^
|         ⎴
|         96
|         ⎵
|     ⎴
|     96
|         ^
|         ⎴
|         69
|         55
|         ⎵
|     55
|     ⎵
|         ^
|         ⎴
|         50
|         ⎵
| 50
| ⎵
|         ^
|         ⎴
|         20
|         ⎵
|     ⎴
|     20
|         ^
|         ⎴
|         12
|         ⎵
|     12
|     ⎵
|         ^
|         ⎴
|         10
|         ⎵

in order:    10|12|12|20|20|50|50|55|55|69|96|96|100|100|200|200|300|
pre order:   50|12|10|20|12|20|100|55|50|96|55|69|96|200|100|200|300|
post order:  10|12|12|20|20|50|55|69|55|96|96|50|100|200|300|200|100|

bt.empty()?false

 removing: [20]
|         ⎴
|         300
|         200
|         ⎵
|     ⎴
|     200
|     ⎵
|         ^
|         ⎴
|         100
|         ⎵
| ^
| ⎴
| 100
|         ^
|         ⎴
|         96
|         ⎵
|     ⎴
|     96
|         ^
|         ⎴
|         69
|         55
|         ⎵
|     55
|     ⎵
|         ^
|         ⎴
|         50
|         ⎵
| 50
| ⎵
|         ^
|         ⎴
|         12
|         ⎵
|     ⎴
|     12
|     ⎵
|         ^
|         ⎴
|         10
|         ⎵

in order:    10|12|12|50|50|55|55|69|96|96|100|100|200|200|300|
pre order:   50|12|10|12|100|55|50|96|55|69|96|200|100|200|300|
post order:  10|12|12|50|55|69|55|96|96|50|100|200|300|200|100|

bt.empty()?false

 removing: [96]
|         ⎴
|         300
|         200
|         ⎵
|     ⎴
|     200
|     ⎵
|         ^
|         ⎴
|         100
|         ⎵
| ^
| ⎴
| 100
|         ^
|         ⎴
|         69
|         ⎵
|     ⎴
|     69
|         ^
|         ⎴
|         55
|         ⎵
|     55
|     ⎵
|         ^
|         ⎴
|         50
|         ⎵
| 50
| ⎵
|         ^
|         ⎴
|         12
|         ⎵
|     ⎴
|     12
|     ⎵
|         ^
|         ⎴
|         10
|         ⎵

in order:    10|12|12|50|50|55|55|69|69|100|100|200|200|300|
pre order:   50|12|10|12|100|55|50|69|55|69|200|100|200|300|
post order:  10|12|12|50|55|55|69|69|50|100|200|300|200|100|

bt.empty()?false

 removing: [10]
|         ⎴
|         300
|         200
|         ⎵
|     ⎴
|     200
|     ⎵
|         ^
|         ⎴
|         100
|         ⎵
| ^
| ⎴
| 100
|         ^
|         ⎴
|         69
|         ⎵
|     ⎴
|     69
|     ⎵
|         ^
|         ⎴
|         55
|         ⎵
| 55
| ⎵
|         ^
|         ⎴
|         50
|         ⎵
|     ⎴
|     50
|     ⎵
|         ^
|         ⎴
|         12
|         ⎵

in order:    12|50|50|55|55|69|69|100|100|200|200|300|
pre order:   55|50|12|50|100|69|55|69|200|100|200|300|
post order:  12|50|50|55|69|69|55|100|200|300|200|100|

bt.empty()?false

 removing: [50]
|         ⎴
|         300
|         200
|         ⎵
|     ⎴
|     200
|     ⎵
|         ^
|         ⎴
|         100
|         ⎵
| ^
| ⎴
| 100
| ⎵
|         ^
|         ⎴
|         69
|         ⎵
|     ⎴
|     69
|         ^
|         ⎴
|         55
|         ⎵
|     55
|     ⎵
|         ^
|         ⎴
|         12
|         ⎵

in order:    12|55|55|69|69|100|100|200|200|300|
pre order:   100|55|12|69|55|69|200|100|200|300|
post order:  12|55|55|69|69|100|200|300|200|100|

bt.empty()?false

 removing: [200]
|         ⎴
|         300
|         ⎵
|     ⎴
|     300
|     ⎵
|         ^
|         ⎴
|         100
|         ⎵
| ^
| ⎴
| 100
| ⎵
|         ^
|         ⎴
|         69
|         ⎵
|     ⎴
|     69
|         ^
|         ⎴
|         55
|         ⎵
|     55
|     ⎵
|         ^
|         ⎴
|         12
|         ⎵

in order:    12|55|55|69|69|100|100|300|300|
pre order:   100|55|12|69|55|69|300|100|300|
post order:  12|55|55|69|69|100|300|300|100|

bt.empty()?false

 removing: [12]
|         ⎴
|         300
|         ⎵
|     ⎴
|     300
|     ⎵
|         ^
|         ⎴
|         100
|         ⎵
| ^
| ⎴
| 100
| ⎵
|         ^
|         ⎴
|         69
|         ⎵
|     ⎴
|     69
|     ⎵
|         ^
|         ⎴
|         55
|         ⎵

in order:    55|69|69|100|100|300|300|
pre order:   100|69|55|69|300|100|300|
post order:  55|69|69|100|300|300|100|

bt.empty()?false

 removing: [300]
|     ⎴
|     100
|     ⎵
| ^
| ⎴
| 100
|     ^
|     ⎴
|     69
|     ⎵
| 69
| ⎵
|     ^
|     ⎴
|     55
|     ⎵

in order:    55|69|69|100|100|
pre order:   69|55|100|69|100|
post order:  55|69|69|100|100|

bt.empty()?false

 removing: [55]
|     ⎴
|     100
|     ⎵
| ^
| ⎴
| 100
| ⎵
|     ^
|     ⎴
|     69
|     ⎵

in order:    69|100|100|
pre order:   100|69|100|
post order:  69|100|100|

bt.empty()?false

 removing: [100]
| ^
| ⎴
| 69
| ⎵

in order:    69|
pre order:   69|
post order:  69|

bt.empty()?false

 removing: [69]
| ^
| ⎴
| ⎵

in order:    
pre order:   
post order:  

bt.empty()?true

remove on empty:
[       OK ] TEST_BPLUS_TREE.BPlusTreeTest (10 ms)
[----------] 1 test from TEST_BPLUS_TREE (10 ms total)

[----------] 1 test from Map_Test
[ RUN      ] Map_Test.MapTest
map[43]: 430
map[20]: 200
map[96]: 960
map[100]: 1000
map[69]: 690

----------
|     ⎴
|     100:1001
|     96:961
|     ⎵
| ⎴
| 96:960
|     ^
|     ⎴
|     69:691
|     43:431
|     ⎵
| 43:430
| ⎵
|     ^
|     ⎴
|     20:201
|     ⎵



----------
map[43]: 431
map[20]: 201
map[96]: 961
map[100]: 1001
map[69]: 691



-------- iterator / range test ----------

20:201 | 43:431 | 69:691 | 96:961 | 100:1001 | 
. . .  lower_bound(): greater or equal to
lower_bound(10): 20:201
lower_bound(20): 20:201
lower_bound(42): 43:431
lower_bound(150): NULL

. . .  upper_bound(): greater than
upper_bound(10): 20:201
upper_bound(20): 43:431
upper_bound(42): 43:431
upper_bound(150): NULL


--- other functions --------

map.size():        7
map.empty():       false
map.at(20):        201
map.find(43):      43:431
map.contains(45):  false
map.contains(100): true
map.contains(150): false
map.is_valud():    true
[       OK ] Map_Test.MapTest (2 ms)
[----------] 1 test from Map_Test (2 ms total)

[----------] 1 test from Multimap_Test
[ RUN      ] Multimap_Test.ultiMapTest
mmap[43]: 430 
mmap[20]: 200 
mmap[96]: 960 
mmap[100]: 1000 
mmap[69]: 690 

----------
|     ⎴
|     100: [1000 1001 1003 ]
|     96: [960 961 963 ]
|     ⎵
| ⎴
| 96: [960 ]
|     ^
|     ⎴
|     69: [690 691 693 ]
|     43: [430 431 433 ]
|     ⎵
| 43: [430 ]
| ⎵
|     ^
|     ⎴
|     20: [200 201 203 ]
|     ⎵


mmap[43]: 430 431 433 
mmap[20]: 200 201 203 
mmap[96]: 960 961 963 
mmap[100]: 1000 1001 1003 
mmap[69]: 690 691 693 



-------- iterator / range test ----------

20: [200 201 203 ] | 43: [430 431 433 ] | 69: [690 691 693 ] | 96: [960 961 963 ] | 100: [1000 1001 1003 ] | 
. . .  lower_bound(): greater or equal to
lower_bound(10): 20: [200 201 203 ]
lower_bound(20): 20: [200 201 203 ]
lower_bound(42): 43: [430 431 433 ]
lower_bound(150): NULL

. . .  upper_bound(): greater than
upper_bound(10): 20: [200 201 203 ]
upper_bound(20): 43: [430 431 433 ]
upper_bound(42): 43: [430 431 433 ]
upper_bound(150): NULL


--- other functions --------

mmap.size():        7
mmap.empty():       false
mmap.at(20):        200 201 203 
mmap.find(43):      43: [430 431 433 ]
mmap.contains(45):  false
mmap.contains(100): true
mmap.contains(150): false
mmap.is_valud():    true
[       OK ] Multimap_Test.ultiMapTest (3 ms)
[----------] 1 test from Multimap_Test (3 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 3 test cases ran. (15 ms total)
[  PASSED  ] 3 tests.
build git:(master)  😊 $> 
*/