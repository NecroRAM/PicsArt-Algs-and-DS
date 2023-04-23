#include <iostream>
#include <vector>
#include <random>

int partition(std::vector<int>& v, int start, int end)
{
	int pivot = v[end]; // 4, 3, 0, 1, 8, 9, 7, [8
	int i = start;
	for (int j = start; j < end; ++j)
		if (v[j] <= pivot)
		{
			std::swap(v[i], v[j]);
			++i;
		}
	std::swap(v[i], v[end]);
	return i;
}

void quickSortWrap(std::vector<int>& v, int start, int end)
{
	if (start < end)
	{
		int pivotI = partition(v, 0, v.size() - 1);
		quickSortWrap(v, start, pivotI - 1);
		quickSortWrap(v, pivotI + 1, end);
	}
}

void quickSort(std::vector<int>& v)
{
	quickSortWrap(v, 0, v.size() - 1);
}

int main()
{
	std::vector<int> v2{ 4, 7, 8, 3, 0, 9, 1, 5 };

	quickSort(v2);
	for (auto x : v2)
		std::cout << x << ' ';
	//std::vector<int> v;

	////get random number
	//std::random_device dev;
	//std::mt19937 rng(dev());
	//std::uniform_int_distribution<int> dist(0, 999);
	////std::cout << dist(rng) << '\n';

	////fill vec with random numbers
	//for (int i = 0; i <= 99; ++i)
	//	v.push_back(dist(rng));

	////print for debugging
	//std::cout << "Vector generated:\n";
	//for (auto x : v)
	//	std::cout << x << ' ';


	/*std::cout << "\n\nVector sorted with quick sort:\n";
	for (auto x : v)
		std::cout << x << ' ';*/
}