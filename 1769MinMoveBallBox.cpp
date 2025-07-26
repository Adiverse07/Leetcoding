#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minOperations(string boxes)
    {
        // Bhai ka approach, Big O(n) square
        //  int n = boxes.size();
        //  vector<int> boxIndexHavingOnes;
        //  vector<int> res;

        // for (int i = 0; i < n; i++)
        // {
        //     if (boxes[i] == '1')
        //     {
        //         boxIndexHavingOnes.push_back(i);
        //     }
        // }

        // if(boxIndexHavingOnes.empty())
        // {
        //     vector<int> res(n,0);
        // }

        // for (int i = 0; i < n; i++)
        // {
        //     int minops = 0;
        //     if (boxes[i] == '0')
        //     {
        //         for (int j = 0; j < boxIndexHavingOnes.size(); j++)
        //         {
        //             minops+=abs(i-boxIndexHavingOnes[j]);
        //         }
        //     }
        //     else
        //     {
        //         for (int j = 0; j < boxIndexHavingOnes.size(); j++)
        //         {
        //             if(boxIndexHavingOnes[j]==i) continue;
        //             minops+=abs(i-boxIndexHavingOnes[j]);
        //         }
        //     }

        //         res.push_back(minops);
        // }
        // return res;

        int n = boxes.size();
        int sum = 0;
        int rightones = 0;

        for (int i = 0; i < n; i++)
        {
            if (boxes[i] == '1')
            {
                sum += i;
                rightones++;
            }
        }
        vector<int> res(n);
        int prefix_sum = 0;
        int leftones = 0;

        for (int i = 0; i < n; i++)
        {
            int moves = sum + prefix_sum;
            res[i] = moves;

            if (boxes[i] == '1')
            {
                leftones++;
                rightones--;
            }

            sum -= rightones;
            prefix_sum += leftones;
        }

        return res;
    }
};

int main()
{
    Solution sl;
    string boxes = "00";

    vector<int> result = sl.minOperations(boxes);
    for (auto i : result)
        cout << i << " ";
}

// 1 1 1 1 0 0 1
// 0 1 2 3 4 5 6
/*
if ball has to be moved from left,  then min_ops = currboxindex   - senderboxindex
if ball has to be moved from right, then min_ops = senderboxindex - currboxindex

*/