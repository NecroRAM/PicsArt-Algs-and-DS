#include <iostream>
#include <vector>
#include <queue>

void addEdge(int u, int v, int weight, std::vector<std::vector<std::pair<int, int>>>& g)
{
	g[u].push_back(std::pair<int, int>(v, weight));
	g[v].push_back(std::pair<int, int>(u, weight)); // Assuming the graph is undirected
}

int dij(std::vector<std::vector<std::pair<int, int>>>& g, int u, int v)
{
	std::priority_queue<std::pair<int, int>> pq;
	std::vector<int> dist(g.size(), INT_MAX);
	std::vector<bool> visited(g.size(), false);

	int curWeight = dist[0] = 0;
	visited[u] = true;
	pq.push(g[u][0]);

	while (!pq.empty())
	{
		u = pq.top().first;
		pq.pop();
		for (auto& ver : g[u]) 
		{
			if (!visited[ver.first])
			{
				visited[ver.first] = true;
				dist[ver.first] = curWeight + std::min(dist[ver.first], pq.top().second);
				curWeight += dist[u];
				pq.push(ver);
			}
		}
	}

	for  ()
}

int main()
{
	std::vector<std::vector<std::pair<int, int>>> g;

	addEdge(0, 1, 3, g);
	addEdge(0, 2, 2, g);
	addEdge(1, 2, 2, g);
	addEdge(2, 3, 3, g);
	addEdge(1, 3, 1, g);
	addEdge(1, 5, 4, g);
	addEdge(2, 6, 5, g);
	addEdge(2, 7, 6, g);
	addEdge(3, 7, 2, g);
	addEdge(5, 7, 1, g);
	addEdge(6, 7, 2, g);


	std::cout << dij(g, 0, 7);
}
