#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string>

int random(int low, int high){
  //call srand in main if you want better random numbers.
  return static_cast<int>(low + (rand() % static_cast<int>((high - low + 1))));
}
//------------------------------------------------------------------------------------------
//Files we are testing:

#include "../../includes/heap/heap.h"
#include "../../includes/heap/pqueue.h"

//------------------------------------------------------------------------------------------

using namespace std;
const string line = "\n"+string(50,'-')+"\n";
const string dashes = "\n"+string(50,'.')+"\n";

bool basic_heap_test(bool debug = false){
    cout << line << endl
         << "Heap Test: " << line<<line << endl;
    Heap<int> heap;

    for (int i = 0; i < 40; i++){
        heap.insert(random(10, 100));
    }
    cout <<endl<<line<< heap <<line<< endl;
    cout << "heap is not empty: " << heap.is_empty() << endl;
    cout << "number of elements on the heap: " << heap.size() << endl;
    cout << "the tree is " << (heap.verify() ? "" : "in") << "valid." << endl;
    int *heap_array = heap.heap_array();
    cout << "heap array: " << endl;

    for (int i = 0; i < heap.size(); i++)
    {
        cout <<"|"<< heap_array[i];
    }
    cout << "|";        
    cout << "\n\n\npop test\n\n";
    while (!heap.is_empty()){
        cout << "removed:  " << heap.remove() << endl;
        if(heap.is_empty())
            cout << "three is now empty." << endl;
        else
            cout << "top of the heap: " << heap.top() << endl;
        cout << "the tree is " << (heap.verify() ? "" : "in") << "valid." << endl;
        cout << "the new tree: " << endl<<dashes
                << heap <<endl<<line<< endl;
}

    return true;
}
bool basic_pq_test(bool debug = false){
    PQueue<string> pq;
    cout << line 
         << "Priority Queue Test: " <<endl<< line<<line << endl;

    pq.push("joe", 3);
    pq.push("bob", 1);
    pq.push("jack", 4);
    pq.push("betty", 5);
    pq.push("Kathy", 6);
    pq.push("Jose", 8);
    pq.push("bill", 2);
    pq.push("Marie", 0);
    pq.push("sam after bill", 2);
    pq.push("Kathy tarde", 6);
    pq.push("Jose later", 8);
    pq.push("bill the second", 2);
    pq.push("Marie's sister", 0);
    pq.push("sam dunk", 2);
    if(debug)
        cout<<pq<<line<<endl;
    while (!pq.is_empty()){
        cout<<"POPPED: "<<pq.pop()<<endl;
        if(debug)
            cout<<dashes<<pq<<endl<<line<<endl;
    }

    return true;
}

