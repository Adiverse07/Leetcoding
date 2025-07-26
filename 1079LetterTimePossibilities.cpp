#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int buildString(vector<int> freq)
    {
        int ways = 0;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                freq[i]--;
                ways += 1 + buildString(freq);

                freq[i]++;
            }
        }

        return ways;
    }

public:
    int numTilePossibilities(string tiles)
    {
        vector<int> freq(26, 0);
        int n = tiles.size();
        if (n == 1)
            return 1;

        for (char c : tiles)
            freq[c - 'A']++;

        return buildString(freq);
    }
};

int main()
{
    string tiles = "AAB";
    Solution sl;

    cout << sl.numTilePossibilities(tiles);
}