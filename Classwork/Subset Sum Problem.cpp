#include <iostream>
#include <vector>

bool ssp(std::vector<int>& arr, int sum, int i)
{
	if (sum == 0) return true;
	if (i == 0) return false;
	if (arr[i] > sum)
		ssp(arr, sum, i - 1);
	return ssp(arr, sum, i - 1) or ssp(arr, sum - arr[i], i - 1);
}
int main()
{

}