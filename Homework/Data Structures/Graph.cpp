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
	Graph(std::initializer_list<std::vector<int>> list)
		: adj(list)
	{
	}

	// Methods
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
		if (adj.size() <= v) // is this check needed?
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

	int countOfNodesAtAGivenLevel(int s, int level)
	{
		std::queue<int> q;
		std::vector<bool> visited(adj.size(), false);
		int count = 0;
		q.push(s);
		visited[s] = true;
		int u = 0;
		while (!q.empty())
		{
			u = q.front();

			for (int v : adj[u])
				if (!visited[v])
				{
					q.push(v);
					visited[v] = true;					
				}

			q.pop();
			if (level-- == 1)
				return q.size();
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

	void transpose()
	{
		for (int i = 0; i < adj.size(); ++i)
			for (int j = 0; j < adj[i].size(); ++j)
			{
				adj[adj[i][j]][j] = i;
				adj[i][j] = -1;
			}
		for (auto v : adj)
			v.erase(std::remove_if(v.begin(), v.end(), [](int n) { return n == -1; }));
	}

	void shortestPathBFS(std::vector<int>& visited, std::queue<int>& q, std::vector<int> res, int s, int d)
	{
		q.push(s);
		visited[s] = true;
		if (s == d)
			return res.push_back(s);
		s = q.front();
		shortestPathBFS(visited, q, res, s, d);
	}

	std::vector<int> shortestPath(const int s, int d)
	{
		if (d > adj.size() - 1)
			return {};
		if (s == d)
			return { s };

		std::queue<int> q;
		std::vector<int> res, parent(adj.size(), -1);
		std::vector<bool> visited(adj.size(), false);

		q.push(s);
		while (!q.empty())
		{
			int u = q.front();
			for (auto v : adj[u])
			{
				if (!visited[v])
				{
					parent[v] = u;
					if (v == d)
						break;
					visited[v] = true;
					q.push(v);
				}
			}
			q.pop();
		}
		
		while (parent[d] != s)
		{
			res.push_back(d);
			d = parent[d];
		} 
		res.push_back(d);
		d = parent[d];
		res.push_back(d);

		std::reverse(res.begin(), res.end());
		return res;
	}
};

//Required functionality:
// 
//addEdge(u, v) V
//addVertex(u) V
//dfs : iterative, recursive V
//dfs_extraCase
//bfs V
//bfs_extraCase
//transpose V
//shortedPathinUnweightedGraph V
//countOfNodesAtAGivenLevel v
//allPossiblePathsBetween2Vertices

int main()
{
	Graph graph1;
	graph1.addEdge(0, 1);
	graph1.addEdge(0, 2);
	graph1.addEdge(1, 3);
	graph1.addEdge(1, 7);
	graph1.addEdge(2, 6);
	graph1.addEdge(5, 4);
	graph1.addEdge(4, 1);
	graph1.addEdge(3, 9);

	Graph graph2 = 
	{
		{1, 2},         // Vertex 0 is connected to vertices 1 and 2
		{0, 2, 3, 4, 5},      // Vertex 1 is connected to vertices 0, 2, and 3
		{0, 1, 3},      // Vertex 2 is connected to vertices 0, 1, and 3
		{1, 2, 4},      // Vertex 3 is connected to vertices 1, 2, and 4
		{1, 3, 5},         // Vertex 4 is connected to vertices 3 and 5
		{1, 4}             // Vertex 5 is connected to vertex 4
	};

	std::cout << graph2.countOfNodesAtAGivenLevel(0, 1);
	/*int source = 0;
	int destination = 4;

	std::vector<int> path = graph2.shortestPath(source, destination);

	if (path.empty()) {
		std::cout << "No path exists between " << source << " and " << destination << std::endl;
	}
	else {
		std::cout << "Shortest path between " << source << " and " << destination << ": ";
		for (int vertex : path) {
			std::cout << vertex << " ";
		}
		std::cout << std::endl;
	}*/
}