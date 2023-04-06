#include <iostream>
#include <vector>
#include <random>

int minElement(std::vector<int>& v, int size)
{
	int indMin = 0;

	for (int i = 1; i < v.size(); ++i)
		if (v[i] < v[indMin])
			indMin = i;
	return indMin;
}

void selectionSort(std::vector<int>& v) // add index ranges for each pass
{
	int size = v.size();

	for (int i = 0; i < size; ++i)
	{
		std::swap(v[minElement(v)], ;
	}
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

	std::cout << "\n\nVector sorted:\n";
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';
}