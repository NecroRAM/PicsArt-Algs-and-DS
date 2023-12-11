#include <iostream>
#include <vector>

class SegmentTree
{
private:
	std::vector<int> tree;
	std::vector<int> data;

public:
	void dfs(int start, int end, int pos)
	{
		std::cout << "A";
		/*if (start > end)
			return;
		if (start == end)
		{
			tree[pos] = data[start];
			return;
		}

		int mid = (start + end) / 2;

		dfs(start, mid, 2 * pos + 1);
		dfs(mid + 1, end, 2 * pos + 2);

		tree[pos] = std::min(tree[2 * pos + 1], tree[2 * pos + 2]);*/
	}
};