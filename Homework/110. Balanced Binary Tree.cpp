/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    int height(TreeNode* root)
    {
        if (!root)
            return 0;

        int left = 0, right = 0;
        left = height(root->left);
        right = height(root->right);

        return std::max(left, right) + 1;
    }
    
    int bf(TreeNode* root)
    {
        return (root ? height(root->left) - height(root->right) : 0);
    }

    bool isBalanced(TreeNode* root) 
    {
        if (!root)
            return true;
        else if (abs(bf(root)) <= 1)
            return isBalanced(root->left) and isBalanced(root->right);
        return false;
    }
	
	// alternative
	int dfs(ListNode* root)
	{
		if (!node)
			return 0;
		int leftHeight = dfs(root->left);
		int rightHeight = dfs(root->right);
		if (leftHeoght == -1 or rightHeight == -1 or std::abs(leftHeight - rightHeight) > 1)
			return -1;
		return std::max(leftHeight, rightHeight) + 1;
	}
	
	bool isBalanced(TreeNode* root) 
    {
        if (!root)
            return true;
        return dfs(root) != -1;
};