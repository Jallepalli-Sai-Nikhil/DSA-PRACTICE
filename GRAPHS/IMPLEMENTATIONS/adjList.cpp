#include <iostream>
#include <vector>
using namespace std;

// Define a class for the graph
class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add v to u's list
        adjList[v].push_back(u); // Add u to v's list (for undirected graph)
    }

    // Function to print the adjacency list
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ":";
            for (int j : adjList[i]) {
                cout << " -> " << j;
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    // Print the graph
    g.printGraph();

    return 0;
}
