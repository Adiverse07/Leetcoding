#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {

        // colors.insert(colors.end(), colors.begin(), colors.end());
        int n = colors.size();
        int l = 0, r = 1;
        int count = 0;

        while (r < (n + (k - 1)))
        {
            if (colors[r % n] == colors[(r - 1) % n])
            {
                l = r;
            }

            if (r - l + 1 > k)
                l++;

            if (r - l + 1 == k)
                count++;

            r++;
        }

        return count;
    }
};

int main()
{
    vector<int> colors = {0, 1, 0, 0, 1, 0, 1};
    int k = 6;
    Solution sl;

    cout << sl.numberOfAlternatingGroups(colors, k);
}