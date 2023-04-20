#include <iostream>
#include <vector>

void merge(std::vector<int>& v, int left, int mid, int right)
{
	int sizeLeft = mid - left + 1;
	int sizeRight = right - mid;
	std::vector<int> leftPart(sizeLeft), rightPart(sizeRight);

	for (int i = 0; i < sizeLeft; ++i)
		leftPart[i] = v[left + i]; // prev: v[p + i - 1]
	for (int i = 0; i < sizeRight; ++i)
		leftPart[i] = v[mid + i];
	while (left < right)
		if (leftPart[left] <= rightPart[right])
			v[left++] = leftPart[right--];
		else
			v[left++] = rightPart[right--];
}

void mergeSort(std::vector<int>& v, int left, int right)
{
	if (left < right)
	{
		int q = (left + right) / 2;
		mergeSort(v, left, q);
		mergeSort(v, q + 1, right);
		merge(v, left, q, right);
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