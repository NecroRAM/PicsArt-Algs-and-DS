#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using std::vector;
using std::stack;

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
	void bfs(int s)
	{
		std::queue<int> q;
		std::vector<bool> visited(adj.size(), false);
		q.push(s);
		visited[s] = true;

		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			for (int v : adj[u])
				if (!visited[v])
				{
					q.push(v);
					visited[v] = true;
				}
		}
	}
	void dfsRecHelper(vector<bool>& visited, const int s)
	{
		visited[s] = true;
		for (auto v : adj[s])
			if (!visited[v])
				dfsRecHelper(visited, v);
	}
	void dfsRecursive(const int s)
	{
		vector<bool> visited(adj.size());
		dfsRecHelper(visited, s);
	}
	void dfsIterative(const int s)
	{
		stack<int> toVisit;
		vector<bool> visited(adj.size());
		int u = 0;

		toVisit.push(s);
		visited[s] = true;
		while (toVisit.empty())
		{
			u = toVisit.top();
			toVisit.pop();
			for (int v : adj[u])
				if (!visited[v])
				{
					toVisit.push(v);
					visited[v] = true;
				}
		}
	}
	int dfsCountHelper(vector<bool>& visited, const int s, const int d)
	{
		if (s == d)
			return 1;
		for (int v : adj[s])
			if (!visited[v])
				dfsCountHelper(visited, v, d);
		visited[s] = false;
	}
	int dfsCount(const int s, const int d)
	{
		vector<bool> visited(adj.size());
		return dfsCountHelper(visited, s, d);
	} // WIP!!!

	// not sure below
	bool dfs(std::vector<bool>& visited, std::vector<bool>& recStack, int source, int parent)
	{
		visited[source] = true;
		recStack[source] = true;

		for (auto neigh : adj[source])
		{
			if (!visited[neigh])
			{
				if (dfs(visited, recStack, neigh, source))
					return true;
			}
			else if (neigh != parent)
				return true;
		}
		recStack[source] = false;
		return false;
	}
	bool isCycled()
	{
		std::vector<bool> visited(adj.size(), false);
		std::vector<bool> recStack(adj.size(), false);

		for (auto vertices : adj)
			for (int v : vertices)
				if (!visited[v])
					if (dfs(visited, recStack, v, 0))
						return true;
		return false;
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