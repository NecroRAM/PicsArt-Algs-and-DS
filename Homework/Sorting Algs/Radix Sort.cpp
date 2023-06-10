#include <iostream>
#include <vector>
#include <random>

void radixSort(std::vector<int>& v)
{
	if (!v.empty())
	{
		int max = *std::max_element(v.begin(), v.end());

		int elBeingSorted = 0;
		int elLeftInd = 0;
		int ratio = 10;

		while (max)
		{
			for (int i = 1; i < v.size(); ++i) // 3 5 1 8 2 4 2 6
			{
				elBeingSorted = v[i];
				elLeftInd = i;

				while (--elLeftInd >= 0 && v[elLeftInd] > elBeingSorted % ratio)
					v[elLeftInd + 1] = v[elLeftInd];

				v[elLeftInd + 1] = elBeingSorted;
			}
			max /= 10;
			ratio *= 10;
		}
	}
	else
		std::cout << "array empty\n";
}

int main()
{
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
	//for (int i = 0; i < v.size(); ++i)
	//	std::cout << v[i] << ' ';

	//radixSort(v);

	//std::cout << "\n\nVector sorted with radix sort:\n";
	//for (int i = 0; i < v.size(); ++i)
	//	std::cout << v[i] << ' ';
}
