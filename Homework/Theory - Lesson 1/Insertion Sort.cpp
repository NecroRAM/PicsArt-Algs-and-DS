#include <iostream>
#include <vector>
#include <random>

// overwrite (i + 1)-th element with i-th if v[i] > v[i + 1]
// decrement i
// restore v[i + 1] from a stored value k = v[j] where j was equal to i

void insertionSort(std::vector<int>& v)
{
	int k = 0; // C1 = 1
	int i = 0; // C2 = 1
	for (int j = 1; j < v.size(); ++j)
	{
		k = v[j]; // C3 = n - 1
		i = j; // C4 = n - 1

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
	std::uniform_int_distribution<int> dist(0, 9);
	//std::cout << dist(rng) << '\n';

	//fill vec with random numbers
	for (int i = 0; i <= 9; ++i)
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