#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {

        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        int prev_end = 0;

        for (int i = 0; i < meetings.size(); i++)
        {

            int start = max(meetings[i][0], prev_end + 1);
            int end = meetings[i][1];
            int len = end - start + 1;

            prev_end = max(prev_end,end);
            days -= max(len,0);

        }
        return days;
    }
};

int main()
{
    Solution sl;
    int days = 10;
    vector<vector<int>> meetings = {{5, 7}, {1, 3}, {9, 10}};

    cout << sl.countDays(days, meetings);
}