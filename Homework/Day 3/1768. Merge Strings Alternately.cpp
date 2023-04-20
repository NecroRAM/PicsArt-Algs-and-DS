class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int length = max(word1.length(), word2.length());
        string res {""};
        auto it1 = word1.begin(), it2 = word2.begin();
        while (length--) 
        {
            if (it1 != word1.end())
                res.push_back(*it1++);
            if (it2 != word2.end())
                res.push_back(*it2++);
        }   
        return res;
    }
};