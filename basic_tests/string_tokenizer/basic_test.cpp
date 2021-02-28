#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


//------------------------------------------------------------------------------------------
//Files we are testing:

#include "../../includes/tokenizer/stokenize.h"



//------------------------------------------------------------------------------------------

using namespace std;

void test_s_tokenize_simple();

bool test_tokenize(bool debug = false)
{
  test_s_tokenize_simple();
  return true;
}


void test_s_tokenize_simple(){
    char s[] = 
            "So, it was the night of october 17th. pi was still 3.14. sigh! 2.";
//    char s[] = "it";
    cout << "\n\ntokenizing: [" << s << "]\n" << endl;
    STokenizer stk(s);
    Token t;
    stk>>t;
    while(stk.more()){
        //process token here...
        cout<<setw(10)<<t.type_string()<<setw(10)<<t<<endl;


        t = Token();
        stk>>t;
    }

}




TEST(TEST_TOKENIZER, TestTokenize) {
  bool success = test_tokenize(true);
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

/*


tokenizer git:(master) ✗  😊 $> tree includes
includes
└── tokenizer
    ├── constants.h
    ├── ftokenize.cpp
    ├── ftokenize.h
    ├── state_machine_functions.cpp
    ├── state_machine_functions.h
    ├── stokenize.cpp
    ├── stokenize.h
    ├── token.cpp
    └── token.h

1 directory, 9 files
tokenizer git:(master) ✗  😊 $> ./build/bin/basic_test


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_TOKENIZER
[ RUN      ] TEST_TOKENIZER.TestSTokenize
     ALPHA         |So|
      PUNC         |,|
     SPACE         | |
     ALPHA         |it|
     SPACE         | |
     ALPHA         |was|
     SPACE         | |
     ALPHA         |the|
     SPACE         | |
     ALPHA         |night|
     SPACE         | |
     ALPHA         |of|
     SPACE         | |
     ALPHA         |october|
     SPACE         | |
    NUMBER         |17|
     ALPHA         |th|
      PUNC         |.|
     SPACE         | |
     ALPHA         |pi|
     SPACE         | |
     ALPHA         |was|
     SPACE         | |
     ALPHA         |still|
     SPACE         | |
    NUMBER         |3.14|
      PUNC         |.|
     SPACE         | |
     ALPHA         |sigh|
   UNKNOWN         |!|
     SPACE         | |
    NUMBER         |2|
      PUNC         |.|
[       OK ] TEST_TOKENIZER.TestSTokenize (1 ms)
[----------] 1 test from TEST_TOKENIZER (1 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (1 ms total)
[  PASSED  ] 1 test.
tokenizer git:(master) ✗  😊 $> 


*/





