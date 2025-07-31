#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        int n = arr.size();
        unordered_set<int> curr;
        unordered_set<int> prev;
        unordered_set<int> result;

        for (int i = 0; i < n; i++)
        {
            for(const int &x : prev) // it is not O(n^2) it is O(n*32), because once the bit is set it cannot be unset
            {                         // and at worst case we will set 1 bit at aa time which gives us at max32 iterations
                curr.insert(x | arr[i]);
                result.insert(x | arr[i]);
            }

            curr.insert(arr[i]);
            result.insert(arr[i]);

            prev = curr;
            curr.clear();
        }

        return result.size();
    }
};

int main()
{
    vector<int> arr = {1, 1, 2};
    Solution sl;

    cout << sl.subarrayBitwiseORs(arr);
}