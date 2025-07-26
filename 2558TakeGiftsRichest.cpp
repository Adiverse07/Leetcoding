#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {

        priority_queue<int> maxheap(gifts.begin(),gifts.end());

        while (k > 0)
        {
          int max = maxheap.top();
          maxheap.pop();
          
          maxheap.push(sqrt(max));

            k--;
        }

        long long sum = 0;
       
       while(!maxheap.empty())
       {
        sum+=maxheap.top();
        maxheap.pop();
       }

        return sum;
    }
};

int main()
{
    vector<int> gifts = {25, 64, 9, 4, 100};
    int k = 4;
    Solution sl;
    cout << sl.pickGifts(gifts, k);

    return 0;
}