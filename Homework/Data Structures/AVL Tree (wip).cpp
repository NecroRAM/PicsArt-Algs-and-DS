#include <iostream>
#include <stack>
#include "D:\Downloads\Courses\Algs and Data Structs\PicsArt-Algs-and-DS\Homework\Data Structures\TreeNode.hpp"

template <typename T>
class AVL
{
private:
	TreeNode<T>* m_root;
	std::size_t m_size;
public:
	// Constructor
	AVL()
		: m_root(nullptr)
		, m_size(0)
	{
	}

	// Initializer list constructor
	AVL(std::initializer_list<T> values)
	{
		for (const T& val : values)
		{
			m_root = insert(m_root, val);
		}
	}

	// Methods
	TreeNode<T>* min_element(TreeNode<T>* node) const
	{
		TreeNode<T>* parent = nullptr;
		while (node)
		{
			parent = node;
			node = node->left;
		}
		return parent;
	}
	TreeNode<T>* max_element(TreeNode<T>* node) const
	{
		TreeNode<T>* parent = nullptr;
		while (node)
		{
			parent = node;
			node = node->right;
		}
		return parent;
	}
	void print(TreeNode<T>* node) const
	{
		std::cout << node->val << ' ';
	}
	TreeNode<T>* root() const
	{
		if (m_root)
			return m_root;
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
		TreeNode<T>* cur = m_root;
		if (!cur)
			return;
		traverseRecursive(cur->left);
		print(cur);
		traverseRecursive(cur->right);
	}
	void traverseIterative(TreeNode<T>* node) const
	{
		std::stack<TreeNode<T>*> s;
		while (node or !s.empty())
		{
			while (node)
			{
				s.push(node);
				print(node);
				node = node->left;
			}
			node = s.top();
			s.pop();
			node = node->right;
		}
	}
	void traverseIterative() const
	{
		TreeNode<T>* cur = m_root;
		std::stack<TreeNode<T>*> s;
		while (cur or !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			print(cur);
			s.pop();
			cur = cur->right;
		}
	}
	TreeNode<T>* successor(TreeNode<T>* node) const
	{
		if (!node)
			return nullptr;
		return min_element(node->right);
	}
	TreeNode<T>* predecessor(TreeNode<T>* node) const
	{
		if (!node)
			return nullptr;
		return max_element(node->left);
	}
	int height(TreeNode<T>* node) const
	{
		if (!node)
			return -1;
		return std::max(height(node->left), height(node->right)) + 1;
	}
	bool searchRecursive(TreeNode<T>* node, T target) const
	{
		if (!node)
			return false;
		if (node->val == target)
			return true;
		if (node->val > target)
			return searchRecursive(node->left, target);
		else
			return searchRecursive(node->right, target);
	}
	bool searchIterative(TreeNode<T>* node, T target) const
	{
		while (node && node->val != target)
			if (node->val < target)
				node = node->right;
			else
				node = node->left;
		return (node ? node->val == target : false);
	}
	bool empty()
	{
		return m_size > 0;
	}
	std::size_t size()
	{
		return m_size;
	}
	int balance_factor(TreeNode<T>* node)
	{
		if (!node)
			return 0;
		return height(node->left) - height(node->right);
	}
	TreeNode<T>* rightRotate(TreeNode<T>* node)
	{
		TreeNode<T>* left = node->left, * right = left->right;
		left->right = node;
		node->left = right;
		return left;
	}
	TreeNode<T>* leftRotate(TreeNode<T>* node)
	{
		TreeNode<T>* right = node->right, * left = right->left;
		right->left = node;
		node->right = left;
		return right;
	}
	TreeNode<T>* insert(TreeNode<T>* node, T p_val)
	{
		if (!node)
		{
			++m_size;
			return new TreeNode<T>(p_val);
		}
		else if (node->val < p_val)
			node->right = insert(node->right, p_val);
		else
			node->left = insert(node->left, p_val);

		int bf = balance_factor(node);

		if (bf > 1 and p_val < node->left->val)
			return rightRotate(node);
		if (bf > 1 and p_val >= node->left->val) 
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		if (bf < -1 and p_val > node->right->val)
			return leftRotate(node);
		if (bf < -1 and p_val <= node->right->val)
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}
		return node;
	}
	TreeNode<T>* remove(TreeNode<T>* node, T p_val)
	{
		if (!node)
			return node;
		if (p_val < node->val)
			node->left = remove(node->left, p_val);
		else if (p_val > node->val)
			node->right = remove(node->right, p_val);
		else
		{
			if (!node->left)
			{
				TreeNode<T>* tmp = node->right;
				delete node;
				--m_size;
				return tmp;
			}
			else if (!node->right)
			{
				TreeNode<T>* tmp = node->left;
				delete node;
				--m_size;
				return tmp;
			}
			TreeNode<T>* tmp = min_element(node->right);
			node->val = tmp->val;
			node->right = remove(node->right, tmp->val);
		}
		return node;
	}
};

int main() 
{
	AVL<int> avl{ 2, 1, 4, 5, 3, 10, 9, 9 };
	avl.traverseRecursive();
	std::cout << '\n';
	avl.traverseIterative();
}