#include <iostream>
#include <vector>

using namespace std;

vector<int> row{ 1, -1, 0, 0 };
vector<int> col{ 0, 0, -1, 1 };

int dfs(int prev, long int i, long int j, long int m, long int n, vector<vector<long int>>& dp, vector<vector<long int>>& matrix)
{
    if (i >= m or j >= n or i < 0 or j < 0 or prev <= matrix[i][j])
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
   int sum = 1;

    for (int k = 0; k < 4; ++k)
    {
        long int ni = i + row[k];
        long int nj = j + col[k];
        sum = max(sum, dfs(matrix[i][j], ni, nj, m, n, dp, matrix) + 1);
    }
    return dp[i][j] = sum;
}
int longestIncreasingPath(vector<vector<long int>>& matrix)
{
    long int m = matrix.size();
    long int n = matrix[0].size();
    vector<vector<long int>> dp(matrix.size(), vector<long int>(matrix[0].size(), -1));
    int res = 0;
    for (long int i = 0; i < matrix.size(); ++i)
        for (long int j = 0; j < matrix[i].size(); ++j)
            res = max(res, dfs(INT_MAX, i, j, m, n, dp, matrix));
    return res;
}

int main()
{
    vector<vector<long int>> matrix = { {2147483647, 1} };
    cout << longestIncreasingPath(matrix);
}
