#include <iostream>
#include <vector>
#include <random>

// overwrite (i + 1)-th element with i-th if v[i] > v[i + 1]
// decrement i
// restore v[i + 1] from a stored value k = v[j] where j was equal to i

void insertionSort(std::vector<int>& v)
{
	int elBeingSorted = 0;
	int elLeftInd = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		elBeingSorted = v[i];
		elLeftInd = i; 

		while (--elLeftInd >= 0 && v[elLeftInd] > elBeingSorted)
			v[elLeftInd + 1] = v[elLeftInd]; 				
	 
		v[elLeftInd + 1] = elBeingSorted;
	}
}

//int main()
//{
//	std::vector<int> v;
//
//	//get random number
//	std::random_device dev;
//	std::mt19937 rng(dev());
//	std::uniform_int_distribution<int> dist(0, 9);
//	//std::cout << dist(rng) << '\n';
//
//	//fill vec with random numbers
//	for (int i = 0; i <= 9; ++i)
//		v.push_back(dist(rng));
//
//	//print for debugging
//	std::cout << "Vector generated:\n";
//	for (int i = 0; i < v.size(); ++i)
//		std::cout << v[i] << ' ';	
//	
//	insertionSort(v);
//
//	std::cout << "\n\nVector sorted:\n";
//	for (int i = 0; i < v.size(); ++i)
//		std::cout << v[i] << ' ';
//}