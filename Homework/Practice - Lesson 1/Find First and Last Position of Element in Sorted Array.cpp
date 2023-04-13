#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// { 0, 1, 2, 3, 4, 5, 5, 5, 6, 7 }
auto lowerBound(const std::vector<int>& v, const int target)
{
	int start = 0;
	int step = 0;
	int count = v.size();

	while (count)
	{
		step = count / 2;
		if (v[start + step] < target)
		{
			start += step + 1;
			count -= step + 1;
		}
		else
			count = step;
	}
	return start;
}

std::vector<int> searchRange(std::vector<int>& v, const int target)
{
	return { lowerBound(v, target), lowerBound(v, target + 1) };
}

int main()
{
	std::vector<int> v;
	int target;
	std::cin >> target;

	//prng
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<int> dist(0, 99);
	//std::cout << dist(rng) << '\n';

	//fill vec with random numbers
	for (int i = 0; i <= 20; ++i)
		v.push_back(dist(rng));

	std::sort(v.begin(), v.end());

	//print for debugging
	std::cout << "Vector generated:\n";
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';

	std::cout << "\nspan: ";

	auto res = searchRange(v, target);
	for (auto x : res)
		std::cout << x << ' ';
}