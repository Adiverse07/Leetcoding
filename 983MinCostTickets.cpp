#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, int> mem;

    int solve(vector<int> &days, vector<int> &costs, int pos, int reachability)
    {
        if (pos > days.size() - 1)
            return 0; // out of bounds
        if (reachability >= days[pos])
            return solve(days, costs, pos + 1, reachability); // if it is in the range then just go to the next day

        if (mem.count(pos))
            return mem[pos];

        int one = costs[0] + solve(days, costs, pos + 1, days[pos]);
        int seven = costs[1] + solve(days, costs, pos + 1, days[pos] + 6);
        int thirty = costs[2] + solve(days, costs, pos + 1, days[pos] + 29);

        return mem[pos] = min({one, seven, thirty});
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {

        return min({costs[0] + solve(days, costs, 0, days[0]),
                    costs[1] + solve(days, costs, 0, days[0] + 6),
                    costs[2] + solve(days, costs, 0, days[0] + 29)});
    }
};

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};

    Solution sl;

    cout << sl.mincostTickets(days, costs);
}