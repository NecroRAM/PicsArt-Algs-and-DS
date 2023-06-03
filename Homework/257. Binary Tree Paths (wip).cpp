class Solution {
public:
    std::string dfs(TreeNode* root, std::vector<string>& vs)
    {
        string s{};
        s.append(root->val);
        if (!root)
            return string;
        if (!root->left and !root->right)
            vs.push_back(s);
        else
            s.append("->");
    }
    std::vector<string> binaryTreePaths(TreeNode* root) 
    {
        std::vector<string> vs;
        return dfs(root, vs);
    }
};