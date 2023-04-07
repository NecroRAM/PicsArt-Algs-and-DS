#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> hash_table;
    for (int i = 0; i < nums.size(); i++) {
        int difference = target - nums[i];
        if (hash_table.count(difference)) {
            return { hash_table[difference], i };
        }
        hash_table[nums[i]] = i;
    }
    return {};
}

int main() //wip
{
    std::vector<int> v{ 4, 5, 6, 3, 8, 5, 0, 9 };
    int target;
    std::cin >> target;
    std::cout << twoSum(v, target)[0];


}