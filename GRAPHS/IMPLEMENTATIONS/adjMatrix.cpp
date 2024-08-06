#include <iostream>
#include <vector>
using namespace std;

class UndirectedGraph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix

public:
    // Constructor to initialize the graph with V vertices
    UndirectedGraph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0)); // Initialize with 0 (no edges)
    }

    // Function to add an edge
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1; // Add edge from u to v
        adjMatrix[v][u] = 1; // Add edge from v to u (undirected)
    }

    // Function to print the adjacency matrix
    void printMatrix() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    UndirectedGraph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    g.printMatrix();

    return 0;
}
