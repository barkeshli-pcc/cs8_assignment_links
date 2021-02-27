#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/deque/deque.h"


//------------------------------------------------------------------------------------------

using namespace std;

bool test_deque_push_back_pop_front(bool debug = false){
  Deque<int> q;
  for (int i = 0; i < 10; i++){
    q.push_back(i * 10);
    cout <<"Deque: "<< q << endl;
  }
  cout << endl<< endl;

  for(Deque<int>::Iterator it = q.begin(); it != q.end(); it++){
    cout << "it->>" << *it << endl;
  }
  cout << endl<< endl;
  for (; !q.empty();){
    cout << "popping Deque: [" << setw(4) << q.pop_front() << "]: " << q << endl;
  }
  cout << endl
       << endl;
  Deque<int>::Iterator it = q.begin();
  cout << "Iterator is_null(): " << boolalpha << it.is_null() << endl;
  
  cout << "\n----------------------- \n\n";
  
  
  return true;
}

bool test_deque_push_front_pop_back(bool debug = false){
  Deque<int> q;
  for (int i = 0; i < 10; i++){
    q.push_front(i * 10);
    cout <<"Deque: "<< q << endl;
  }
  cout << endl<< endl;

  for(Deque<int>::Iterator it = q.begin(); it != q.end(); it++){
    cout << "it->>" << *it << endl;
  }
  cout << endl<< endl;
  for (; !q.empty();){
    cout << "popping Deque: [" << setw(4) << q.pop_back() << "]: " << q << endl;
  }
  cout << endl
       << endl;
  Deque<int>::Iterator it = q.begin();
  cout << "Iterator is_null(): " << boolalpha << it.is_null() << endl;
  
  cout << "\n----------------------- \n\n";
  
  
  return true;
}


TEST(TEST_DEQUE, TestDeque_rev) {
  bool success = test_deque_push_front_pop_back(false);
  EXPECT_EQ(success, true);
}



TEST(TEST_DEQUE, TestDeque) {
  bool success = test_deque_push_back_pop_front(false);
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*

l1_dequeue git:(master) ✗  😊 $> tr includes
includes
├── deque
├── linked_list_functions
└── node

3 directories, 0 files
l1_dequeue git:(master) ✗  😊 $> ./build/bin/basic_test


----------running basic_test.cpp---------


[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from TEST_DEQUE
[ RUN      ] TEST_DEQUE.TestDeque_rev
Deque: Deque:Head-><-[0]-> |||

Deque: Deque:Head-><-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||



it->>90
it->>80
it->>70
it->>60
it->>50
it->>40
it->>30
it->>20
it->>10
it->>0


popping Deque: [   0]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> |||

popping Deque: [  10]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> |||

popping Deque: [  20]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> |||

popping Deque: [  30]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> |||

popping Deque: [  40]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> |||

popping Deque: [  50]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> |||

popping Deque: [  60]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> |||

popping Deque: [  70]: Deque:Head-><-[90]-> <-[80]-> |||

popping Deque: [  80]: Deque:Head-><-[90]-> |||

popping Deque: [  90]: Deque:Head->|||



Iterator is_null(): true

----------------------- 

[       OK ] TEST_DEQUE.TestDeque_rev (1 ms)
[ RUN      ] TEST_DEQUE.TestDeque
Deque: Deque:Head-><-[0]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||



it->>0
it->>10
it->>20
it->>30
it->>40
it->>50
it->>60
it->>70
it->>80
it->>90


popping Deque: [   0]: Deque:Head-><-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  10]: Deque:Head-><-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  20]: Deque:Head-><-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  30]: Deque:Head-><-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  40]: Deque:Head-><-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  50]: Deque:Head-><-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  60]: Deque:Head-><-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  70]: Deque:Head-><-[80]-> <-[90]-> |||

popping Deque: [  80]: Deque:Head-><-[90]-> |||

popping Deque: [  90]: Deque:Head->|||



Iterator is_null(): true

----------------------- 

[       OK ] TEST_DEQUE.TestDeque (2 ms)
[----------] 2 tests from TEST_DEQUE (3 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (3 ms total)
[  PASSED  ] 2 tests.
l1_dequeue git:(master) ✗  😊 $> cd build              
build git:(master) ✗  😊 $> make && ./bin/basic_test
[ 10%] Built target gtest
Scanning dependencies of target basic_test
[ 15%] Building CXX object CMakeFiles/basic_test.dir/_tests/_test_files/basic_test.cpp.o
[ 21%] Linking CXX executable bin/basic_test
[ 21%] Built target basic_test
[ 31%] Built target testA
[ 42%] Built target testB
[ 52%] Built target main
[ 68%] Built target gmock
[ 89%] Built target gmock_main
[100%] Built target gtest_main


----------running basic_test.cpp---------


[==========] Running 2 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 2 tests from TEST_DEQUE
[ RUN      ] TEST_DEQUE.TestDeque_rev
Deque: Deque:Head-><-[0]-> |||

Deque: Deque:Head-><-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

Deque: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||



it->>90
it->>80
it->>70
it->>60
it->>50
it->>40
it->>30
it->>20
it->>10
it->>0


popping Deque: [   0]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> |||

popping Deque: [  10]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> |||

popping Deque: [  20]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> |||

popping Deque: [  30]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> |||

popping Deque: [  40]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> |||

popping Deque: [  50]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> |||

popping Deque: [  60]: Deque:Head-><-[90]-> <-[80]-> <-[70]-> |||

popping Deque: [  70]: Deque:Head-><-[90]-> <-[80]-> |||

popping Deque: [  80]: Deque:Head-><-[90]-> |||

popping Deque: [  90]: Deque:Head->|||



Iterator is_null(): true

----------------------- 

[       OK ] TEST_DEQUE.TestDeque_rev (1 ms)
[ RUN      ] TEST_DEQUE.TestDeque
Deque: Deque:Head-><-[0]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> |||

Deque: Deque:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||



it->>0
it->>10
it->>20
it->>30
it->>40
it->>50
it->>60
it->>70
it->>80
it->>90


popping Deque: [   0]: Deque:Head-><-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  10]: Deque:Head-><-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  20]: Deque:Head-><-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  30]: Deque:Head-><-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  40]: Deque:Head-><-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  50]: Deque:Head-><-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  60]: Deque:Head-><-[70]-> <-[80]-> <-[90]-> |||

popping Deque: [  70]: Deque:Head-><-[80]-> <-[90]-> |||

popping Deque: [  80]: Deque:Head-><-[90]-> |||

popping Deque: [  90]: Deque:Head->|||



Iterator is_null(): true

----------------------- 

[       OK ] TEST_DEQUE.TestDeque (0 ms)
[----------] 2 tests from TEST_DEQUE (1 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 1 test case ran. (1 ms total)
[  PASSED  ] 2 tests.
build git:(master) ✗  😊 $> 
*/