#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k)
{
	std::unordered_map<std::string, int> m;
	for (auto& s : words)
		++m[s];

	for (auto& el : m)
		std::cout << el.first << ": " << el.second << ", ";
	std::vector<std::pair<std::string, int>> strings;
	std::copy(m.begin(), m.end(), std::back_inserter(strings));

	std::sort(strings.begin(), strings.end(), 
	[](std::pair<std::string, int> el1, std::pair<std::string, int> el2)
	{
		return (el1.second == el2.second ? el1.first < el2.first : el1.second > el2.second);
	});
	std::vector<std::string> res;
	int i = 0;
	while (k--)
	{
		res.push_back(strings[i++].first);
	}
	return res;
}

int main()
{
	std::vector<std::string> words = { "the","day","is","sunny","the","the","the","sunny","is","is" };
	auto res = topKFrequent(words, 4);
	std::cout << '\n';
	for (auto& s : res)
		std::cout << s << ", ";
}