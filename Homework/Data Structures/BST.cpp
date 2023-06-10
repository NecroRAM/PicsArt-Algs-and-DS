#include <iostream>
#include <stack>

template <typename T>
struct TreeNode
{
	T val;
	TreeNode* left, * right;

	TreeNode(T p_val, TreeNode<T>* p_left = nullptr, TreeNode<T>* p_right = nullptr)
		: val(p_val)
		, left(p_left)
		, right(p_right)
	{
	}
};

template <typename T>
class BST
{
private:
	TreeNode<T>* m_root;
	std::size_t m_size;
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
public:
	// Constructor
	BST() 
		: m_root(nullptr)
		, m_size(0) 
	{
	}

	// Initializer list constructor
	BST(std::initializer_list<T> values) 
	{
		for (const T& val : values)
		{
			m_root = insert(m_root, val);
		}
	}

	// Methods
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
		return node;
	}
	TreeNode<T>* remove(TreeNode<T>* node, T p_val)
	{
		if (!node)
			return node;
		if (p_val < node->val) // step 2
			node->left = remove(node->left, p_val);
		else if (p_val > node->val) // step 1
			node->right = remove(node->right, p_val);
		else
		{
			if (!node->left) // step 3
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
	void clear()
	{
		std::stack<TreeNode<T>*> s;
		TreeNode<T>* node = m_root, *tmp = nullptr;
		while (node or !s.empty())
		{
			while (node)
			{
				s.push(node);
				node = node->left;
			}
			node = tmp = s.top();
			s.pop();
			node = node->right;
			delete tmp;
		}
		m_root = nullptr;
		m_size = 0;
	}
};

int main() 
{
	BST<int> bst{ 2, 1, 4, 5, 3, 10, 9, 9 };
	std::cout << "Recursive:\n";
	bst.traverseRecursive();
	std::cout << '\n';
	std::cout << "Iterative:\n";
	bst.traverseIterative();
	std::cout << '\n';
	std::cout << "Size:\n";
	std::cout << bst.size();
	std::cout << '\n';
	std::cout << "Remove 3:\n";
	bst.remove(bst.root(), 3);
	std::cout << "Iterative:\n";
	bst.traverseIterative();
	std::cout << '\n';
	std::cout << "Recursive:\n";
	bst.traverseRecursive();
	std::cout << '\n';
	std::cout << "Size:\n";
	std::cout << bst.size();
	std::cout << '\n';
	std::cout << "Clear:\n";
	bst.clear();
	std::cout << "Root val:\n";
	std::cout << bst.root()->val;
	std::cout << '\n';
	std::cout << "Size:\n";
	std::cout << bst.size();
	std::cout << '\n';
	std::cout << "Recursive:\n";
	bst.traverseRecursive();
}