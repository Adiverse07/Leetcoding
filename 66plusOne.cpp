#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {

        int carry = 1;
        int flag = 0;

        int ld = digits[digits.size() - 1] + 1;
        if (ld > 9)
        {

            digits[digits.size() - 1] = 0;
            for (int i = digits.size() - 2; i >= 0; i--)
            {
                if (digits[i] + carry > 9)
                {
                    digits[i] = 0;
                    carry = 1;
                }
                else
                {
                    digits[i] = digits[i] + carry;
                    carry = 0;
                }
            }
            if (carry == 1)
            {
                digits.insert(digits.begin(), 1);
            }
        }
        else
        {
            digits[digits.size() - 1] = digits[digits.size() - 1] + 1;
        }

        return digits;
    }
};

int main()
{
    Solution sl;
    vector<int> digits = {7, 2, 8, 5, 0, 9, 1, 2, 9, 5, 3, 6, 6, 7, 3, 2, 8, 4, 3, 7, 9, 5, 7, 7, 4, 7, 4, 9, 4, 7, 0, 1, 1, 1, 7, 4, 0, 0, 6};

    vector<int> result = sl.plusOne(digits);

    for (auto e : result)
        cout << e << " ";
}