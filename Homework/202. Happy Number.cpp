class Solution {
public:

    int getNext(int n)
    {
        int res = 0;
        while (n)
        {
            res += (n % 10) * (n % 10);
            n /= 10;
        }
        return res;
    }

    bool isHappy(int n) 
    {
        unordered_map<int, int> map;
        while (n != 1)
        {
            map[n];
            n = getNext(n);
            if (map.count(n))
                return false;
        }
        return true;
    }
};