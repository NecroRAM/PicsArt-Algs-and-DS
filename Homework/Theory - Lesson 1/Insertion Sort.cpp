#include <iostream>
#include <vector>
#include <random>

void insertionSort(std::vector<int>& v)
{
	int k = 0;
	int i = 0;
	for (int j = 1; j <= v.size() - 1; ++j)
	{
		k = v[j];
		//i = j - 1;
		i = j;

		while (--i >= 0 && v[i] > k)
			v[i + 1] = v[i];
		
		v[i + 1] = k;
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
	
	insertionSort(v);

	std::cout << "\n\nVector sorted:\n";
	for (int i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';
}