#include <iostream>
#include <vector>
#include <random>

void bubbleSort(std::vector<int>& v)
{
	int size = v.size();

	while (size--)
		for (int i = 1; i <= size; ++i)
			if (v[i] < v[i - 1])
				std::swap(v[i], v[i - 1]);
}

int main()
{
	std::vector<int> v;

	//get random number
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<int> dist(0, 999);
	//std::cout << dist(rng) << '\n';

	//fill vec with random numbers
	for (int i = 0; i <= 99; ++i)
		v.push_back(dist(rng));

	//print for debugging
	std::cout << "Vector generated:\n";
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';

	bubbleSort(v);

	std::cout << "\n\nVector sorted:\n";
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';
}