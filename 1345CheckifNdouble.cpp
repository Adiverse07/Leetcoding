#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr.size();j++)
            {
                if(i!=j && arr[i]==2*arr[j])      //i!=j so that element doesnt compare itself with itself
                {
                    cout<<arr[i]<<" = 2 * "<<arr[j]<<endl;
                    return true;
                }
            }
        }
        return false;
        
    }
};

int main()
{
    Solution s;
    vector<int> arr = {-2,0,10,-19,4,6,-8};

    s.checkIfExist(arr);
}