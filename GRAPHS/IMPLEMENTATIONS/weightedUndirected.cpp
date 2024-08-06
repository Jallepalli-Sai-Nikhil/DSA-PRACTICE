#include <iostream>
#include <vector>
#include <utility> // For std::pair
using namespace std;

class WeightedUndirectedGraph {
private:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Adjacency list with weights

public:
    // Constructor to initialize the graph with V vertices
    WeightedUndirectedGraph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge with a weight
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight)); // Add edge from u to v
        adjList[v].push_back(make_pair(u, weight)); // Add edge from v to u (for undirected graph)
    }

    // Function to print the adjacency list
    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << ":";
            for (auto &edge : adjList[i]) {
                cout << " -> " << edge.first << " (weight: " << edge.second << ")";
            }
            cout << endl;
        }
    }
};

int main() {
    WeightedUndirectedGraph g(5);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 4, 50);
    g.addEdge(3, 4, 60);

    g.printGraph();

    return 0;
}
