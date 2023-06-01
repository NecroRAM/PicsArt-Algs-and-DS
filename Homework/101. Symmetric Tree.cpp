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
class Solution {
public:
    bool checker(TreeNode* left, TreeNode* right)
    {
        if (left and right and left->val == right->val)
        {
            return checker(left->left, right->right) and checker(left->right, right->left);
        }
        else if (!right and !left)
            return true;
        else
            return false;
    }

    bool isSymmetric(TreeNode* root) 
    {
        return (!root ? true : checker(root->left, root->right));
    }
};