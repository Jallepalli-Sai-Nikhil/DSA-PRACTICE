#include <iostream>
#include <vector>
using namespace std;

class DirectedGraph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    // Constructor to initialize the graph with V vertices
    DirectedGraph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add a directed edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v); // Add directed edge from u to v
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
    DirectedGraph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0); // This makes it cyclic

    g.printGraph();

    return 0;
}
