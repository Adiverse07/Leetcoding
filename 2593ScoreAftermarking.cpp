#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

class Solution {
public:
    long long findScore(vector<int>& nums) {

        int n = nums.size();

        priority_queue<pii,vector<pii> , greater<pii>> minheap;

        unordered_set<int> marked_index;

        for(int i=0;i<n;i++)
            minheap.push(make_pair(nums[i],i));

            long long sum =0;

        while(!minheap.empty())
        {
            pii current = minheap.top();
            minheap.pop();

            int value = current.first;
            int index = current.second;

            if(marked_index.count(index))
                continue;

            sum+=value;
            marked_index.insert(index-1);
            marked_index.insert(index);
            marked_index.insert(index+1);
            
        }

        return sum;


    }
};

using namespace std;

int main()
{
    Solution sl;
    vector<int> arr = {2,1,3,4,5,2};

    cout<<sl.findScore(arr);
}