#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;



int main()
{
	vector<int> v{ 20, 4, 15, 5, 3, 19, 2, 1, 5, 5, 3, 3 };
	std::unordered_map<int, std::pair<int, bool>> hm;

	for (int i = 0; i < v.size(); ++i)
	{
		hm[v[i]];
	}
	int len = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (hm.find(v[i] - 1) != hm.end())
		{

		}

	}
}