TEST(TEST_HEAP, TestHeap) {
  bool success = basic_heap_test(true);
  EXPECT_EQ(success, true);
}
TEST(TEST_PQ, TestPQ) {
  bool success = basic_pq_test(false);
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
└── heap
    ├── heap.h
    └── pqueue.h

1 directory, 2 files
build git:(master) ✗  😊 $> ./bin/basic_test

----------running basic_test.cpp---------


[==========] Running 2 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 1 test from TEST_HEAP
[ RUN      ] TEST_HEAP.TestHeap

--------------------------------------------------

Heap Test: 
--------------------------------------------------

--------------------------------------------------



--------------------------------------------------
                54
            70
                31
        86
                65
            73
                47
    92
                54
            74
                48
        82
                66
            73
                33
94
                72
            72
                65
        74
                28
            56
                41
                    32
    86
                    24
                39
                    21
            66
                    38
                42
                    15
        86
                    39
                40
                    39
            67
                    17
                36
                    27

--------------------------------------------------

heap is not empty: 0
number of elements on the heap: 40
the tree is valid.
heap array: 
|94|86|92|86|74|82|86|67|66|56|72|73|74|73|70|36|40|42|39|41|28|65|72|33|66|48|54|47|65|31|54|27|17|39|39|15|38|21|24|32|


pop test

removed:  94
top of the heap: 92
the tree is valid.
the new tree: 

..................................................
                54
            70
                31
        73
                32
            65
                47
    86
                54
            74
                48
        82
                66
            73
                33
92
                72
            72
                65
        74
                28
            56
                41
    86
                    24
                39
                    21
            66
                    38
                42
                    15
        86
                    39
                40
                    39
            67
                    17
                36
                    27


--------------------------------------------------

removed:  92
top of the heap: 86
the tree is valid.
the new tree: 

..................................................
                54
            70
                31
        73
                32
            65
                47
    86
                54
            74
                48
        82
                66
            73
                33
86
                72
            72
                65
        74
                28
            56
                41
    86
                39
                    21
            66
                    38
                42
                    15
        67
                    39
                39
                    24
            40
                    17
                36
                    27


--------------------------------------------------

removed:  86
top of the heap: 86
the tree is valid.
the new tree: 

..................................................
                54
            70
                31
        73
                32
            65
                47
    86
                54
            74
                48
        82
                66
            73
                33
86
                21
            72
                65
        72
                28
            56
                41
    74
                39
            66
                    38
                42
                    15
        67
                    39
                39
                    24
            40
                    17
                36
                    27


--------------------------------------------------

removed:  86
top of the heap: 86
the tree is valid.
the new tree: 

..................................................
                54
            70
                31
        73
                32
            65
                47
    82
                38
            54
                48
        74
                66
            73
                33
86
                21
            72
                65
        72
                28
            56
                41
    74
                39
            66
                42
                    15
        67
                    39
                39
                    24
            40
                    17
                36
                    27


--------------------------------------------------

removed:  86
top of the heap: 82
the tree is valid.
the new tree: 

..................................................
                54
            70
                31
        73
                32
            65
                47
    74
                38
            54
                48
        73
                15
            66
                33
82
                21
            72
                65
        72
                28
            56
                41
    74
                39
            66
                42
        67
                    39
                39
                    24
            40
                    17
                36
                    27


--------------------------------------------------

removed:  82
top of the heap: 74
the tree is valid.
the new tree: 

..................................................
                54
            70
                31
        73
                32
            65
                47
    74
                38
            54
                48
        73
                15
            66
                33
74
                21
            65
                39
        72
                28
            56
                41
    72
                39
            66
                42
        67
                39
                    24
            40
                    17
                36
                    27


--------------------------------------------------

removed:  74
top of the heap: 74
the tree is valid.
the new tree: 

..................................................
                54
            70
                31
        73
                32
            65
                47
    73
                38
            54
                48
        66
                15
            33
                24
74
                21
            65
                39
        72
                28
            56
                41
    72
                39
            66
                42
        67
                39
            40
                    17
                36
                    27


--------------------------------------------------

removed:  74
top of the heap: 73
the tree is valid.
the new tree: 

..................................................
                17
            54
                31
        70
                32
            65
                47
    73
                38
            54
                48
        66
                15
            33
                24
73
                21
            65
                39
        72
                28
            56
                41
    72
                39
            66
                42
        67
                39
            40
                36
                    27


--------------------------------------------------

removed:  73
top of the heap: 73
the tree is valid.
the new tree: 

..................................................
                17
            54
                31
        65
                32
            47
                27
    70
                38
            54
                48
        66
                15
            33
                24
73
                21
            65
                39
        72
                28
            56
                41
    72
                39
            66
                42
        67
                39
            40
                36


--------------------------------------------------

removed:  73
top of the heap: 72
the tree is valid.
the new tree: 

..................................................
            54
                31
        65
                32
            47
                27
    70
                38
            54
                48
        66
                15
            33
                24
72
                21
            39
                17
        65
                28
            56
                41
    72
                39
            66
                42
        67
                39
            40
                36


--------------------------------------------------

removed:  72
top of the heap: 72
the tree is valid.
the new tree: 

..................................................
            54
        65
                32
            47
                27
    70
                38
            54
                48
        66
                15
            33
                24
72
                21
            39
                17
        65
                28
            56
                41
    67
                39
            42
                31
        66
                39
            40
                36


--------------------------------------------------

removed:  72
top of the heap: 70
the tree is valid.
the new tree: 

..................................................
            54
        65
            47
                27
    66
                38
            48
                32
        54
                15
            33
                24
70
                21
            39
                17
        65
                28
            56
                41
    67
                39
            42
                31
        66
                39
            40
                36


--------------------------------------------------

removed:  70
top of the heap: 67
the tree is valid.
the new tree: 

..................................................
            54
        65
            47
    66
                38
            48
                32
        54
                15
            33
                24
67
                21
            39
                17
        65
                28
            56
                41
    66
                27
            39
                31
        42
                39
            40
                36


--------------------------------------------------

removed:  67
top of the heap: 66
the tree is valid.
the new tree: 

..................................................
            54
        65
            47
    66
            48
                32
        54
                15
            33
                24
66
                21
            39
                17
        56
                28
            41
                38
    65
                27
            39
                31
        42
                39
            40
                36


--------------------------------------------------

removed:  66
top of the heap: 66
the tree is valid.
the new tree: 

..................................................
            32
        54
            47
    65
            48
        54
                15
            33
                24
66
                21
            39
                17
        56
                28
            41
                38
    65
                27
            39
                31
        42
                39
            40
                36


--------------------------------------------------

removed:  66
top of the heap: 65
the tree is valid.
the new tree: 

..................................................
            32
        54
            47
    65
            48
        54
            33
                24
65
                21
            39
                17
        41
                28
            38
                15
    56
                27
            39
                31
        42
                39
            40
                36


--------------------------------------------------

removed:  65
top of the heap: 65
the tree is valid.
the new tree: 

..................................................
            32
        54
            47
    54
            24
        48
            33
65
                21
            39
                17
        41
                28
            38
                15
    56
                27
            39
                31
        42
                39
            40
                36


--------------------------------------------------

removed:  65
top of the heap: 56
the tree is valid.
the new tree: 

..................................................
            32
        54
            47
    54
            24
        48
            33
56
            39
                17
        41
                28
            38
                15
    42
                27
            39
                31
        40
                21
            39
                36


--------------------------------------------------

removed:  56
top of the heap: 54
the tree is valid.
the new tree: 

..................................................
            32
        47
            17
    54
            24
        48
            33
54
            39
        41
                28
            38
                15
    42
                27
            39
                31
        40
                21
            39
                36


--------------------------------------------------

removed:  54
top of the heap: 54
the tree is valid.
the new tree: 

..................................................
            32
        47
            17
    48
            24
        33
            28
54
            39
        41
            38
                15
    42
                27
            39
                31
        40
                21
            39
                36


--------------------------------------------------

removed:  54
top of the heap: 48
the tree is valid.
the new tree: 

..................................................
            15
        32
            17
    47
            24
        33
            28
48
            39
        41
            38
    42
                27
            39
                31
        40
                21
            39
                36


--------------------------------------------------

removed:  48
top of the heap: 47
the tree is valid.
the new tree: 

..................................................
            15
        32
            17
    33
            24
        28
            27
47
            39
        41
            38
    42
            39
                31
        40
                21
            39
                36


--------------------------------------------------

removed:  47
top of the heap: 42
the tree is valid.
the new tree: 

..................................................
            15
        32
            17
    33
            24
        28
            27
42
            31
        39
            38
    41
            39
        40
                21
            39
                36


--------------------------------------------------

removed:  42
top of the heap: 41
the tree is valid.
the new tree: 

..................................................
            15
        32
            17
    33
            24
        28
            27
41
            31
        39
            38
    40
            39
        39
            36
                21


--------------------------------------------------

removed:  41
top of the heap: 40
the tree is valid.
the new tree: 

..................................................
            15
        32
            17
    33
            24
        28
            27
40
            31
        39
            38
    39
            21
        39
            36


--------------------------------------------------

removed:  40
top of the heap: 39
the tree is valid.
the new tree: 

..................................................
        32
            17
    33
            24
        28
            27
39
            31
        39
            38
    39
            21
        36
            15


--------------------------------------------------

removed:  39
top of the heap: 39
the tree is valid.
the new tree: 

..................................................
        32
    33
            24
        28
            27
39
            31
        38
            17
    39
            21
        36
            15


--------------------------------------------------

removed:  39
top of the heap: 39
the tree is valid.
the new tree: 

..................................................
        32
    33
        28
            27
39
            24
        31
            17
    38
            21
        36
            15


--------------------------------------------------

removed:  39
top of the heap: 38
the tree is valid.
the new tree: 

..................................................
        32
    33
        28
38
            24
        31
            17
    36
            21
        27
            15


--------------------------------------------------

removed:  38
top of the heap: 36
the tree is valid.
the new tree: 

..................................................
        32
    33
        28
36
        24
            17
    31
            21
        27
            15


--------------------------------------------------

removed:  36
top of the heap: 33
the tree is valid.
the new tree: 

..................................................
        17
    32
        28
33
        24
    31
            21
        27
            15


--------------------------------------------------

removed:  33
top of the heap: 32
the tree is valid.
the new tree: 

..................................................
        17
    28
        21
32
        24
    31
        27
            15


--------------------------------------------------

removed:  32
top of the heap: 31
the tree is valid.
the new tree: 

..................................................
        17
    28
        21
31
        24
    27
        15


--------------------------------------------------

removed:  31
top of the heap: 28
the tree is valid.
the new tree: 

..................................................
    21
        17
28
        24
    27
        15


--------------------------------------------------

removed:  28
top of the heap: 27
the tree is valid.
the new tree: 

..................................................
    21
27
        17
    24
        15


--------------------------------------------------

removed:  27
top of the heap: 24
the tree is valid.
the new tree: 

..................................................
    21
24
    17
        15


--------------------------------------------------

removed:  24
top of the heap: 21
the tree is valid.
the new tree: 

..................................................
    15
21
    17


--------------------------------------------------

removed:  21
top of the heap: 17
the tree is valid.
the new tree: 

..................................................
17
    15


--------------------------------------------------

removed:  17
top of the heap: 15
the tree is valid.
the new tree: 

..................................................
15


--------------------------------------------------

removed:  15
three is now empty.
the tree is valid.
the new tree: 

..................................................


--------------------------------------------------

[       OK ] TEST_HEAP.TestHeap (26 ms)
[----------] 1 test from TEST_HEAP (26 ms total)

[----------] 1 test from TEST_PQ
[ RUN      ] TEST_PQ.TestPQ

--------------------------------------------------
Priority Queue Test: 

--------------------------------------------------

--------------------------------------------------

POPPED: Jose
POPPED: Jose later
POPPED: Kathy
POPPED: Kathy tarde
POPPED: betty
POPPED: jack
POPPED: joe
POPPED: bill
POPPED: sam after bill
POPPED: bill the second
POPPED: sam dunk
POPPED: bob
POPPED: Marie
POPPED: Marie's sister
[       OK ] TEST_PQ.TestPQ (0 ms)
[----------] 1 test from TEST_PQ (0 ms total)

[----------] Global test environment tear-down
[==========] 2 tests from 2 test cases ran. (26 ms total)
[  PASSED  ] 2 tests.
build git:(master)  😊 $> 


*/
