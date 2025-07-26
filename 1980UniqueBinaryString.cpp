#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string res;
    bool buildNumber(unordered_set<string> numset,string curr, int &n)
    {
        if(curr.size()==n)
        {
            if(numset.count(curr)==0)
            {
                res = curr;
                return true;
            }
            return false;
        }

        curr.push_back('0'); //try 0
        if(buildNumber(numset,curr,n)) return true;
        curr.pop_back();

        //try 1
        curr.push_back('1');
        if(buildNumber(numset,curr,n)) return true;
        curr.pop_back();

        return false;

    }
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums.size();
        unordered_set<string> numbers(nums.begin(),nums.end());
        string curr = "";

        buildNumber(numbers,curr,n);
        return res;
    }
};

int main()
{
    Solution sl;
    vector<string> sArr = {"01","10","11","00"};

    cout<<sl.findDifferentBinaryString(sArr);
}