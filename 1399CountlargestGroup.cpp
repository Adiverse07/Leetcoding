#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDigitSum(int num)
    {
        int sum = 0;

        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
    int countLargestGroup(int n)
    {
        unordered_map<int, int> sumN;
        int count = 0;
        int maxSize = 0;

        for (int i = 1; i <= n; i++)
        {
            int digitsum = findDigitSum(i);
            sumN[digitsum]++;

            if (sumN[digitsum] == maxSize)
            {
                count++;
            }
            else if (sumN[digitsum] > maxSize)
            {
                maxSize = sumN[digitsum];
                count = 1;
            }
        }
        return count;
    }
};

int main()
{
    Solution sl;

    cout << sl.countLargestGroup(13);
}