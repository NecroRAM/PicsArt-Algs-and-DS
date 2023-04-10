#include <iostream>
#include <map>
#include <vector>

int main() //wip
{
	std::vector<int> v{ 2, 7, 11, 15 };
	int target;
	std::map<int, int> m;
	std::cin >> target;
	for (int i = 0; i < v.size(); ++i)
	{
		if (!m.count(target - v[i]))
			m.insert(target - v[i], i);
	}

	
	/*for (auto x : m)
		std::cout << x.first << ' ' <<x.second << '\n';*/
}