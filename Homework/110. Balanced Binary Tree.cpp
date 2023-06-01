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
};