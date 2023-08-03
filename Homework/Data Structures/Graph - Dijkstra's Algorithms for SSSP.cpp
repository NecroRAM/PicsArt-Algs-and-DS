#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

// Data structure to represent edges and their weights
struct Edge {
    int _to;
    int _weight;
    
    Edge()
    {}

    Edge(int source, int weight)
        : _to(source)
        , _weight(weight)
    {}
};

// Dijkstra's algorithm implementation
vector<int> dijkstra(const vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<int> distances(n, INF);
    distances[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();

        if (dist_u > distances[u]) {
            // Ignore outdated entries in the priority queue
            continue;
        }

        for (const Edge& edge : graph[u]) {
            int v = edge._to;
            int weight = edge._weight;

            if (dist_u + weight < distances[v]) {
                distances[v] = dist_u + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }

    return distances;
}

vector<int> dij(const vector<vector<Edge>>& graph, int source) 
{
    vector<bool> vis(graph.size(), false);
    vector<int> dist(graph.size(), INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq;
    pq.emplace(pair(source, 0));
    Edge edge;
    while (!pq.empty())
    {
        edge._to = pq.top().first;
        edge._weight = pq.top().second;
        pq.pop();
        vis[edge._to] = true;
        for (auto& e : graph[edge._to])
        {
            if (!vis[e._to])
            {
                int newDist = dist[edge._to] + e._weight;
                if (newDist < dist[e._to])
                {
                    dist[e._to] = newDist;
                    pq.emplace(pair(e._to, newDist));
                }
            }
        }
    }
    return dist;
}

// Example usage:
int main() {
    int n = 6; // Number of vertices
    vector<vector<Edge>> graph(n);

    // Adding edges to the graph
    graph[0].push_back({ 1, 5 }); // Edge from node 0 to node 1 with weight 5
    graph[0].push_back({ 2, 3 }); // Edge from node 0 to node 2 with weight 3
    graph[1].push_back({ 2, 2 }); // Edge from node 1 to node 2 with weight 2
    graph[1].push_back({ 3, 6 }); // Edge from node 1 to node 3 with weight 6
    graph[2].push_back({ 3, 7 }); // Edge from node 2 to node 3 with weight 7
    graph[2].push_back({ 4, 4 }); // Edge from node 2 to node 4 with weight 4
    graph[3].push_back({ 4, 1 }); // Edge from node 3 to node 4 with weight 1
    graph[3].push_back({ 5, 11 }); // Edge from node 3 to node 5 with weight 11
    graph[4].push_back({ 5, 8 }); // Edge from node 4 to node 5 with weight 8

    int source = 0;
    //vector<int> distances = dijkstra(graph, source);
    vector<int> distances = dij(graph, source);

    cout << "Shortest distances from node " << source << " to all other nodes:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Distance to node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
