#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

int random(int low, int high){
  //call srand in main if you want better random numbers.
  return static_cast<int>(low + (rand() % static_cast<int>((high - low + 1))));
}
//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/hash/chained_hash.h"
#include "../../includes/hash/double_hash.h"
#include "../../includes/hash/constants.h"



//------------------------------------------------------------------------------------------

using namespace std;
struct HashRecord{
    int _key;
    string _item;
    HashRecord(int key=-1, string item=""):_key(key), _item(item){}
    friend ostream& operator <<(ostream& outs, const HashRecord& h){
        cout << "[" << h._key << ":" << h._item << "]";
        return outs;
    }
    friend bool operator < (const HashRecord& left, const HashRecord& right){
        return left._key < right._key;
    }
    friend bool operator > (const HashRecord& left, const HashRecord& right){
        return left._key > right._key;
    }
    friend bool operator == (const HashRecord& left, const HashRecord& right){
        return left._key == right._key;
    }
};

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
//We will need a function like this for any class/struct that will specialize 
//      the AVL class. (for use in the AVL's 
//      pre_order(), in_order(), post_order() functions)
string to_string(const HashRecord& h){
    return string(to_string(h._key) + " : " + h._item);
}
//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
bool double_hash_basic_test(bool debug = false)
{
    DoubleHash<HashRecord> double_hash;
    cout << "DoubleHash test. capacity:          " << double_hash.capacity() << endl;
    cout << "           initial collision count: " << double_hash.collisions() << endl;
    cout << "           initial size:            " << double_hash.size() << endl;
    for (int i = 0; i < double_hash.capacity() * 0.75; i++)
    {
        int r = random(100, 999);
        double_hash.insert(HashRecord(r, string("item__")+to_string(r)));
    }
    double_hash.insert(HashRecord(42, string("This is the meaning of life? A NON-PRIME number? @_@")));
    HashRecord hash_record;
    cout << endl
         << endl;
    cout << "           final collision count: " 
                        << double_hash.collisions() << endl;
    cout << "           final size:            " 
                        << double_hash.size() << endl;
    cout << "           is_present(42)::       " 
                        << boolalpha << double_hash.is_present(42) << endl;
    cout << "           find(42):              " 
                        << boolalpha << double_hash.find(42, hash_record) 
                        << " :: " << hash_record << endl;
    cout << "Here is the hash table after all the insertions: " << endl
                << double_hash << endl;
    cout << endl;
    cout << "----------------------------------" << endl;
    cout<<"the print anatomy: "<< endl;
    cout << "[006] [640:item__640](013)* hash2: 12" << endl<<endl;
    cout << ". . . . . . . . . . . . . . . . . . " << endl;
    cout << "[006]:           table index." << endl;
    cout << "[640:item__640]: record inserted: record's insertion operator" << endl;
    cout << "(013):           index where the record was originally hashed to" << endl;
    cout << "*                indicates there has been one or more collisions" << endl;
    cout << "hash2: 12:       value of hash2, the steps taken once a collision" << endl;
    cout << "                 has been detected " << endl;
        cout
        << "----------------------------------" << endl;
    return true;
}

bool double_hash_remove_test(bool debug = false)
{
    DoubleHash<HashRecord> double_hash;
    cout << "DoubleHash remove test. " << endl;
    for (int i = 0; i < double_hash.capacity() * 0.75; i++)
    {
        int r = random(100, 999);
        double_hash.insert(HashRecord(r, string("item__")+to_string(r)));
    }
    double_hash.insert(HashRecord(42, string("This is the meaning of life? A NON-PRIME number? @_@")));
    cout << "double_hash after all the inserts: " << endl
         << double_hash << endl;

    cout << "\nremoving 42: " << endl;
    if (double_hash.remove(42)){
        cout << "42 was removed successfully: " << endl
             << double_hash << endl;
        cout << "\n\n---------------------------------------------------\n" << endl;

        cout << "[013] - - - - - - " << endl;

        cout << "Note the indication of the 'PREVIOUSLY_USED` row" << endl;
        cout << "---------------------------------------------------\n\n" << endl;

    }
    else{
        cout << "FAILED to remove 42." << endl;
    }
    return true;
}

