#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{

    bool canAssign(ll &mid, vector<int> &candies, ll &k)
    {
        ll count = 0;

        for (auto ele : candies)
        {
            if (ele >= mid)
            {
                count += ele / mid;
            }
        }

        return count >= k;
    }

public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        ll low = 1;
        ll high = *max_element(candies.begin(), candies.end());

        ll mid;

        ll max_candies = 0;

        while (low <= high)
        {
            mid = low + (high - low) / 2;

            if (canAssign(mid, candies, k))
            {
                max_candies = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return max_candies;
    }
};

int main()
{
    vector<int> candies = {5, 8, 6};
    long long k = 3;
    Solution sl;

    cout << sl.maximumCandies(candies, k);
}