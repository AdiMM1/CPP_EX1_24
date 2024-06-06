/*
Adi Megidi
314956608
Adimillersoso@gmail.com
*/

#ifndef GRAPH_HPP
#define GRAPH_HPP
#pragma once
#include <iostream>
#include <vector>

using namespace std;
namespace ariel {

    class Graph {
    private:
        std::vector<std::vector<int>> adjMatrix;


    public:

    //construcor
    Graph();

    const vector <vector<int>>& getadjMatrix() const;
    void loadGraph (const std::vector<std::vector<int>>&matrix);
    void printGraph() const;
    bool isDirected (const Graph& g);
    
        

};    
};

#endif
