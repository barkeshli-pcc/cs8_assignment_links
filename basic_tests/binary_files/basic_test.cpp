#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <string>
#include <fstream>


//------------------------------------------------------------------------------------------
//Files we are testing:

#include "../../includes/binary_files/file_record.h"
#include "../../includes/binary_files/utilities.h"


//------------------------------------------------------------------------------------------

using namespace std;
bool simple_test(bool debug = false){

    fstream f;
    //reset the file: use this for new files
    open_fileW(f, "record_list.bin");

    FileRecord r;
    int recno=-1;
    vector<string> v;

    v = vector<string>({"Joe Zero", "000"});
    r = FileRecord(v); //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;

    v = vector<string>({"One Arm Jane", "111"});
    r = FileRecord(v); //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;

    v = vector<string>({"Two face Harvey", "222"});
    r = FileRecord(v); //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;

    v = vector<string>({"Three Eyed Raven", "333"});
    r = FileRecord(v); //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;

    v = vector<string>({"Four Square Circle", "444"});
    r = FileRecord(v); //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;

    v = vector<string>({"Cinco De Mayo, Bryan!", "555"});
    r = FileRecord(v); //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;

    v = vector<string>({"The Six Shooter Kid!", "666"});
    r = FileRecord(v); //filling the envelop
    recno = r.write(f);
    cout<<"wrote into record: "<<recno<<endl;



    f.close();



    FileRecord r2;
    //open the file for reading and writing.
    open_fileRW(f, "record_list.bin" );
    int i = 0;
    long bytes = r2.read(f, i); //empty envelop to be filled by the FileRecord object
    while (bytes>0){
      cout<<"record "<<i<<": "<<r2<<endl;
      i++;
      bytes = r2.read(f, i);
    }
    return true;

}


TEST(TEST_SIMPLE, TestSimple) {
  bool success = simple_test(true);
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
└── binary_files
    ├── file_record.cpp
    ├── file_record.h
    ├── utilities.cpp
    └── utilities.h

1 directory, 4 files
build git:(master) ✗  😊 $> 
build git:(master) ✗  😊 $> ./bin/basic_test


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_SIMPLE
[ RUN      ] TEST_SIMPLE.TestSimple
wrote into record: 0
wrote into record: 1
wrote into record: 2
wrote into record: 3
wrote into record: 4
wrote into record: 5
wrote into record: 6
record 0:                  Joe Zero                      000
record 1:              One Arm Jane                      111
record 2:           Two face Harvey                      222
record 3:          Three Eyed Raven                      333
record 4:        Four Square Circle                      444
record 5:     Cinco De Mayo, Bryan!                      555
record 6:      The Six Shooter Kid!                      666
[       OK ] TEST_SIMPLE.TestSimple (5 ms)
[----------] 1 test from TEST_SIMPLE (5 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (5 ms total)
[  PASSED  ] 1 test.
