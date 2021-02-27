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

08-airport git:(master) ✗  😊 $> tr includes
includes
├── airport
├── linked_list_functions
├── node
├── queue
└── stack

5 directories, 0 files
08-airport git:(master) ✗  😊 $> ./build/bin/basic_test


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
137 landed
50 took off
1 planes crashed. :(
Average waiting time to land: 9.35766
Average waiting time to take off: 338.82


---------------------- [1] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
137 landed
50 took off
No planes crashed. :)
Average waiting time to land: 8.91241
Average waiting time to take off: 346.44


---------------------- [2] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
140 landed
49 took off
No planes crashed. :)
Average waiting time to land: 9.97143
Average waiting time to take off: 548.082


---------------------- [3] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
127 landed
53 took off
1 planes crashed. :(
Average waiting time to land: 9.06299
Average waiting time to take off: 440.528


---------------------- [4] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
124 landed
54 took off
8 planes crashed. :(
Average waiting time to land: 9.95968
Average waiting time to take off: 393.389


---------------------- [5] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
142 landed
48 took off
5 planes crashed. :(
Average waiting time to land: 8.84507
Average waiting time to take off: 443.333


---------------------- [6] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
128 landed
52 took off
7 planes crashed. :(
Average waiting time to land: 11.4922
Average waiting time to take off: 258.519


---------------------- [7] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
128 landed
53 took off
No planes crashed. :)
Average waiting time to land: 9.78906
Average waiting time to take off: 418.604


---------------------- [8] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
134 landed
51 took off
1 planes crashed. :(
Average waiting time to land: 8.81343
Average waiting time to take off: 427.608


---------------------- [9] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
140 landed
49 took off
1 planes crashed. :(
Average waiting time to land: 9.24286
Average waiting time to take off: 429.51


---------------------- [10] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
137 landed
50 took off
2 planes crashed. :(
Average waiting time to land: 9.09489
Average waiting time to take off: 446.86


---------------------- [11] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
137 landed
50 took off
2 planes crashed. :(
Average waiting time to land: 10.0219
Average waiting time to take off: 280.5


---------------------- [12] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
154 landed
45 took off
2 planes crashed. :(
Average waiting time to land: 10.0519
Average waiting time to take off: 481.311


---------------------- [13] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
121 landed
56 took off
8 planes crashed. :(
Average waiting time to land: 10.2231
Average waiting time to take off: 418.893


---------------------- [14] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
131 landed
52 took off
No planes crashed. :)
Average waiting time to land: 9.25954
Average waiting time to take off: 406.962


---------------------- [15] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
153 landed
45 took off
7 planes crashed. :(
Average waiting time to land: 10.3987
Average waiting time to take off: 418.133


---------------------- [16] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
138 landed
50 took off
No planes crashed. :)
Average waiting time to land: 8.80435
Average waiting time to take off: 410.86


---------------------- [17] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
160 landed
42 took off
18 planes crashed. :(
Average waiting time to land: 11.5875
Average waiting time to take off: 427.833


---------------------- [18] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
128 landed
53 took off
No planes crashed. :)
Average waiting time to land: 9.39844
Average waiting time to take off: 370.698


---------------------- [19] ---------------------------
============================================
time to take off      : 15
time to land:         : 5
probability of landing: 0.1
probability of takeoff: 0.08
fuel: time to crash   : 20
total simulation time : 1440


. . . . . . . . . . . . . . . . . . . . . . . 
143 landed
48 took off
No planes crashed. :)
Average waiting time to land: 9.74825
Average waiting time to take off: 484




========== END SIMULATION ==================
[       OK ] TEST_AIRPORT.TestAirport (30 ms)
[----------] 1 test from TEST_AIRPORT (30 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (30 ms total)
[  PASSED  ] 1 test.
08-airport git:(master) ✗  😊 $>   


*/