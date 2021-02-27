#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


#include "../../includes/node/node.h"
#include "../../includes/linked_list_functions/linkedlistfunctionsTemplated.h"
#include "../../includes/stack/MyStack.h"
#include "../../includes/queue/MyQueue.h"

//------------------------------------------------------------------------------------------
//Files we are testing:



//------------------------------------------------------------------------------------------

using namespace std;
bool  test_linked_list_functions(bool debug = false){

  node<int> *head=nullptr;
  for (int i = 0; i < 10; i++){
    _insert_head(head, (i+1) * 10);
  }
  _print_list(head);


  node<int> *inserted;
  node<int> *this_node;
  int n;

  cout << "\n\n======= testing insert =======================" << endl;
  n = 50;
  cout << "\n\n----------- A node at the middle: " << n << endl;

  cout << "\n\ntesting prev and next links: " << endl;
  this_node = _search_list(head, n);
  cout << "found " << n << ": " << *this_node << endl;
  cout << "before: " << n << ": " << *(this_node->_prev) << endl;
  cout << "after: " << n << ": " << *(this_node->_next) << endl;

  cout << "\n\ninsert_after(): " << endl;
  inserted = _insert_after(head, this_node, n - 5);
  _print_list(head);
  cout << *inserted << " was inserted" << endl;

  cout << "\n\ninsert_before()" << endl;
  inserted = _insert_before(head, this_node, n + 5);
  _print_list(head);
  cout << *inserted << " was inserted" << endl;

  cout << "\n\n======= testing delete =======================" << endl;


  cout << "/n/n------------- deleting the last element: " << endl;
  this_node = _search_list(head, 10); //last element
  cout << "about to delete " << *this_node << endl;
  cout << "deleted " << _delete_node(head, this_node) << ": " << endl;
  _print_list(head);



  return true;
}

bool test_stack(bool debug = false)
{
  Stack<int> s;
  for (int i = 0; i < 10; i++){
    s.push(i * 10);
    cout <<"stack: "<< s << endl;
  }
  cout << endl<< endl;

  for(Stack<int>::Iterator it = s.begin(); it != s.end(); it++){
    cout << "it->>" << *it << endl;
  }
  cout << endl<< endl;
  for (; !s.empty();){
    cout << "popping stack: [" << setw(4) << s.pop() << "]: " << s << endl;
  }
  cout << endl
       << endl;
  Stack<int>::Iterator it = s.begin();
  cout << "Iterator is_null(): " << boolalpha << it.is_null() << endl;

  cout << "\n----------------------- \n\n";
  
  return true;
}

bool test_queue(bool debug = false)
{
  Queue<int> q;
  for (int i = 0; i < 10; i++){
    q.push(i * 10);
    cout <<"queue: "<< q << endl;
  }
  cout << endl<< endl;

  for(Queue<int>::Iterator it = q.begin(); it != q.end(); it++){
    cout << "it->>" << *it << endl;
  }
  cout << endl<< endl;
  for (; !q.empty();){
    cout << "popping queue: [" << setw(4) << q.pop() << "]: " << q << endl;
  }
  cout << endl
       << endl;
  Queue<int>::Iterator it = q.begin();
  cout << "Iterator is_null(): " << boolalpha << it.is_null() << endl;
  
  cout << "\n----------------------- \n\n";
  
  
  return true;
}

TEST(TEST_FUNCTIONS, TestLinkedListFunctions) {
  bool success = test_linked_list_functions(true);
  EXPECT_EQ(success, true);
}

TEST(TEST_FUNCTIONS, TestQueue) {
  bool success = test_queue(true);
  EXPECT_EQ(success, true);
}

