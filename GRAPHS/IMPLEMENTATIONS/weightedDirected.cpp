#include <iostream>
#include <vector>
#include <utility> // For std::pair
using namespace std;

class WeightedDirectedGraph {
private:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adjList; // Adjacency list with weights

public:
    // Constructor to initialize the graph with V vertices
    WeightedDirectedGraph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add a directed edge with a weight
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back(make_pair(v, weight)); // Add directed edge from u to v with weight
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
    WeightedDirectedGraph g(5);

    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 20);
    g.addEdge(2, 3, 30);
    g.addEdge(3, 4, 40);
    g.addEdge(4, 0, 50); // This makes it cyclic

    g.printGraph();

    return 0;
}
