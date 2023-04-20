class Solution {
public:
    string largestMerge(string word1, string word2) 
    {
        auto it1 = word1.begin();
        auto it2 = word2.begin();
        int size = max(word1.size(), word2.size());
        string merge {""};

        while (size--)
        {
            if (*it1 > *it2 && it1 != word1.end())
            {
                merge.push_back(*it1);
                it1 = word1.erase(it1);
            }
            else if (*it1 < *it2 && it2 != word2.end())
            {
                merge.push_back(*it2);
                it2 = word2.erase(it2);
            }
            else if (it1 != word1.end())
            {
                merge.push_back(*it1);
                it1 = word1.erase(it1);
            }
            else if (it2 != word1.end())
            {
                merge.push_back(*it2);
                it2 = word1.erase(it2);
            }
        }

        return merge;
    }
};