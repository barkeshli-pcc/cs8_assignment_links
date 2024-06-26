#include "gtest/gtest.h"
#include <iostream>
#include <iomanip>

#include "../../includes/graph/graph.h"
#include "../../includes/graph/wgraph.h"

#include "../../includes/graph/gtraversals.h"
#include "../_test_includes/utilities.h" //outs << vector and set
using namespace std;

//----------------------------------------------------------------------------------------
//          COPY BASIC_TEST INTO THIS FILE.
//                    AND THEN,
//         DO NOT EDIT THIS FILE ANY FURTHER
//----------------------------------------------------------------------------------------
bool template_function_argument_demo(bool debug = false);
bool test_graph_print(bool debug = false);
bool test_graph_print_path_exists(bool debug=false);
bool test_graph_traversal(bool debug=false);
bool test_wgraph_dijkstra(bool debug=false);
//------ create graphs ------------------
graph<int> graph_x();
wgraph<int> wgraph_x();
//---------------------------------------
//------ function pointers ------------------

template <class T>
void print_vertex(T vertex);

template <class T>
void do_nothing(T vertex);
//---------------------------------------
template <class T>
void print_item(const T& element){
    cout << "[" << element << "] ";
}

template<class Process, class T, class Size>
void process_array(Process f, T arr[], Size size){
    for (Size i = 0; i < size; i++){
        f(arr[i]);
    }
    cout << endl;
}

bool template_function_argument_demo(bool debug){
    /*
    this function: template_function_argument_demo()
    send this function: print_item()
    as an argument to this function: process_array()
    
    This is accomplished by the Process template argument.
    inside the process_array() function, the Process f is called 
    like a simple function: f(x): this causes f to act on x
    
    
    */
    int arr[] = {1, 1, 3, 5, 8, 13, 21};
    process_array(print_item<int>, arr, 7);

    string weekdays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    process_array(print_item<string>, weekdays, 5);

    return true;
}

bool test_graph_basic(bool debug){
  //create a graph:
  graph<int> g = graph_x();
  // print graph
  cout << "here is the graph: " << endl
       << g << endl;
  //graph::size4():
  cout << "size of graph: " << g.size() << endl;
  //neighbors:
  set<int> neighbors = g.neighbors(g[3]);
  cout << "neighbors of [ 3]: "<<neighbors << endl;
  neighbors = g.neighbors(g[5]);
  cout << "neighbors of [ 5]: " << neighbors << endl;
  neighbors = g.neighbors(g[0]);
  cout  << "neighbors of [ 0]: "<< neighbors << endl;
  

  return true;
}
bool test_graph_path_exists(bool debug){
  graph<int> g = graph_x();
  // for (int i = 0; i < g.size(); i++){
  //   for (int j = 0; j < g.size(); j++){
  //     if (g.path_exists(i, j))
  //       cout << "A path exists between vertex " << i << " and " << j << endl;
  //     else
  //       cout << "A path DOES NOT exists between vertex " << i << " and " << j << endl;

  //   }
  // }
  cout << "g.path_exists(0, 4): " << boolalpha << g.path_exists(0, 4) << endl;
  cout << "g.path_exists(2, 0): " << boolalpha << g.path_exists(2, 0) << endl;
  cout << "g.path_exists(3, 3): " << boolalpha << g.path_exists(3, 3) << endl;
  cout << "g.path_exists(2, 3): " << boolalpha << g.path_exists(2, 3) << endl;
  cout << "g.path_exists(2, 5): " << boolalpha << g.path_exists(2, 5) << endl;
  cout << "g.path_exists(9, 7): " << boolalpha << g.path_exists(9, 7) << endl;
  cout << "g.path_exists(9, 9): " << boolalpha << g.path_exists(9, 9) << endl;

  return true;
}
bool test_graph_traversal(bool debug){
  graph<int> g = graph_x();
  cout << "------------- depth first -----------------------" << endl;
  cout << "depth first [0]: ";
  depth_first(print_vertex<int>, g, 0);
  cout << endl;
  cout << "depth first [2]: "; depth_first(print_vertex<int>, g, 2); cout<<endl;
  cout << "depth first [5]: "; depth_first(print_vertex<int>, g, 5); cout<<endl;
  cout << ". . . . . . . . . . . . . . . . . . " << endl;
  cout << "depth first [0]: "<< depth_first(do_nothing<int>, g, 0)<<endl;
  cout << "depth first [2]: "<< depth_first(do_nothing<int>, g, 2)<<endl;
  cout << "depth first [5]: "<< depth_first(do_nothing<int>, g, 5)<<endl;

  cout << "------------- breadth first -----------------------" << endl;
  cout << "breadth first [0]: "; breadth_first(print_vertex<int>, g, 0);
  cout << endl;
  cout << "breadth first [2]: "; breadth_first(print_vertex<int>, g, 2); cout<<endl;
  cout << "breadth first [5]: "; breadth_first(print_vertex<int>, g, 5); cout<<endl;
  cout << ". . . . . . . . . . . . . . . . . . " << endl;
  cout << "breadth first [0]: "<< breadth_first(do_nothing<int>, g, 0)<<endl;
  cout << "breadth first [2]: "<< breadth_first(do_nothing<int>, g, 2)<<endl;
  cout << "breadth first [5]: "<< breadth_first(do_nothing<int>, g, 5)<<endl;
  return true;
}
bool test_wgraph_dijkstra(bool debug){
  wgraph<int> wg = wgraph_x();
  cout << wg << endl;

  for (int source = 0; source < wg.size(); source++){
    for (int target = 0; target < wg.size(); target++){
      vector<int> path = wg.shortest_path(source, target);
      if (path.size()!=0){
        cout << "path from " << source << " to " << target << ": " << path << endl;
      }
    }

  }
    return true;
}


