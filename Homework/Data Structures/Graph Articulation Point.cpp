#include <iostream>
#include <vector>

int time = 0;
std::vector<std::vector<int>> graph;
void dfs(int u, std::vector<int>& disc, std::vector<int>& low, std::vector<int>& parent, std::vector<int>& artPoints)
{
	disc[u] = low[u] = time++; // time is a static variable
	int childCount = 0;
	for (int v : graph[u])
	{
		if (disc[v] != -1)
		{
			parent[v] = u;
			++childCount;
			dfs(v, disc, low, parent, artPoints);
			low[u] = std::min(low[u], low[v]);
			if (parent[u] == -1 and childCount > 1)
				artPoints.push_back(u);
			else if (parent[u] != -1 and low[v] >= disc[u])
				artPoints.push_back(u);
		}
		else if (v != parent[u])
			low[u] = std::min(low[u], low[v]);
	}
}