#include <iostream>
#include <unordered_map>
#include <array>

std::array<int, 2> twoSum(const std::vector<int>& nums, std::unordered_map<int, int>& hash_table, int target)
{
    for (int i = 0; i < nums.size(); i++) 
    {
        int difference = target - nums[i];

        if (hash_table.count(difference)) 
            return { hash_table[difference], i };
        
        hash_table[nums[i]] = i;
    }
    return {};
}

int main()
{
	const std::vector<int> nums{ 2, 7, 11, 15 };
	int target;
    std::unordered_map<int, int> hash_table;
	std::cin >> target;

    auto res = twoSum(nums, hash_table, target);

    if (!res.empty())
        for (auto x : res)
            std::cout << nums[x] << " at index " << x << '\n';
    else
        std::cout << "Not found\n";
}
