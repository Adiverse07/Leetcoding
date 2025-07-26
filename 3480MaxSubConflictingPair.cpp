#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        long long valid = 0;

        vector<vector<int>> conflictPoints(n + 1);

        for (auto &p : conflictingPairs)
        {
            int maxPoint = max(p[0], p[1]);
            int minPoint = min(p[0], p[1]);

            conflictPoints[maxPoint].push_back(minPoint);
        }

        vector<long long> extra(n + 1, 0);

        int maxConflict = 0;
        int secondMaxConflict = 0;

        for (int end = 1; end <= n; end++)
        {
            for (auto &u : conflictPoints[end]) // check all conflicting points of end
            {
                if (u >= maxConflict)
                {
                    secondMaxConflict = maxConflict;
                    maxConflict = u;
                }
                else if (u > secondMaxConflict)
                {
                    secondMaxConflict = u;
                }
            }

            valid += end - maxConflict;
            extra[maxConflict] += maxConflict - secondMaxConflict;
        }

        return valid + *max_element(begin(extra), end(extra));
    }
};