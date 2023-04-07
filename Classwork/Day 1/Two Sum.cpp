#include <iostream>
#include <map>
#include <vector>

int main() //wip
{
	std::vector<int> v{ 2, 7, 11, 15 };
	int target;
	std::cin >> target;
	std::map<int, int> m;
	int size = v.size();
	for (int i = 0; i < size; ++i)
		m.insert(target - v[i], i);

	
	/*for (auto x : m)
		std::cout << x.first << ' ' <<x.second << '\n';*/
}