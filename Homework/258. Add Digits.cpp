class Solution {
public:
    int addDigits(int num) {
        if (num <= 9)
            return num;
        int res = 0;
        while (num)
        {
            res += num % 10;
            num /= 10;
        }
        return addDigits(res);
    }
};