#include <iostream>
#include <vector>


void dfs(int u, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent, std::vector<std::vector<int>>& bridges, std::vector<std::vector<int>>& graph, int time)
{
    disc[u] = low[u] = time++;
    for (int v = 0; v < graph[u].size(); ++v)
    {
        int connectedVertex = graph[u][v];
        if (disc[connectedVertex] == -1)
        {
            parent[connectedVertex] = u;
            dfs(connectedVertex, disc, low, parent, bridges, graph, time);
            low[u] = std::min(low[u], low[connectedVertex]);
            if (low[connectedVertex] > disc[u])
                bridges.push_back({ u, connectedVertex });
        }
        else if (connectedVertex != parent[u])
            low[u] = std::min(low[u], low[connectedVertex]);
    }

}

std::vector<std::vector<int>> criticalConnections(int n, std::vector<std::vector<int>>& connections)
{
    std::vector<int> disc(n, -1);
    std::vector<int> low(n, INT_MAX);
    std::vector<int> parent(n, -1);
    std::vector<std::vector<int>> bridges;
    std::vector<std::vector<int>> graph(n);

    for (auto& c : connections)
    {
        graph[c[0]].push_back(c[1]);
        graph[c[1]].push_back(c[0]);
    }

    dfs(0, disc, low, parent, bridges, graph, 0);
    return bridges;
}

int main()
{
    int n = 4;
    std::vector<std::vector<int>> con = { {0, 1}, {1, 2}, {2, 0}, {1, 3} };
    auto res = criticalConnections(n, con);
    for (int i = 0; i < res.size(); ++i)
    {
        std::cout << i << ": ";
        for (int j = 0; j < res[i].size(); ++j)
            std::cout << res[i][j] << ' ';
        std::cout << std::endl;
    }

}