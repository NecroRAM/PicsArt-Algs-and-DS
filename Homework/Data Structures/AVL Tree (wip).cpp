#include <iostream>
#include <stack>
#include <queue>
#include <iterator>
#include "C:\Users\Aram\Documents\PicsArt-Algs-and-DS\PicsArt-Algs-and-DS\Homework\Data Structures\TreeNode.hpp"

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
			insert(val);
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
	void levelOrderTraversal() const
	{
		if (!m_root)
			return;

		TreeNode<T>* cur = m_root;
		std::queue<TreeNode<T>*> q;
		int max = 0;
		q.push(cur); 

		while (!q.empty())
		{
			max = cur->val;
			cur = q.front();
			if (max > cur->val)
				std::cout << '\n';
			if (cur->left)
				q.push(cur->left);
			if (cur->right)
				q.push(cur->right);
			print(cur);
			q.pop();
		}
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
	bool empty() const
	{
		return m_size > 0;
	}
	std::size_t size() const
	{
		return m_size;
	}
	int balance_factor(TreeNode<T>* node) const
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
	TreeNode<T>* insertHelper(TreeNode<T>* node, T p_val)
	{
		if (!node)
		{
			++m_size;
			node = new TreeNode<T>(p_val);
			return node;			
		}
		else if (node->val < p_val)
			node->right = insertHelper(node->right, p_val);
		else
			node->left = insertHelper(node->left, p_val);

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
	void insert(T p_val)
	{
		m_root = insertHelper(this->m_root, p_val);
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
			else 
			{
				TreeNode<T>* tmp = min_element(node->right);
				node->val = tmp->val;
				node->right = remove(node->right, tmp->val);
			}
			int bf = balance_factor(node);
			if (bf > 1 and balance_factor(node->left) >= 0)
				return rightRotate(node);
			if (bf > 1 and balance_factor(node->left) < 0)
			{
				node->left = leftRotate(node->left);
				return rightRotate(node);
			}
			if (bf < -1 and balance_factor(node->right) <= 0)
				return leftRotate(node);
			if (bf < -1)
			{
				node->right = rightRotate(node->right);
				return leftRotate(node);
			}
		}
	}
	void clear()
	{
		std::stack<TreeNode<T>*> s;
		TreeNode<T>* node = m_root, * tmp = nullptr;
		while (node or !s.empty())
		{
			while (node)
			{
				s.push(node);
				node = node->left;
			}
			tmp = s.top();
			s.pop();
			node = tmp->right;
			delete tmp;
		}
		m_root = nullptr;
		m_size = 0;
	}

	//class Iterator
	//{
	//private:
	//	TreeNode<T>* cur;
	//public:
	//	using iterator_category = std::bidirectional_iterator_tag;
	//	using value_type = T;
	//	using reference = T&;
	//	using pointer = T*;
	//	using difference_type = std::ptrdiff_t;

	//	// Constructor and operator overloads

	//	// Dereference operators
	//	reference operator*() const;
	//	pointer operator->() const;

	//	// Increment and decrement operators
	//	Iterator& operator++();
	//	Iterator operator++(int);
	//	Iterator& operator--();
	//	Iterator operator--(int);

	//	// Equality and inequality operators
	//	bool operator==(const Iterator& other) const;
	//	bool operator!=(const Iterator& other) const;
	//};

	//// Concept for a valid AVL iterator
	//template <typename Iterator>
	//concept ValidAVLIterator = std::input_or_output_iterator<Iterator> &&
	//	std::convertible_to<typename Iterator::value_type, T>;

	//// Public member functions

	//Iterator begin();
	//Iterator end();

	//// Additional member functions and definitions
};

// Iterator member function definitions

//template <typename T>
//typename AVL<T>::Iterator AVL<T>::begin()
//{
//	return min_element(m_root);
//}
//
//template <typename T>
//typename AVL<T>::Iterator AVL<T>::end()
//{
//	return max_element(m_root);
//}
//
//template <typename T>
//typename AVL<T>::Iterator::reference AVL<T>::Iterator::operator*() const
//{
//	return this->cur->val;
//}
//
//template <typename T>
//typename AVL<T>::Iterator::pointer AVL<T>::Iterator::operator->() const
//{
//	return this->cur;
//}
//
//template <typename T> //WIP!!!!!!
//typename AVL<T>::Iterator& AVL<T>::Iterator::operator++()
//{
//	// Increment the iterator to the next element
//}
//
//template <typename T>
//typename AVL<T>::Iterator AVL<T>::Iterator::operator++(int)
//{
//	// Post-increment the iterator to the next element
//}
//
//template <typename T>
//typename AVL<T>::Iterator& AVL<T>::Iterator::operator--()
//{
//	// Decrement the iterator to the previous element
//}
//
//template <typename T>
//typename AVL<T>::Iterator AVL<T>::Iterator::operator--(int)
//{
//	// Post-decrement the iterator to the previous element
//}
//
//template <typename T>
//bool AVL<T>::Iterator::operator==(const Iterator& other) const
//{
//	// Compare if two iterators are equal
//}
//
//template <typename T>
//bool AVL<T>::Iterator::operator!=(const Iterator& other) const
//{
//	// Compare if two iterators are not equal
//}


int main() 
{
	AVL<int> avl{ 2, 1, 4, 5 };

	std::cout << "\nlevel1:\n";
	avl.levelOrderTraversal();

	std::cout << "\ntrav rec:\n";
	avl.traverseRecursive();

	std::cout << "\ntrav iter:\n";
	avl.traverseIterative();
	std::cout << '\n';

	avl.remove(avl.root(), 4);
	std::cout << avl.size();
	std::cout << '\n';

	std::cout << "\ntrav iter:\n";
	avl.traverseIterative();

	std::cout << '\n';
	std::cout << "\nlevel1:\n";
	avl.levelOrderTraversal();

	avl.clear();
	std::cout << "\ncleared\n";

	std::cout << "\nlevel2:\n";
	avl.levelOrderTraversal();
	if (avl.root())
		std::cout << "root: " << avl.root()->val << '\n';

	for (int i = 0; i < 10; ++i)
		avl.insert(i);

	std::cout << '\n';
	std::cout << "level3:\n";
	avl.levelOrderTraversal();
	std::cout << '\n';
	std::cout << "iter:\n";
	avl.traverseIterative();

}