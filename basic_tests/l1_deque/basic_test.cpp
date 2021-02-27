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

