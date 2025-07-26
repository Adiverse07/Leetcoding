#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size();

        int black_count = 0;
        int minops = INT_MAX;
        int l = 0, r = 0;
        while (r < n)
        {
            if (blocks[r] == 'B')
            {
                black_count++;
            }
            if (r - l + 1 == k)
            {
                minops = min(minops, k - black_count);
                if (blocks[l] == 'B')
                    black_count--;
                l++;
            }
            r++;
        }

        return minops;
    }
};
// class Solution {
//     public:
//         int minimumRecolors(string blocks, int k) {

//             int n = blocks.size();
//             int l=0;
//             int r = k-1;
//             int minops = INT_MAX;

//             while(r<n)
//             {
//                 int ops = 0;

//                 for(int i = l;i<=r;i++)
//                 {
//                     if(blocks[i]=='W')
//                     ops++;
//                 }
//                 minops = min(minops,ops);
//                 l++;
//                 r++;
//             }
//             return minops;
//         }
//     };

int main()
{
    Solution sl;
    string blocks = "WBBWWBBWBW";
    int k = 7;

    cout << sl.minimumRecolors(blocks, 7);
}