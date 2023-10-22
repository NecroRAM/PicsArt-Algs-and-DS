#include <iostream>
#include <vector>
#include <C:\Users\Aram\Documents\PicsArt-Algs-and-DS\PicsArt-Algs-and-DS\Homework\Data Structures\TreeNode.hpp>

// Hierholzer's Algorithm

// Finding Eulerian paths
std::vector<int> findPaths()
{
	for (int i = 0; i < v.size(); ++i)
	{
		outDegree[u] = adjList[u].size();
		for (int v : adjList[u])
			++inDegree[v];
		for (i ... v)
		{
			if (abs(out[i] - in[i] > 1))
				return false;
			else if (inDegree[i] - outDegree[i] == 1)
				++endPoints;
			else if (outDegree[i] - inDegree[i] == 1)
				++startPoints;
		}
		while (outDegree[u] != 0)
		{
			index = --outDegree[u];
			v = graph[u][index];
			dfs(...v);
		}
		path.push_back(u);
	}
}

TreeNode* LCA(TreeNode * left, TreeNode * right)
{

}

