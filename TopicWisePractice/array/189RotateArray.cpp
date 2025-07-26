#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

        int n = nums.size();
        if (n == 1)
            return;

        k = k % n;

        vector<int> temp;

        for (int i = n - k; i < n; i++)
        {
            temp.push_back(nums[i]);
        }

        // int last = nums[n - k - 1];

        for (int i = n-k-1; i >= 0; i--)
        {
         nums[i+k] = nums[i];   
        }
        // nums[n - 1] = last;

        for (int i = 0; i < temp.size(); i++)
        {
            nums[i] = temp[i];
        }
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    Solution sl;

    sl.rotate(nums, k);

    for (int e : nums)
        cout << e << " ";
}

//*easy one
/*
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {

      int n = nums.size();

      k = k%n;
      if(n==1) return;
      vector<int> rotated;

      for(int i = n-k;i<n;i++)
      {
        rotated.push_back(nums[i]);
      }

      for(int i =0;i<n-k;i++)
      {
        rotated.push_back(nums[i]);
      }

      for(int i =0;i<n;i++)
      {
        nums[i] = rotated[i];
      }
    }
};
*/