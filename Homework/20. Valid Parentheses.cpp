#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

bool isValid(std::string s) 
{
    if (s.length() <= 1) 
        return false;
    // Create unordered map
    std::unordered_map<char, char> charMap;
    std::stack<char> charStack;
    charMap.insert({ '}', '{' });
    charMap.insert({ ')', '(' });
    charMap.insert({ ']', '[' });

    // If the first parntheses is a closing bracket
    if (charMap.count(s[0]))
        return false;
    // loop through the string if it's not a closing brack
    // then place it inside the stack
    for (char c : s)
        if (!charMap.count(c)) 
            charStack.push(c);
        else if (!charStack.empty() && charStack.top() == charMap[c]) 
            charStack.pop();
        else
            return false;

    return (charStack.empty() ? true : false);
}

int main()
{
    std::cout << isValid("{[]()}");
}