#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long coloredCells(int n)
    {
        long long cc =1;
        for(int i = 1;i<n;i++)
        {
            cc+=4*i;
          
        }
        return cc;

    }
};

int main()
{
    Solution sl;
    int n = 1;

    cout<<sl.coloredCells(n);
}