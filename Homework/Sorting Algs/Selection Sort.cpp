#include <iostream>
#include <vector>
#include <random>

void swapMinElement(std::vector<int>& v, int start = 0)
{
	int indMin = start;

	for (int i = start; i < v.size(); ++i)
		if (v[i] < v[indMin])
			indMin = i;

	if (indMin != start)
		std::swap(v[indMin], v[start]);
}

void selectionSort(std::vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
		swapMinElement(v, i);
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

	selectionSort(v);

	std::cout << "\n\nVector sorted with selection sort:\n";
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';
}