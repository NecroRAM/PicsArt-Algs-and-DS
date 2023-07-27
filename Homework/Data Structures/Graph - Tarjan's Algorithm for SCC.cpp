#include <iostream>
#include <vector>
#include <stack>

class Graph {
    int V;
    std::vector<std::vector<int>> adj;
    std::vector<int> ids;
    std::vector<int> low;
    std::vector<bool> onStack;
    std::stack<int> stk;
    int id;
    std::vector<std::vector<int>> scc;

public:
    Graph(int v) : V(v), adj(v), ids(v, -1), low(v, -1), onStack(v, false), id(0) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int v) {
        stk.push(v);
        onStack[v] = true;
        ids[v] = low[v] = id++;

        for (int w : adj[v]) {
            if (ids[w] == -1) 
                DFS(w);
            if (onStack[w]) 
                low[v] = std::min(low[v], ids[w]);
        }

        if (low[v] == ids[v]) {
            std::vector<int> component;
            int w;
            do {
                w = stk.top();
                stk.pop();
                onStack[w] = false;
                component.push_back(w);
            } while (w != v);

            scc.emplace_back(component);
        }
    }

    std::vector<std::vector<int>> tarjansSCC() {
        for (int i = 0; i < V; ++i) {
            if (ids[i] == -1) {
                DFS(i);
            }
        }
        return scc;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    std::vector<std::vector<int>> scc = g.tarjansSCC();

    std::cout << "Strongly Connected Components:\n";
    for (const auto& component : scc) {
        std::cout << "Strongly connected component:";
        for (int vertex : component) {
            std::cout << " " << vertex;
        }
        std::cout << std::endl;
    }

    return 0;
}
