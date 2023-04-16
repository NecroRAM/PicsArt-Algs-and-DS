#include <iostream>
#include <vector>

void merge(std::vector<int>& v, int low, int mid, int high)
{
	int sizeLeft = mid - low + 1;
	int sizeRight = high - mid;
	std::vector<int> left(sizeLeft), right(sizeRight);

	for (int i = 0; i < sizeLeft; ++i)
		left[i] = v[low + i]; // prev: v[p + i - 1]
	for (int i = 0; i < sizeRight; ++i)
		left[i] = v[mid + i];
	for (int k = low, i = 0, j = 0; low < high; ++low)
		if (left[i] <= right[j])
			v[k] = left[i++];
		else
			v[k] = right[j++];
}

void mergeSort(std::vector<int>& v, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		mergeSort(v, p, q);
		mergeSort(v, q + 1, r);
		merge(v, p, q, r);
	}
}

void mergeSortWrapper(std::vector<int>& v)
{
	mergeSort(v, 0, v.size() - 1);
}

int main()
{
	std::vector<int> v{ 5, 2, 4, 7, 1, 3, 2, 6 };

	mergeSortWrapper(v);

	for (auto x : v)
		std::cout << x << ' ';
}