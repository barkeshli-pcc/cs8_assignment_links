#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

//------------------------------------------------------------------------------------------
//Files we are testing:
#include "../../includes/table/table.h"


//------------------------------------------------------------------------------------------

using namespace std;

Table make_table(){
    vectorstr fields={"fname", "lname", "age"};

    Table t("student", fields);
    vectorstr row;
    row = {"Joe", "Gomez", "20"};
    t.insert_into(row);
    row = {"Karen", "Orozco", "21"};
    t.insert_into(row);
    row = {"Flo", "Yao", "29"};
    t.insert_into(row);
    row = {"Jack", "Yao", "19"};
    t.insert_into(row);
    row = {"Flo", "Jackson", "20"};
    t.insert_into(row);
    row = {"Flo", "Gomez", "20"};
    t.insert_into(row);
    return t;
}


bool table_basic(){
     Table t = make_table();
     cout<< "Here is table t: " << endl << t << endl;

     cout << "Here are all the Yaos:" << endl;
     cout << t.select({"fname", "lname", "age"}, "lname", "=", "Yao");

     Table tbl_student("student");
     cout << "\n\nhere is the student table: " << tbl_student << endl;

     cout << "\n20 year-olds:" << endl;
     cout << tbl_student.select({"age", "fname", "lname"}, "age", "=", "20");
     cout <<"record numbers from original table: "<< tbl_student.select_recnos() << endl
          << endl;

     cout << "\nolder than 20 years old:" << endl;
     cout << tbl_student.select({"age", "fname", "lname"}, "age", ">", "20");
     cout <<"record numbers from original table: "<< tbl_student.select_recnos() << endl
          << endl;

     cout << "\nyounger than 20 years old:" << endl;
     cout << tbl_student.select({"age", "fname", "lname"}, "age", "<", "20");
     cout <<"record numbers from original table: "<< tbl_student.select_recnos() << endl
          << endl;

     cout << "\n20 or younger:" << endl;
     cout << tbl_student.select({"age", "fname", "lname"}, "age", "<=", "20");
     cout <<"record numbers from original table: "<< tbl_student.select_recnos() << endl
          << endl;


     cout << "\n20 or older:" << endl;
     cout << tbl_student.select({"age", "fname", "lname"}, "age", ">=", "20");
     cout <<"record numbers from original table: "<< tbl_student.select_recnos() << endl
          << endl;


     cout << "----- END TEST --------" << endl;
     return true;
}


TEST(TABLE_BASIC, TableBasic) {
  bool success = table_basic();
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
├── binary_files
│   ├── file_record.cpp
│   ├── file_record.h
│   ├── utilities.cpp
│   └── utilities.h
├── bplustree
│   ├── bplustree.h
│   ├── btree_array_funcs.h
│   ├── map.h
│   ├── multimap.h
│   └── set_class.h
├── stl_utils
│   └── vector_utilities.h
└── table
    ├── deleted.h
    ├── table.cpp
    ├── table.h
    └── typedefs.h

4 directories, 14 files
build git:(master) ✗  😊 $> 
build git:(master) ✗  😊 $> ./bin/basic_test


----------running basic_test.cpp---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TABLE_BASIC
[ RUN      ] TABLE_BASIC.TableBasic

Table name: student, records: 6
                   _record                    fname                    lname                      age

                        0                      joe                    Gomez                       20
                        1                    Karen                   Orozco                       21
                        2                      Flo                      Yao                       29
                        3                     Jack                      Yao                       19
                        4                      Flo                  Jackson                       20
                        5                      Flo                    Gomez                       20



Table name: _select_table_1, records: 2
                   _record                    fname                    lname                      age

                        0                      Flo                      Yao                       29
                        1                     Jack                      Yao                       19



here is the student table: 
Table name: student, records: 6
                   _record                    fname                    lname                      age

                        0                      joe                    Gomez                       20
                        1                    Karen                   Orozco                       21
                        2                      Flo                      Yao                       29
                        3                     Jack                      Yao                       19
                        4                      Flo                  Jackson                       20
                        5                      Flo                    Gomez                       20



20 year-olds:

Table name: _select_table_4, records: 3
                   _record                      age                    fname                    lname

                        0                       20                      joe                    Gomez
                        1                       20                      Flo                  Jackson
                        2                       20                      Flo                    Gomez


older than 20 years old:

Table name: _select_table_6, records: 2
                   _record                      age                    fname                    lname

                        0                       21                    Karen                   Orozco
                        1                       29                      Flo                      Yao


younger than 20 years old:

Table name: _select_table_8, records: 1
                   _record                      age                    fname                    lname

                        0                       19                     Jack                      Yao


20 or younger:

Table name: _select_table_10, records: 4
                   _record                      age                    fname                    lname

                        0                       19                     Jack                      Yao
                        1                       20                      joe                    Gomez
                        2                       20                      Flo                  Jackson
                        3                       20                      Flo                    Gomez


20 or older:

Table name: _select_table_12, records: 5
                   _record                      age                    fname                    lname

                        0                       20                      joe                    Gomez
                        1                       20                      Flo                  Jackson
                        2                       20                      Flo                    Gomez
                        3                       21                    Karen                   Orozco
                        4                       29                      Flo                      Yao

----- END TEST --------
[       OK ] TABLE_BASIC.TableBasic (49 ms)
[----------] 1 test from TABLE_BASIC (49 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (49 ms total)
[  PASSED  ] 1 test.
build git:(master) ✗  😊 $>                                  




*/