TEST(Template_Function_Argument_Demo, TemplateFunctionArgumentDemo) {
  
  //EXPECT_EQ(1, <your individual test functions are called here>);

  EXPECT_EQ(1, template_function_argument_demo(false));
}



TEST(Test_Graph, TestGraphPRINT) {
  
  //EXPECT_EQ(1, <your individual test functions are called here>);

  EXPECT_EQ(1, test_graph_basic(false));
}

TEST(Test_Graph, TestGraphPathExists) {
  
  //EXPECT_EQ(1, <your individual test functions are called here>);

  EXPECT_EQ(1, test_graph_path_exists(false));
}

TEST(Test_Graph, Test_Graph_Traversal) {
  
  //EXPECT_EQ(1, <your individual test functions are called here>);

  EXPECT_EQ(1, test_graph_traversal(false));
}

TEST(Test_WGraph, TestWGraphDijkstra) {
  
  //EXPECT_EQ(1, <your individual test functions are called here>);

  EXPECT_EQ(1, test_wgraph_dijkstra(false));
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n----------running basic_test.cpp---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}

//------------------------------------------------
//  create graphs
//------------------------------------------------
graph<int> graph_x(){
    //make_graph(): 10 vertices, 12 edges
    graph<int> g;
    for (int i= 0; i<10; i++)
        g.add_vertex(i);

    g.add_edge(4, 0);
    g.add_edge(3, 0);
    g.add_edge(9, 3);
    g.add_edge(6, 2);
    g.add_edge(4, 5);
    g.add_edge(4, 2);
    g.add_edge(2, 7);
    g.add_edge(8, 7);
    g.add_edge(8, 2);
    g.add_edge(2, 9);
    g.add_edge(0, 7);
    g.add_edge(3, 1);


    return g;
}

wgraph<int> wgraph_x(){
    //make_wgraph(): 10 vertices, 18 edges
    wgraph<int> wg;
    for (int i= 0; i<10; i++)
        wg.add_vertex(i);

    wg.add_edge(2, 2, 3);
    wg.add_edge(3, 6, 14);
    wg.add_edge(0, 1, 17);
    wg.add_edge(3, 5, 8);
    wg.add_edge(1, 0, 6);
    wg.add_edge(8, 0, 7);
    wg.add_edge(3, 2, 3);
    wg.add_edge(9, 8, 18);
    wg.add_edge(2, 6, 11);
    wg.add_edge(2, 9, 17);
    wg.add_edge(5, 4, 20);
    wg.add_edge(7, 8, 5);
    wg.add_edge(7, 1, 10);
    wg.add_edge(6, 5, 18);
    wg.add_edge(7, 7, 17);
    wg.add_edge(9, 5, 20);
    wg.add_edge(7, 4, 12);
    wg.add_edge(4, 8, 5);


    return wg;
}
//------------------------------------------------
//functions to be passed to traversal tourines:
//------------------------------------------------

template <class T>
void print_vertex(T vertex){
    cout<<"["<<vertex<<"] ";
}

template <class T>
void do_nothing(T vertex){
    // cout<<"["<<vertex<<"] ";
}