TEST(TEST_FUNCTIONS, TestStack) {
  bool success = test_stack(true);
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*

08-stack-queue git:(master) ✗  😊 $> tr includes 
includes
├── linked_list_functions
├── node
├── queue
└── stack

4 directories, 0 files
08-stack-queue git:(master) ✗  😊 $> build/bin/basic_test


----------running basic_test.cpp---------


[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from TEST_FUNCTIONS
[ RUN      ] TEST_FUNCTIONS.TestLinkedListFunctions
Head-><-[100]-> <-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> |||


======= testing insert =======================


----------- A node at the middle: 50


testing prev and next links: 
found 50: <-[50]-> 
before: 50: <-[60]-> 
after: 50: <-[40]-> 


insert_after(): 
Head-><-[100]-> <-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[45]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> |||
<-[45]->  was inserted


insert_before()
Head-><-[100]-> <-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[55]-> <-[50]-> <-[45]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> |||
<-[55]->  was inserted


======= testing delete =======================
/n/n------------- deleting the last element: 
about to delete <-[10]-> 
deleted 10: 
Head-><-[100]-> <-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[55]-> <-[50]-> <-[45]-> <-[40]-> <-[30]-> <-[20]-> |||
[       OK ] TEST_FUNCTIONS.TestLinkedListFunctions (0 ms)
[ RUN      ] TEST_FUNCTIONS.TestQueue
queue: Queue:Head-><-[0]-> |||

queue: Queue:Head-><-[0]-> <-[10]-> |||

queue: Queue:Head-><-[0]-> <-[10]-> <-[20]-> |||

queue: Queue:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> |||

queue: Queue:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> |||

queue: Queue:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> |||

queue: Queue:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> |||

queue: Queue:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> |||

queue: Queue:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> |||

queue: Queue:Head-><-[0]-> <-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||



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


popping queue: [   0]: Queue:Head-><-[10]-> <-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping queue: [  10]: Queue:Head-><-[20]-> <-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping queue: [  20]: Queue:Head-><-[30]-> <-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping queue: [  30]: Queue:Head-><-[40]-> <-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping queue: [  40]: Queue:Head-><-[50]-> <-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping queue: [  50]: Queue:Head-><-[60]-> <-[70]-> <-[80]-> <-[90]-> |||

popping queue: [  60]: Queue:Head-><-[70]-> <-[80]-> <-[90]-> |||

popping queue: [  70]: Queue:Head-><-[80]-> <-[90]-> |||

popping queue: [  80]: Queue:Head-><-[90]-> |||

popping queue: [  90]: Queue:Head->|||



Iterator is_null(): true

----------------------- 

[       OK ] TEST_FUNCTIONS.TestQueue (0 ms)
[ RUN      ] TEST_FUNCTIONS.TestStack
stack: Stack:Head-><-[0]-> |||

stack: Stack:Head-><-[10]-> <-[0]-> |||

stack: Stack:Head-><-[20]-> <-[10]-> <-[0]-> |||

stack: Stack:Head-><-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

stack: Stack:Head-><-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

stack: Stack:Head-><-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

stack: Stack:Head-><-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

stack: Stack:Head-><-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

stack: Stack:Head-><-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

stack: Stack:Head-><-[90]-> <-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||



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


popping stack: [  90]: Stack:Head-><-[80]-> <-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

popping stack: [  80]: Stack:Head-><-[70]-> <-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

popping stack: [  70]: Stack:Head-><-[60]-> <-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

popping stack: [  60]: Stack:Head-><-[50]-> <-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

popping stack: [  50]: Stack:Head-><-[40]-> <-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

popping stack: [  40]: Stack:Head-><-[30]-> <-[20]-> <-[10]-> <-[0]-> |||

popping stack: [  30]: Stack:Head-><-[20]-> <-[10]-> <-[0]-> |||

popping stack: [  20]: Stack:Head-><-[10]-> <-[0]-> |||

popping stack: [  10]: Stack:Head-><-[0]-> |||

popping stack: [   0]: Stack:Head->|||



Iterator is_null(): true

----------------------- 

[       OK ] TEST_FUNCTIONS.TestStack (1 ms)
[----------] 3 tests from TEST_FUNCTIONS (1 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (2 ms total)
[  PASSED  ] 3 tests.
08-stack-queue git:(master) ✗  😊 $> 
*/


