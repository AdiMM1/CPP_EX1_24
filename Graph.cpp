
#include <iostream>

using namespace std;
#include "Graph.hpp"

namespace ariel {
    
    Graph::Graph() {}

    const std::vector <vector<int>>& Graph::getadjMatrix() const{
        return this-> adjMatrix;
     }

    //load graph
    void Graph::loadGraph (const std::vector<std::vector<int>>&matrix){
        size_t numRows = matrix.size();
        size_t numCols = matrix[0].size();
        if (numRows != numCols)
            throw std::invalid_argument("The matrix isn't square matrix");

        adjMatrix = matrix;
    }

    void Graph::printGraph() const {
        for (size_t i=0; i<adjMatrix.size(); i++){
            for (size_t j=0; j<adjMatrix[i].size(); j++){
                cout << adjMatrix [i][j] << " "; 
            }
            cout << endl;
        }
    }

    

    
};