/*
./includes
└── graphs
    ├── graph.h        //txtbk page 743: Programming Example: Labeled Graph Class
    ├── gtraversals.h  // depth_first() (and rec_dfs() ): Page 762, 
    │                  // breadth_first() : Page 763
    └── wgraph.h       //  Explained in txtbk Page: 764 & Project 5, page 780



----------running basic_test.cpp---------


[==========] Running 5 tests from 3 test suites.
[----------] Global test environment set-up.
[----------] 1 test from Template_Function_Argument_Demo
[ RUN      ] Template_Function_Argument_Demo.TemplateFunctionArgumentDemo
[1] [1] [3] [5] [8] [13] [21] 
[Monday] [Tuesday] [Wednesday] [Thursday] [Friday] 
[       OK ] Template_Function_Argument_Demo.TemplateFunctionArgumentDemo (0 ms)
[----------] 1 test from Template_Function_Argument_Demo (1 ms total)

[----------] 3 tests from Test_Graph
[ RUN      ] Test_Graph.TestGraphPRINT
here is the graph: 
[ 0]---------------------------------------------------------->[ 7]
                  [ 2]---------------------------------------->[ 7]
                  [ 2]---------------------------------------------------------->[ 9]
[ 0]<----------------------[ 3]
         [ 1]<-------------[ 3]
[ 0]<-------------------------------[ 4]
                  [ 2]<-------------[ 4]
                                    [ 4]---->[ 5]
                  [ 2]<-------------------------------[ 6]
                  [ 2]<-------------------------------------------------[ 8]
                                                               [ 7]<----[ 8]
                           [ 3]<-------------------------------------------------[ 9]

size of graph: 10
neighbors of [ 3]: ||   0   1||
neighbors of [ 5]: ||||
neighbors of [ 0]: ||   7||
[       OK ] Test_Graph.TestGraphPRINT (0 ms)
[ RUN      ] Test_Graph.TestGraphPathExists
g.path_exists(0, 4): false
g.path_exists(2, 0): true
g.path_exists(3, 3): true
g.path_exists(2, 3): true
g.path_exists(2, 5): false
g.path_exists(9, 7): true
g.path_exists(9, 9): true
[       OK ] Test_Graph.TestGraphPathExists (0 ms)
[ RUN      ] Test_Graph.Test_Graph_Traversal
------------- depth first -----------------------
depth first [0]: [0] [7] 
depth first [2]: [2] [7] [9] [3] [0] [1] 
depth first [5]: [5] 
. . . . . . . . . . . . . . . . . . 
depth first [0]: {   0   7}
depth first [2]: {   2   7   9   3   0   1}
depth first [5]: {   5}
------------- breadth first -----------------------
breadth first [0]: [0] [7] 
breadth first [2]: [2] [7] [9] [3] [0] [1] 
breadth first [5]: [5] 
. . . . . . . . . . . . . . . . . . 
breadth first [0]: {   0   7}
breadth first [2]: {   2   7   9   3   0   1}
breadth first [5]: {   5}
[       OK ] Test_Graph.Test_Graph_Traversal (0 ms)
[----------] 3 tests from Test_Graph (0 ms total)

[----------] 1 test from Test_WGraph
[ RUN      ] Test_WGraph.TestWGraphDijkstra
[ 0]---->[ 1]  {17}
[ 0]<----[ 1]  { 6}
                  [ 2]<[ 2]  { 3}
                  [ 2]------------------------------->[ 6]  {11}
                  [ 2]---------------------------------------------------------->[ 9]  {17}
                  [ 2]<----[ 3]  { 3}
                           [ 3]------------->[ 5]  { 8}
                           [ 3]---------------------->[ 6]  {14}
                                    [ 4]------------------------------->[ 8]  { 5}
                                    [ 4]<----[ 5]  {20}
                                             [ 5]<----[ 6]  {18}
         [ 1]<-------------------------------------------------[ 7]  {10}
                                    [ 4]<----------------------[ 7]  {12}
                                                               [ 7]<[ 7]  {17}
                                                               [ 7]---->[ 8]  { 5}
[ 0]<-------------------------------------------------------------------[ 8]  { 7}
                                             [ 5]<-------------------------------[ 9]  {20}
                                                                        [ 8]<----[ 9]  {18}

path from 0 to 1: {   1   0}
path from 1 to 0: {   0   1}
path from 2 to 0: {   0   8   9   2}
path from 2 to 1: {   1   0   8   9   2}
path from 2 to 4: {   4   5   6   2}
path from 2 to 5: {   5   6   2}
path from 2 to 6: {   6   2}
path from 2 to 8: {   8   9   2}
path from 2 to 9: {   9   2}
path from 3 to 0: {   0   8   4   5   3}
path from 3 to 1: {   1   0   8   4   5   3}
path from 3 to 2: {   2   3}
path from 3 to 4: {   4   5   3}
path from 3 to 5: {   5   3}
path from 3 to 6: {   6   3}
path from 3 to 8: {   8   4   5   3}
path from 3 to 9: {   9   2   3}
path from 4 to 0: {   0   8   4}
path from 4 to 1: {   1   0   8   4}
path from 4 to 8: {   8   4}
path from 5 to 0: {   0   8   4   5}
path from 5 to 1: {   1   0   8   4   5}
path from 5 to 4: {   4   5}
path from 5 to 8: {   8   4   5}
path from 6 to 0: {   0   8   4   5   6}
path from 6 to 1: {   1   0   8   4   5   6}
path from 6 to 4: {   4   5   6}
path from 6 to 5: {   5   6}
path from 6 to 8: {   8   4   5   6}
path from 7 to 0: {   0   8   7}
path from 7 to 1: {   1   7}
path from 7 to 4: {   4   7}
path from 7 to 8: {   8   7}
path from 8 to 0: {   0   8}
path from 8 to 1: {   1   0   8}
path from 9 to 0: {   0   8   9}
path from 9 to 1: {   1   0   8   9}
path from 9 to 4: {   4   5   9}
path from 9 to 5: {   5   9}
path from 9 to 8: {   8   9}
[       OK ] Test_WGraph.TestWGraphDijkstra (0 ms)
[----------] 1 test from Test_WGraph (0 ms total)

[----------] Global test environment tear-down
[==========] 5 tests from 3 test suites ran. (1 ms total)
[  PASSED  ] 5 tests.

*/