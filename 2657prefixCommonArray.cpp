#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();

        vector<int> freq(n + 1, 0);
        int common = 0;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
           freq[A[i]]++;
           if(freq[A[i]]==2)
           common++;

           freq[B[i]]++;
           if(freq[B[i]]==2)
           common++;

           res.push_back(common);
        }

        return res;
    }
};

int main()
{
    vector<int> A = {1, 3, 2, 4};
    vector<int> B = {3, 1, 2, 4};
    Solution sl;
    vector<int> res = sl.findThePrefixCommonArray(A, B);
    for (auto i : res)
    {
        cout << i << " ";
    }
}