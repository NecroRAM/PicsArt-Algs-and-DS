#include <iostream>
#include <vector>
#include <string>
#include <utility>

struct TreeNode
{
	int id_;
	TreeNode* parent_;
	std::vector<TreeNode*> arr_;

	TreeNode(int v, TreeNode* node)
		: id_(v)
		, parent_(node)
	{
	}
	TreeNode()
	{
	}
};

void buildTree(std::vector<std::vector<int>>& graph, TreeNode* node, TreeNode* parent)
{
	for (int v : graph[node->id_])
	{
		if (parent and v == parent->id_)
			continue; 
		TreeNode* child = new TreeNode(v, node);
		node->arr_.push_back(child);
		buildTree(graph, child, node);
	}
}

TreeNode* rootTree(std::vector<std::vector<int>>& graph, TreeNode* root)
{
	TreeNode* root = new TreeNode;
	buildTree(graph, root, nullptr);
	return root;
}

//1) find inDegree
//2) impl Kahn's algorithm principle

bool areIsom(std::vector<std::vector<int>>& g1, std::vector<std::vector<int>>& g2)
{
	std::vector<TreeNode*>& tC1 = getCenters(g1);
	std::vector<TreeNode*>& tC2 = getCenters(g2);
	TreeNode* root1 = buildTree(g1, tC1[0], nullptr);
	std::string s1 = encode(root1);
	for (int id : tC2)
	{
		root2 = buildTree(g2, id);
		std::string s2 = encode(root2);
		if (s1 == s2)
			return true;
	}
	return false;
}

std::string encode(TreeNode* node)
{
	if (!node)
		return "";
	std::vector<std::string> labels;
	for (TreeNode* child : node->arr)
		labels.push_back(encode(child));
	std::sort(labels.begin(), labels.end());
	std::string res = "";
	for (std::string str : labels)
		res += str;
	return "(" + res + ")";
}

//-------------
// APSP
//-------------

void apsp()
{
	/*matrix
	dp
	next*/

	for (u ..v)
		for (v, w : graph[u])
		{
			matrix[u][v] = w;
			if (u == v)
		}
	dp = matrix;


	for (u...v)
		for (v...v)
			if (matrix[u][v] != INT_MAX)
				next[u][v] = v;
}

fw()
{
	initMatrix();
	setupDpNext
		for (k...v)
			for (i...v)
				for (j...v)
					if (dp[i][j] > dp[i][k] + dp[k][j])
					{
						dp[i][j] = dp[i][k] + dp[k][j];
						next[i][j] = next[i][k];
					}
}

query(s, d)
{
	i = s;
	for (; i != d; i = next[i][d])
	{
		if(dp[s][d] == INT_MAX)
			//no answer
		if (next[i][d] == -1)
			throw;
		res.push_back(i);
	}
	res.push_back(dest);
}