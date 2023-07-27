#include <iostream>
#include <vector>
#include <stack>

class Graph {
    int V;
    std::vector<std::vector<int>> adj;

public:
    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFSUtil(int v, std::vector<bool>& visited, std::vector<int>& component) {
        visited[v] = true;
        component.push_back(v); // Store the current vertex in the component

        for (int i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited, component);
            }
        }
    }

    Graph transpose() {
        Graph g(V);
        for (int v = 0; v < V; ++v) {
            for (int i : adj[v]) {
                g.addEdge(i, v);
            }
        }
        return g;
    }

    void fillOrder(int v, std::vector<bool>& visited, std::stack<int>& Stack) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i]) {
                fillOrder(i, visited, Stack);
            }
        }
        Stack.push(v);
    }

    void printSCCs() {
        std::stack<int> Stack;
        std::vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                fillOrder(i, visited, Stack);
            }
        }

        Graph transposed = transpose();

        std::fill(visited.begin(), visited.end(), false);

        std::vector<int> component;
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();

            if (!visited[v]) {
                transposed.DFSUtil(v, visited, component);

                std::cout << "Strongly connected component:";
                for (int vertex : component) {
                    std::cout << " " << vertex;
                }
                std::cout << std::endl;
                component.resize(0);
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 1);

    std::cout << "Strongly Connected Components:\n";
    g.printSCCs();

    return 0;
}