bool chained_hash_basic_test(bool debug = false){

    ChainedHash<HashRecord> chained_hash;
    cout << "ChainedHash test. capacity:         " << chained_hash.capacity() << endl;
    cout << "           initial size:            " << chained_hash.size() << endl;
    for (int i = 0; i < chained_hash.capacity() * 0.75; i++)
    {
        int r = random(100, 999);
        chained_hash.insert(HashRecord(r, string("item__")+to_string(r)));
    }
    chained_hash.insert(HashRecord(42, string("This is the meaning of life? A NON-PRIME number? @_@")));
    HashRecord hash_record;
    cout << endl
         << endl;
    cout << "           final size:            " 
                        << chained_hash.size() << endl;
    cout << "           is_present(42)::       " 
                        << boolalpha << chained_hash.is_present(42) << endl;
    cout << "           find(42):              " 
                        << boolalpha << chained_hash.find(42, hash_record) 
                        << " :: " << hash_record << endl;
    cout << "Here is the hash table after all the insertions: " << endl
                << chained_hash << endl;
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout<<"the print anatomy: "<< endl;
    cout << "[003] [345 : item__345][668 : item__668][801 : item__801]" << endl<<endl;
    cout << ". . . . . . . . . . . . . . . . . . " << endl;
    cout << "[003]:                                    table index." << endl;
    cout << "[345 : item__345][668 : item__668]...:    records inserted: inorder()" << endl;
    cout << "---------------------------------------------------------------" << endl;
    return true;
}
bool chained_hash_remove_test(bool debug = false){
    ChainedHash<HashRecord> chained_hash;
    cout << "DoubleHash remove test. " << endl;
    for (int i = 0; i < chained_hash.capacity() * 0.75; i++)
    {
        int r = random(100, 999);
        chained_hash.insert(HashRecord(r, string("item__")+to_string(r)));
    }
    chained_hash.insert(HashRecord(42, string("This is the meaning of life? A NON-PRIME number? @_@")));
    cout << "chained_hash after all the inserts: " << endl
         << chained_hash << endl;

    cout << "\nremoving 42: " << endl;
    if (chained_hash.remove(42)){
        cout << "42 was removed successfully: " << endl
             << chained_hash << endl;

    }
    else{
        cout << "FAILED to remove 42." << endl;
    }
    return true;
    return true;
}

TEST(TEST_DOUBLE_BASIC, TestDoubleHashBasic){
  bool success = double_hash_basic_test(true);
  EXPECT_EQ(success, true);
}

TEST(TEST_DOUBLE_REMOVE, TestDoubleHashRemove){
  bool success = double_hash_remove_test(true);
  EXPECT_EQ(success, true);
}
TEST(TEST_CHAINED_BASIC, TestChainedHashBasic){
  bool success = chained_hash_basic_test(true);
  EXPECT_EQ(success, true);
}

