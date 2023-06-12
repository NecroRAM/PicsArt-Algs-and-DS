#pragma once

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