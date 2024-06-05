Adi Miller
E-mail: adimillersoso@gmail.com
ID: 314956608

# Graph
Graph.

loadGraph
This function loads a graph represented by an adjacency matrix.

printGraph
This function prints the vertices of the graph according to the order in the adjacency matrix.


Algorithms

BFS
The BFS algorithm is a search algorithm used to traverse the nodes of the graph. 
The algorithm starts from the source vertex, laterally checks the vertices after it and updates the array according to the vertices it visited.

isConnected
This function accepts a graph and performs a test using BFS algorithm (Breadth-First Search), whether the graph is connected.
That is, whether it is possible to reach any other vertex in the graph from any particular vertex in the graph.
The function returns true, in case the function is indeed connected and false in case the test failed.

Bellman-Ford
Bellman-Ford algorithm is used to find the shortest path from a certain node to any of the other nodes in the graph.
This algorithm also works when there are edges with negative weight.
The function accepts a graph and a source vertex, and returns true if there is a negative cycle in the graph and false otherwise.

ShortestPath
This function returns the shortest path between 2 given vertices it receives.
The function uses the Belman-Ford algorithm to perform this calculation.

negativeCircle
The function accepts a graph and returns true if there is a negative cycle in the graph, and false if there is no such cycle.
The function uses the Belman-Ford algorithm to perform this calculation.

DFS
The DFS algorithm is used to traverse the graph or search the graph. 
The algorithm starts from the source node and searches the depth of the graph for vertices it has not yet visited.
The algorithm is performed recursively and repeats the process until all the nodes have been "visited".

isContainsCycle
This function checks if there is a circle in the graph.
A circle in the graph starts from a certain vertex, passes through the edges and returns to the same vertex without visiting more than once each of the vertices it passes through (except the starting vertex).
The function returns the path of the circle.

find_Bipartite
The function checks whether the graph can be divided into a bipartite graph by the DFS algorithm.
The function returns true if the division can be performed and false if the graph is not a bipartite.

isBipartite
This function checks with the find_bipartite function whether there is a bipartite partition. 
The function returns the 2 groups if there is a bipartite partition. 
In the case where there is no bipartite partition, the function will return "0".


