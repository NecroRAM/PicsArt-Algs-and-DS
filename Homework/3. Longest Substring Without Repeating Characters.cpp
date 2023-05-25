#include <iostream>
#include <string>
#include <unordered_map>

// sliding window technique
int lengthOfLongestSubstring(std::string s) 
{
    std::unordered_map<char, int> map;
    int left = 0, right = 0, res = 0;
    while (right < s.length())
    {
        ++map[s[right]];
        while (map.at(s[right]) > 1)
        {
            --map[s[left]];
            ++left;
        }
        res = std::max(res, right - left + 1);
        ++right;
    }
    return res;
}

int main()
{
    std::cout 
        << lengthOfLongestSubstring("abcabcbb") << '\n' 
        << lengthOfLongestSubstring("bbbbb") << '\n' 
        << lengthOfLongestSubstring("pwwkew");
}