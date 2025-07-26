#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long distributeCandies(int n, int limit)
    {
        long long ways = 0;

        int minCh1 = max(0, n - 2 * limit);
        int maxCh2 = min(n, limit);

        for (int i = minCh1; i <= maxCh2; i++)
        {
            int N = n - i;
            int maxCh2 = min(N, limit);
            int minCh2 = max(0, N - limit);

            ways+= maxCh2 - minCh2 +1;

        }

        return ways;
    }
};

int main()
{
    Solution sl;

    cout<<sl.distributeCandies(5,2);
}