#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {

        int n = prices.size();

        for (int i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                int j = i + 1;

                while (j < n)
                {
                    if (prices[j] <= prices[i])
                    {
                        prices[i] = prices[i] - prices[j];
                        break;
                    }
                    j++;
                }
            }
        }

        return prices;
    }
};

int main()
{
    Solution sl;
    vector<int> prices = {8, 4, 6, 2, 3}; // 8 4 6 3 2

    vector<int> res = sl.finalPrices(prices);

    for (auto i : res)
        cout << i << " ";
}


//OG SOLUTION
/*
class Solution
{
public:
  vector<int> finalPrices(vector<int> &prices)
  {
    int n = prices.size();

    int stack[500];
    int top = 0;

    stack[top] = n - 1;

    vector<int> ans = prices;

    for (int i = n - 2; i >= 0; i--)
    {
      while (top >= 0 && prices[i] < prices[stack[top]]) // the top points to nearest smaller element index
        top--;                                           // This removes indices of elements larger than prices[i], ensuring the stack top points to the nearest smaller or equal element to the right.

      if (top >= 0)
        ans[i] -= prices[stack[top]]; // nearest smaller element taken as discount

      top++;
      stack[top] = i;
    }
    return ans;
  }
};
*/