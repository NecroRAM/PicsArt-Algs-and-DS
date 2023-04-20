// compare number of missing elements with k and move mid of binary search accordingly
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int start = 0;
        int end = v.size() - 1;
        int mid = 0;

        while (start <= end)
        {
            mid = (start + end) / 2;

            else if (v[mid] - mid - 1 < k)
                start = mid + 1;
            else (v[mid] - mid - 1 > k)
                end = mid - 1;
        }
        return v.end();

    }
};