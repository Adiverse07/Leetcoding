#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {

        int n = s.size();
        string res;
        vector<int> diff(n + 1, 0);

        for (auto shift : shifts)
        {
            if (shift[2] == 1)
            {
                diff[shift[0]]++;
                diff[shift[1] + 1]--;
            }
            else
            {
                diff[shift[0]]--;
                diff[shift[1] + 1]++;
            }
        }

        for (int i = 1; i <= n; i++)
            diff[i] += diff[i - 1];

        for (int i = 0; i < n; i++)
        {
            int count = diff[i] % 26;

            if (count < 0)
                count = count + 26;

            char curr = char((s[i] - 'a' + count) % 26 + 97);
            res.push_back(curr);
        }
        return res;
    }
};

int main()
{
    string s = "abc";
    vector<vector<int>> shifts = {{0, 1, 0}, {1, 2, 1}, {0, 2, 1}};
    Solution sl;

    cout << sl.shiftingLetters(s, shifts);
}