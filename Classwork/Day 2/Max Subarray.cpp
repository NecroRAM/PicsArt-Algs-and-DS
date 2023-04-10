#include <iostream>
#include <vector>

std::vector<int> findMaxSubarray(std::vector<int>& v, int low, int high)
{
	std::vector<int> left, right;
	if (low == high)
		return { low, high, v[low] };
	
	int mid = low + (high - low) / 2;
	left = findMaxSubarray(v, low, mid);
	right = findMaxSubarray(v, mid + 1, high);
	auto cross = findMaxCrossingSubaray(v, low, mid, high);
	if (left[2] >= right[2] && left[2] >= cross[2])
		return left;
	else if (right[2] >= left[2] && right[2] > cross[2])
		return right;
	else
		return cross;
}

int main()
{

}