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
    TreeNode* dfs(std::vector<int>& nums, int start, int end)
    {
        if (start <= end)
        {
            int mid = (start + end) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = dfs(nums, start, mid);
            node->right = dfs(nums, mid + 1, end);
            return node;
        }
        return nullptr;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        int mid = nums[nums.size() / 2];
        TreeNode* root = new TreeNode(mid);
        int start = 0, end = nums.size() - 1;
        while (start < end)
        {
            int mid = (end - start) / 2;
            root->left = dfs(nums, start, mid);
            root->right = dfs(nums, mid + 1, end);
        }
        return root;
    }
};