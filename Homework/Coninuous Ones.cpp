#include <iostream>
#include <vector>

//prefix and suffix sum
std::vector<int> sum(vector<int>& v, std::vector<int>& res)
{
	std::vector<int> ps = v, ss = v;
	ps[v] = v[0]
	for (int i = 1; i < v.size() - 1; ++i)
	{
		ps[i] = v[i] + v[i - 1];
	}
	ps[v.size() - 1] = 
	for (int i = size() - 1; i >= 0; --i)
	{

	}
}

int main()
{
	std::vector<int> v{ 1, 50, 102, 507, 2030, 3333, 5000 };
	std::vector<int> res;
	cout << sum(v);
}