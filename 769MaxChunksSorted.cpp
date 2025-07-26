#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {

        int n = arr.size();
        int max_seen = 0;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            max_seen = max(max_seen, arr[i]);

            if (max_seen == i)
                count++;
        }
        return count;
    }
};

int main()
{
    Solution sl;
    vector<int> arr = {5,1,2,3,4};

    cout << sl.maxChunksToSorted(arr);
}