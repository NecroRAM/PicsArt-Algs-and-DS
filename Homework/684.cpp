class Solution {
public:
    int find(int x, vector<int>& parents)
    {
        if (x == parents[x]) 
            return x;
        return parents[x] = find(parents[x], parents);
    }

    bool unify(int x, int y, vector<int>& parents, vector<int>& ranks)
    {
        x = find(x, parents);
        y = find(y, parents);
        if (x == y) // false condition unclear
            return false;
        if (ranks[x] == ranks[y])
        {
            ++ranks[x];
            parents[y] = x;
        }
        else if (ranks[x] < ranks[y]) 
            parents[x] = y;
        else 
            parents[y] = x;
        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        vector<int> parents(1001), ranks(1001);
        
        for (int i = 0; i < parents.size(); ++i)
            parents[i] = i;
        for (auto& edge : edges)
            if (!unify(edge[0], edge[1], parents, ranks))
                return edge;
        return {};
    }
};