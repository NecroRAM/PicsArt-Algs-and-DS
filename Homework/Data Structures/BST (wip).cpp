#include <iostream>
#include <stack>

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
	T v_val;
	TreeNode* left, * right;

	TreeNode(T val)
		: v_val(val)
	{
	}
};

template <typename T>
class BST
{
private:
	TreeNode<T>* v_root;
	std::size_t v_size;
	TreeNode<T>* getMin(TreeNode<T>* node) const 
	{
		TreeNode<T>* parent;
		while (node)
		{
			parent = node;
			node = node->left;
		}
		return parent;
	}
	TreeNode<T>* getMax(TreeNode<T>* node) const
	{
		TreeNode<T>* parent;
		while (node)
		{
			parent = node;
			node = node->right;
		}
		return parent;
	}
	void print(TreeNode<T>* node) const
	{
		std::cout << node->v_val << ' ';
	}
public:
	// Constructor
	BST() 
		: v_root(nullptr)
		, v_size(0) 
	{
	}

	// Initializer list constructor
	BST(std::initializer_list<T> values) 
	{
		for (const T& val : values)
		{
			v_root = insert(v_root, val);
			++v_size;
		}
	}

	// Methods
	TreeNode<T>* root() const
	{
		return v_root;
	}
	void traverseRecursive(TreeNode<T>* node) const
	{
		if (!node)
			return;
		traverseRecursive(node->left);
		print(node);
		traverseRecursive(node->right);
	}
	void traverseRecursive() const
	{
		TreeNode<T>* cur = v_root;
		if (!cur)
			return;
		traverseRecursive(cur->left);
		print(cur);
		traverseRecursive(cur->right);
	}
	void traverseIterative(TreeNode<T>* node) const
	{
		TreeNode<T>* cur = node;
		std::stack<TreeNode<T>*> s;
		while (cur or s.empty())
		{
			while (cur)
			{
				s.push(cur);
				print(cur);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
			cur = cur->right;
		}
	}
	void traverseIterative() const
	{
		TreeNode<T>* cur = v_root;
		std::stack<TreeNode<T>*> s;
		while (cur and !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				print(cur);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
			cur = cur->right;
		}
	}
	TreeNode<T>* successor(TreeNode<T>* node) const
	{
		if (!node)
			return nullptr;
		return getMin(node->right);
	}
	TreeNode<T>* predecessor(TreeNode<T>* node) const
	{
		if (!node)
			return nullptr;
		return getMax(node->left);
	}
	int height(TreeNode<T>* node) const
	{
		if (!node)
			return -1;
		return std::max(height(node->left), height(node->right)) + 1;
	}
	bool searchRecursive(TreeNode<T>* root, T target) const
	{
		if (!root)
			return false;
		if (root->v_val == target)
			return true;
		if (root->v_val > target)
			return searchRecursive(root->left, target);
		else
			return searchRecursive(root->right, target);
	}
	bool searchIterative(TreeNode<T>* root, T target) const
	{
		while (root && root->v_val != target)
			if (root->v_val < target)
				root = root->right;
			else
				root = root->left;
		return (root ? root->v_val == target : false);
	}
	TreeNode<T>* insert(TreeNode<T>* node, T val)
	{
		if (!node)
			return new TreeNode<T>(val);
		else if (node->v_val < val)
			node->right = insert(node->right, val);
		else
			node->left = insert(node->left, val);
	}
};

int main() 
{
	BST bst{ 1, 2, 3, 4, 5 };
	bst.traverseRecursive();
	std::cout << '\n';
	bst.traverseIterative();
}