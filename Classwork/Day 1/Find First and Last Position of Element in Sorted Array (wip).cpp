#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

auto bs_iterative(const std::vector<int>& v, const int val)
{
	int start = 0;
	int end = v.size() - 1;
	int count = 0;

	while (start <= end)
	{
		count = (start + end) / 2;

		if (v[count] == val)
			return v.begin() + count;
		else if (v[count] < val)
			start = count + 1;
		else
			end = count - 1;
	}
	return v.end();
}

auto bs_recursive(const std::vector<int>& v, int start, int mid, int end, int val)
{
	mid = (start + end) / 2;
	if (start > end)
		return v.end();
	if (v[mid] == val)
		return v.begin() + mid;
	else if (v[mid] < val)
		return bs_recursive(v, mid + 1, mid, end, val);
	else
		return bs_recursive(v, start, mid, mid - 1, val);
}

auto bs_recursive_wrapper(const std::vector<int>& v, const int val)
{
	int start = 0;
	int end = v.size() - 1;
	int mid = 0;
	return bs_recursive(v, start, mid, end, val);
}

int main()
{
	std::vector<int> v;
	int val;

	//prng
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<int> dist(0, 9);
	//std::cout << dist(rng) << '\n';

	//fill vec with random numbers
	for (int i = 0; i <= 10; ++i)
		v.push_back(dist(rng));

	std::sort(v.begin(), v.end());

	//print for debugging
	std::cout << "Vector generated:\n";
	for (int i = 0; i <= 10; ++i)
		std::cout << v[i] << ' ';

	int impl;
	std::cout << "\n\nDo you want to call the (1)iterative or the (2)recursive implementation? Enter 1 or 2\n";
	std::vector<int>::const_iterator it;

	while (std::cin >> impl && (impl != 1 && impl != 2))
		std::cout << "Wrong input. Please enter 1 or 2\n";

	while (true)
	{

		std::cout << "Input the search term\n";
		std::cin >> val;
		if (impl == 1)
			it = bs_iterative(v, val);
		else
			it = bs_recursive_wrapper(v, val);

		if (it == v.end())
			std::cout << "Not found\n";
		else
			std::cout << "Found at index: " << std::distance(v.cbegin(), it) << std::endl;
	}
}