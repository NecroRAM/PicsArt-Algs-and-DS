
// use map (for sortedness)
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        int size1 = items1.size();
        int size2 = items2.size();
        int size = max(items1.size(), items2.size());
        vector<vector<int>> ret(size, vector<int>);

        for (int i = 0; i < size1; ++i) // items1 size
        {
            for (int j = 0; j < size2; ++j) // items 1 item size
            {
                if (items1[i][0] == items2[j][0])
                {
                    ret[i][0] = items1[j][0];
                    ret[i][1] = items1[i][1] + items2[j][1];
                }
            }
        }
        return ret;
    }
};