#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void countingSort(std::vector<int>& v)
{
	if (!v.empty())
	{
		int max = *std::max_element(v.begin(), v.end());
	
		std::vector<int> count(max + 1, 0);
		for (auto x : v)
			++count[x];
		for (int i = 1; i <= max; ++i)
			count[i] += count[i - 1];
		std::vector<int> tmp(v.size());
		for (int i = v.size() - 1; i >= 0; --i)
			tmp[--count[v[i]]] = v[i];
		for (int i = 0; i < v.size(); ++i)
			v[i] = tmp[i];
	}
}

int main()
{
	std::vector<int> v;

	//get random number
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<int> dist(0, 9);
	//std::cout << dist(rng) << '\n';

	//fill vec with random numbers
	for (int i = 0; i <= 9; ++i)
		v.push_back(dist(rng));

	//print for debugging
	std::cout << "Vector generated:\n";
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';	
	
	countingSort(v);

	std::cout << "\n\nVector sorted:\n";
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';
}