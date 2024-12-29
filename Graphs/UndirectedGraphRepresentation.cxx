#include <iostream>
#include <vector>

// FOR UNDIRECTED GRAPH
int main() {
    // ADJACENCY MATRIX
    int nodes, edges;
    std::cin >> nodes >> edges;
    int adjacencyMat[nodes+1][nodes+1] = {0};
    // entire graph stored here!
    for(int i = 0; i < edges; i++) {
        int u,v;
        std::cin >> u >> v;
        adjacencyMat[u][v] = 1;
        adjacencyMat[v][u] = 1;
    }

    //ADJACENCY LIST
    std::vector<std::vector<int>> adjacencyList(nodes + 1);
    for(auto i = 1; i <= nodes; i++) {
        int u,v;
        std::cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    

    return 0;
}
