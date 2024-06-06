#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <vector>

using namespace std;
using namespace ariel;

TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph3 = {
        {0,0,0},
        {0,0,0},
        {0,0,0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isConnected(g) == false);

    vector<vector<int>> graph4 = {
        {0,1,1},
        {1,0,1},
        {1,1,0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph5 = {
        {0, 1, 2, 3, 4}, 
        {1, 0, 2, 3, 4}, 
        {1, 2, 0, 3, 4},
        {1, 2, 3, 0, 4},
        {1, 2, 3, 4, 0}}; 
    g.loadGraph(graph5);
    CHECK(Algorithms::isConnected(g) == true);
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "-1");

    vector<vector<int>> graph3 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 0, 2) == "0->2");

    vector<vector<int>> graph4 = {
        {0, 1, 0, 2}, 
        {0, 0, 1, 0}, 
        {0, 0, 0, 1}, 
        {2, 0, 0, 0}}; 
    g.loadGraph(graph4);
    CHECK(Algorithms::shortestPath(g, 0, 3) == "0->3");

    vector<vector<int>> graph5 = {
        {0, 1, 0, 2, 5}, 
        {0, 0, 1, 0, 1}, 
        {0, 0, 0, 1, 1}, 
        {2, 0, 0, 0, 1}, 
        {5, 0, 0, 0, 0}}; 
    g.loadGraph(graph5);
    CHECK(Algorithms::shortestPath(g, 0, 4) == "0->1->4");
    CHECK(Algorithms::shortestPath(g, 2, 0) == "2->3->0");
}

TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->0");

    vector<vector<int>> graph3 = {
        {0, 2, 0, 0, 4, 7},
        {2, 0, 1, 0, 0, 0}, 
        {0, 1, 0, 3, 0, 0},
        {0, 0, 3, 0, 0, 1}, 
        {4, 0, 0, 0, 0, 0},
        {7, 0, 0, 1, 0, 0}}; 
    g.loadGraph(graph3);
    CHECK(Algorithms::isContainsCycle(g) == "The cycle is: 0->1->2->3->5->0");

    vector<vector<int>> graph4 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0}, 
        {0, 0, 0, 0},
        {0, 0, 0, 0}}; 
    g.loadGraph(graph4);
    CHECK(Algorithms::isContainsCycle(g) == "0");
}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::negativeCycle(g) == 0);

    vector<vector<int>> graph1 = {
        {0, 0, -2, -1}, 
        {-4, 0, 5, 0}, 
        {0, -3, 0, 0}, 
        {0, 1, 0, 0}}; 
    g.loadGraph(graph1);
    CHECK(Algorithms::negativeCycle(g) == 1);
}

TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph4 = {
        {0, -1, 0, 1},
        {1, 0, 1, 0},
        {0, -1, 0, 1},
        {1, 0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2}, B={1,3}");  

    vector<vector<int>> graph5 = {
        {0, 1, 0, 0, 0},
        {1, 0, 3, 0, 0},
        {0, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};  
    g.loadGraph(graph5);
    CHECK(Algorithms::isBipartite(g) == "The graph is bipartite: A={0,2,4}, B={1,3}");  
}

TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
 