#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
	using namespace std;

	vector<vector<int>> g{ {1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2} };
	vector<int> mask(g.size());
	queue<int> q;

	while (!q.empty())
	{
		[u, dist, mask] = q.top();
		for (v : g[u])
		{
			newMask = (1 << v) | mask;
			if (newMask == ((1 << n) - 1))
				return dist + 1;
		}
		if (!visited(v, newMask))
			q.push(v, dist + 1, newMask);
	}
	for (int i = 0; i < g.size(); ++i)
	{
		
	}


}