#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Global variables
vector<vector<int>> graph; // Adjacency list representation of the graph
unordered_set<int> visited; // Set to keep track of visited nodes

void bfs(int start_node) {
    queue<int> q;
    q.push(start_node);
    visited.insert(start_node);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        // Process current node
        cout << "Processing node: " << current_node << endl;

        // Enqueue unvisited neighbors
        for (int neighbor : graph[current_node]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main() {
    int num_nodes, num_edges;
    cout << "Enter the number of nodes and edges in the graph: ";
    cin >> num_nodes >> num_edges;

    // Resize graph
    graph.resize(num_nodes + 1); // Assuming node indices start from 1

    // Take input for edges
    cout << "Enter edges in the format 'node1 node2':" << endl;
    for (int i = 0; i < num_edges; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1); // Assuming undirected graph
    }

    // Start node for BFS
    int root_node;
    cout << "Enter the root node for BFS: ";
    cin >> root_node;

    // Perform BFS
    bfs(root_node);

    return 0;
}
