#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> nums = {1,5,4,3,2};
    int n = nums.size();

    int largest = INT_MIN;
    int secondLargest = -1;

    for(int  i  =0;i<n;i++)
    {
        if(nums[i] > largest)
        {
            secondLargest = largest;
            largest = nums[i];
        }
        else if(nums[i] < largest && nums[i] > secondLargest)
        {
            secondLargest = nums[i];
        }
    }



    cout << secondLargest;
}