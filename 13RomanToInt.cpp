#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {

        int n = s.size();
        int sum = 0;
        unordered_map<char, int> romanToInt = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 and (romanToInt[s[i]] < romanToInt[s[i + 1]]))
                sum -= romanToInt[s[i]];
            else
                sum += romanToInt[s[i]];
        }
        return sum;
    }
};

int main()
{
    string s = "LVIII";
    Solution sl;
    cout << sl.romanToInt(s);
}