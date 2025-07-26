#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int, int> nge; // 1, 3, 4, 2
        stack<int> st;
        vector<int> res;
        st.push(0);

        for (int num : nums2)
        {
            nge[num] = -1;
        }

        for (int i = 1; i < n2; i++)
        {
            while (!st.empty() && nums2[i] > nums2[st.top()])
            {
                nge[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < n1; i++)
        {
            res.push_back(nge[nums1[i]]);
        }

        return res;
    }
};

int main()
{
    Solution sl;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> res = sl.nextGreaterElement(nums1, nums2);

    for (auto i : res)
    {
        cout << i << " ";
    }
}