TEST(TEST_CHAINED_REMOVE, TestChainedHashRemove){
  bool success = chained_hash_remove_test(true);
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
├── avl
│   ├── avl.h
│   └── avl_functions.h
└── hash
    ├── chained_hash.h
    ├── chained_hash_list.h
    ├── constants.h
    ├── double_hash.h
    ├── hash_table.h.autosave
    └── open_hash.h

2 directories, 8 files
build git:(master) ✗  😊 $> cat ../includes/hash/constants.h
#ifndef CONSTANTS_H
#define CONSTANTS_H
#include  <math.h>
using namespace std;

const int TABLE_SIZE = 19; //811; //180799; //2121737;//180799;// 101119; //811;

#endif // CONSTANTS_H
build git:(master) ✗  😊 $> ./bin/basic_test


----------running basic_test.cpp---------


[==========] Running 4 tests from 4 test cases.
[----------] Global test environment set-up.
[----------] 1 test from TEST_DOUBLE_BASIC
[ RUN      ] TEST_DOUBLE_BASIC.TestDoubleHashBasic
DoubleHash test. capacity:          19
           initial collision count: 0
           initial size:            0


           final collision count: 25
           final size:            16
           is_present(42)::       true
           find(42):              true :: [42:This is the meaning of life? A NON-PRIME number? @_@]
Here is the hash table after all the insertions: 
[000] [209:item__209](000) 
[001]  
[002] [858:item__858](003)* hash2: 9
[003] [573:item__573](003) 
[004] [707:item__707](004) 
[005] [423:item__423](005) 
[006] [640:item__640](013)* hash2: 12
[007] [972:item__972](003)* hash2: 4
[008] [844:item__844](008) 
[009] [765:item__765](005)* hash2: 1
[010] [487:item__487](012)* hash2: 12
[011] [42:This is the meaning of life? A NON-PRIME number? @_@](004)* hash2: 9
[012] [449:item__449](012) 
[013] [230:item__230](002)* hash2: 10
[014]  
[015] [342:item__342](000)* hash2: 3
[016]  
[017] [378:item__378](017) 
[018] [592:item__592](003)* hash2: 15
----------- collisions(): 25 -----------


----------------------------------
the print anatomy: 
[006] [640:item__640](013)* hash2: 12

. . . . . . . . . . . . . . . . . . 
[006]:           table index.
[640:item__640]: record inserted: record's insertion operator
(013):           index where the record was originally hashed to
*                indicates there has been one or more collisions
hash2: 12:       value of hash2, the steps taken once a collision
                 has been detected 
----------------------------------
[       OK ] TEST_DOUBLE_BASIC.TestDoubleHashBasic (0 ms)
[----------] 1 test from TEST_DOUBLE_BASIC (0 ms total)

[----------] 1 test from TEST_DOUBLE_REMOVE
[ RUN      ] TEST_DOUBLE_REMOVE.TestDoubleHashRemove
DoubleHash remove test. 
double_hash after all the inserts: 
[000] [440:item__440](003)* hash2: 16
[001] [799:item__799](001) 
[002] [629:item__629](002) 
[003] [827:item__827](010)* hash2: 12
[004] [403:item__403](004) 
[005] [860:item__860](005) 
[006] [478:item__478](003)* hash2: 3
[007] [957:item__957](007) 
[008] [216:item__216](007)* hash2: 13
[009] [935:item__935](004)* hash2: 1
[010] [903:item__903](010) 
[011] [109:item__109](014)* hash2: 8
[012]  
[013] [42:This is the meaning of life? A NON-PRIME number? @_@](004)* hash2: 9
[014] [812:item__812](014) 
[015] [133:item__133](000)* hash2: 15
[016]  
[017]  
[018] [569:item__569](018) 
----------- collisions(): 15 -----------


removing 42: 
42 was removed successfully: 
[000] [440:item__440](003)* hash2: 16
[001] [799:item__799](001) 
[002] [629:item__629](002) 
[003] [827:item__827](010)* hash2: 12
[004] [403:item__403](004) 
[005] [860:item__860](005) 
[006] [478:item__478](003)* hash2: 3
[007] [957:item__957](007) 
[008] [216:item__216](007)* hash2: 13
[009] [935:item__935](004)* hash2: 1
[010] [903:item__903](010) 
[011] [109:item__109](014)* hash2: 8
[012]  
[013] - - - - - - 
[014] [812:item__812](014) 
[015] [133:item__133](000)* hash2: 15
[016]  
[017]  
[018] [569:item__569](018) 
----------- collisions(): 15 -----------



---------------------------------------------------

[013] - - - - - - 
Note the indication of the 'PREVIOUSLY_USED` row
---------------------------------------------------


[       OK ] TEST_DOUBLE_REMOVE.TestDoubleHashRemove (2 ms)
[----------] 1 test from TEST_DOUBLE_REMOVE (2 ms total)

[----------] 1 test from TEST_CHAINED_BASIC
[ RUN      ] TEST_CHAINED_BASIC.TestChainedHashBasic
ChainedHash test. capacity:         19
           initial size:            0


           final size:            0
           is_present(42)::       true
           find(42):              true :: [-1:]
Here is the hash table after all the insertions: 
[000] [893 : item__893]
[001] 
[002] 
[003] [136 : item__136]
[004] [42 : This is the meaning of life? A NON-PRIME number? @_@][479 : item__479]
[005] 
[006] 
[007] [121 : item__121][197 : item__197][767 : item__767]
[008] [312 : item__312][426 : item__426][749 : item__749]
[009] 
[010] 
[011] [372 : item__372][885 : item__885]
[012] [810 : item__810]
[013] 
[014] 
[015] [433 : item__433]
[016] 
[017] 
[018] [379 : item__379]


---------------------------------------------------------------
the print anatomy: 
[003] [345 : item__345][668 : item__668][801 : item__801]

. . . . . . . . . . . . . . . . . . 
[003]:                                    table index.
[345 : item__345][668 : item__668]...:    records inserted: inorder()
---------------------------------------------------------------
[       OK ] TEST_CHAINED_BASIC.TestChainedHashBasic (7 ms)
[----------] 1 test from TEST_CHAINED_BASIC (7 ms total)

[----------] 1 test from TEST_CHAINED_REMOVE
[ RUN      ] TEST_CHAINED_REMOVE.TestChainedHashRemove
DoubleHash remove test. 
chained_hash after all the inserts: 
[000] [228 : item__228]
[001] 
[002] [344 : item__344][724 : item__724]
[003] [345 : item__345][668 : item__668][801 : item__801]
[004] [42 : This is the meaning of life? A NON-PRIME number? @_@]
[005] 
[006] [690 : item__690]
[007] 
[008] 
[009] 
[010] [257 : item__257]
[011] 
[012] 
[013] [203 : item__203]
[014] [394 : item__394]
[015] [908 : item__908]
[016] [130 : item__130][396 : item__396][453 : item__453][491 : item__491]
[017] 
[018] 


removing 42: 
42 was removed successfully: 
[000] [228 : item__228]
[001] 
[002] [344 : item__344][724 : item__724]
[003] [345 : item__345][668 : item__668][801 : item__801]
[004] 
[005] 
[006] [690 : item__690]
[007] 
[008] 
[009] 
[010] [257 : item__257]
[011] 
[012] 
[013] [203 : item__203]
[014] [394 : item__394]
[015] [908 : item__908]
[016] [130 : item__130][396 : item__396][453 : item__453][491 : item__491]
[017] 
[018] 

[       OK ] TEST_CHAINED_REMOVE.TestChainedHashRemove (3 ms)
[----------] 1 test from TEST_CHAINED_REMOVE (3 ms total)

[----------] Global test environment tear-down
[==========] 4 tests from 4 test cases ran. (12 ms total)
[  PASSED  ] 4 tests.
build git:(master) ✗  😊 $> 
*/