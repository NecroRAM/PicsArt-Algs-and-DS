#include <iostream>
#include <string>
#include <unordered_map>

int longestPalindrome(std::string s) {
    std::unordered_map<int, int> count(58);
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
        ++count[s[i] - 'A'];
    for (auto x : count)
    {
        res += (x.second / 2) * 2;
        if (res % 2 == 0 and x.second % 2 == 1)
            ++res;
    }
    return res;
}

int main()
{
    std::cout << longestPalindrome("abccccdd");
}