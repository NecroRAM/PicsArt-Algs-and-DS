#include <iostream>
#include <string>

//unsigned int hash_func_1a(std::string s)
//{
//	uint32_t hash = 2166136261;
//	for (char c : s)
//	{
//		hash ^= c;
//		hash *= 167777613;
//	}
//	return hash;
//}

template <typename T>
struct TreeNode
{
	TreeNode* left, * right;
	T val;
};

template <typename T>
class BST
{
private:
	TreeNode* root;
	std::size_t size;
public:
	bool searchRec(TreeNode* root, T target)
	{
		if (!root)
			return false;
		if (root->val == target)
			return true;
		if (root->val > target)
			return searchRec(root->left, target)
		else
			return searchRec(root->right, target);
	}

	bool searchIter(TreeNode* root, T target)
	{
		while (root && val != root->val)
		{
			if (root->val < target)
				root = root->right;
			else
				root = root->left;
		}
		return root;
	}

	TreeNode* insert(T val)
	{
		auto cur = root;
		while (cur and (cur->left or cur->right))
		{
			if (val < cur->val)
				cur = cur->left;
			if (val >= cur->val)
				cur = cur->right;
		}
		if (val < cur->val)
			cur->left = new TreeNode(val);
		else
			cur->right = new TreeNode(val);
		return (cur->left ? cur->left : cur->right);
	}
};

int main()
{
	
}