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

