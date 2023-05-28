class Solution {
public:
    int firstUniqChar(string s) 
    {
        int a = 0, b = 0;
        for (char c : s)
        {
            if (a & 1 << (c - 'a'))
                b |= 1 << (c - 'a');
            a |= 1 << (c - 'a');
        }
        for (int i = 0; i < s.size(); ++i)
            if (a & 1 << s[i] - 'a' & ~b)
                return i;
        return -1; 

        // int count[26] = {0};
        // for (int i = 0; i < s.size(); ++i)
        //     ++count[s[i] - 'a'];
        // for (int i = 0; i < s.size(); ++i)
        //     if (count[s[i] - 'a'] == 1)
        //         return i;
        // return -1;        
    }
};