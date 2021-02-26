#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>


//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/airport/simulation.h"


//------------------------------------------------------------------------------------------

using namespace std;

bool test_airport(bool debug = false){

  cout<<endl<<endl<<"======================================="<<endl<<endl;
  srand(time(0));
  for (int i=0; i<20; i++){
      cout << "---------------------- [" << i << "] ---------------------------" << endl;
      simulate_airport(debug);
  }
  cout <<endl<<endl<< "========== END SIMULATION ==================" << endl;
  
  return true;
}


TEST(TEST_AIRPORT, TestAirport) {
  bool success = test_airport(false);
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}



/*

08-airport git:(master) ✗  😊 $> tr
.
├── _tests
│   ├── _test_files
│   ├── _test_includes
│   └── other
│       └── cmake
├── build
│   ├── bin
│   └── lib
├── cmake
└── includes
    ├── airport
    ├── linked_list_functions
    ├── node
    ├── queue
    └── stack

15 directories, 0 files
08-airport git:(master) ✗  😊 $> cd build
build git:(master) ✗  😊 $> make && ./bin/basic_test[  7%] Built target gtest
[ 29%] Built target basic_test
[ 37%] Built target testA
[ 44%] Built target testB
[ 66%] Built target main
[ 77%] Built target gmock
[ 92%] Built target gmock_main
[100%] Built target gtest_main


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_AIRPORT
[ RUN      ] TEST_AIRPORT.TestAirport


=======================================

---------------------- [0] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
165 landed
41 took off
3 planes crashed. :(
Average waiting time to land: 9.66061
Average waiting time to take off: 500.707


---------------------- [1] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
152 landed
45 took off
4 planes crashed. :(
Average waiting time to land: 9.34868
Average waiting time to take off: 417.578


---------------------- [2] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
125 landed
55 took off
No planes crashed. :)
Average waiting time to land: 9.592
Average waiting time to take off: 359.6


---------------------- [3] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
153 landed
43 took off
13 planes crashed. :(
Average waiting time to land: 11.4379
Average waiting time to take off: 350.791


---------------------- [4] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
152 landed
45 took off
4 planes crashed. :(
Average waiting time to land: 9.59211
Average waiting time to take off: 467.867


---------------------- [5] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
141 landed
49 took off
1 planes crashed. :(
Average waiting time to land: 9.14894
Average waiting time to take off: 354.878


---------------------- [6] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
139 landed
49 took off
No planes crashed. :)
Average waiting time to land: 8.40288
Average waiting time to take off: 418.673


---------------------- [7] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
144 landed
48 took off
1 planes crashed. :(
Average waiting time to land: 8.5
Average waiting time to take off: 460.188


---------------------- [8] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
131 landed
53 took off
2 planes crashed. :(
Average waiting time to land: 9.22901
Average waiting time to take off: 422.34


---------------------- [9] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
115 landed
57 took off
1 planes crashed. :(
Average waiting time to land: 9.10435
Average waiting time to take off: 392.702


---------------------- [10] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
125 landed
54 took off
No planes crashed. :)
Average waiting time to land: 9.48
Average waiting time to take off: 427.611


---------------------- [11] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
168 landed
40 took off
No planes crashed. :)
Average waiting time to land: 9.67262
Average waiting time to take off: 457.55


---------------------- [12] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
164 landed
41 took off
21 planes crashed. :(
Average waiting time to land: 11.8232
Average waiting time to take off: 535.366


---------------------- [13] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
147 landed
47 took off
1 planes crashed. :(
Average waiting time to land: 9.2381
Average waiting time to take off: 382.872


---------------------- [14] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
141 landed
49 took off
2 planes crashed. :(
Average waiting time to land: 10.0355
Average waiting time to take off: 366.918


---------------------- [15] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
163 landed
41 took off
12 planes crashed. :(
Average waiting time to land: 11.7178
Average waiting time to take off: 431.341


---------------------- [16] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
170 landed
38 took off
8 planes crashed. :(
Average waiting time to land: 10.0765
Average waiting time to take off: 421.474


---------------------- [17] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
148 landed
47 took off
No planes crashed. :)
Average waiting time to land: 9.91892
Average waiting time to take off: 499.277


---------------------- [18] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
165 landed
41 took off
5 planes crashed. :(
Average waiting time to land: 9.92121
Average waiting time to take off: 426.902


---------------------- [19] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
136 landed
50 took off
6 planes crashed. :(
Average waiting time to land: 10.1029
Average waiting time to take off: 366.08




========== END SIMULATION ==================
[       OK ] TEST_AIRPORT.TestAirport (12 ms)
[----------] 1 test from TEST_AIRPORT (12 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (12 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $> 

*/