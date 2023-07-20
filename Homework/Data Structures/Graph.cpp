#include <iostream>
#include <vector>

using std::vector;

class Graph
{
private:
	vector<vector<int>> adj;
public:
	Graph()
	{
		std::cout << "graph constructed\n";
	}
	Graph(int size)
		: adj(size)
	{
		std::cout << "graph constructed with size" << size << '\n';
	}
	void addEdge(unsigned const int u, unsigned const int v)
	{
		if (adj.size() > u)
			adj[u].push_back(v);
		else
		{
			adj.resize(u + 1);
			adj[u].push_back(v);
		}
		if (adj.size() > v)
			adj[v].push_back(u);
		else
		{
			adj.resize(v + 1);
			adj[v].push_back(u);
		}
	}
	void addVertex(int v)
	{
		if (adj.size() <= v)
			adj.push_back(vector<int> {});
	}
	void dfsRecursive(unsigned const int s)
	{
		vector<bool> visited(adj.size());
	}

	void dfs(int s, int d)
	{
		vector<bool> visited(adj.size());
		visited[s] = true;
		if (s == d)
			return;
		for (auto v : adj[s])
			if (!visited[v])
				dfs(v, d);
		//visited[s] = false;
	}
};

int main()
{
	Graph g;
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 7);
	g.addEdge(2, 6);
	g.addEdge(5, 4);
	g.addEdge(4, 1);
	g.addEdge(3, 9);
}