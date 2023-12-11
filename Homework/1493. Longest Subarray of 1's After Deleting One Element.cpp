#include <iostream>
#include <vector>

using namespace std;

int contOnes(vector<int>& v)
{
	int maxC = 0, curr = 0, zeroC = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] & 1)
			++curr;
		else if (!zeroC and !curr)
			++zeroC;
		else
			curr = 0;
		maxC = max(maxC, curr);
	}
	return maxC;
}

int main()
{
	vector<int> v{ 0,0,1,0,1,1,1,0,1,1 };
	cout << contOnes(v);
}