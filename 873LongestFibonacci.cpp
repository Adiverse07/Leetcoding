#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int lenLongestFibSubseq(vector<int> &arr)
//     {
//         //using simulation
//         int n = arr.size();
//         unordered_set<int> values(arr.begin(),arr.end());
//         int longest = 0;

//         for(int i =0;i<n;i++)
//         {
//             for(int j =i+1; j<n;j++)
//             {
//                 int a = arr[i];
//                 int b = arr[j];
//                 int fib_len =2;
//                 while(values.count(a+b)>0)
//                 {
//                     int sum = a+b;
//                     a = b;
//                     b = sum;
//                     fib_len++;

//                 }

//                 if(fib_len>2)
//                 {
//                     longest = max(longest,fib_len);
//                 }
//             }
//         }

//         return longest;
//     }
// };

// optimal
class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n));

        int longest = 0;

        for (int sum = 2; sum < n; sum++)
        {
            int a = 0;
            int b = sum - 1;

            while (a < b)
            {
                if (arr[a] + arr[b] > arr[sum])
                    b--;
                else if (arr[a] + arr[b] < arr[sum])
                    a++;
                else
                {
                    dp[b][sum] = 1 + dp[a][b];
                    longest = max(longest, dp[b][sum]);
                    a++;
                    b++;
                }
            }
        }

        return longest==0 ? 0 : 2+longest;
    }
};

int main()
{
    vector<int> arr = {1, 3, 7, 11, 12, 14, 18};
    Solution sl;

    cout << sl.lenLongestFibSubseq(arr);
}