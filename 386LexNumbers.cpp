#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(int currNum, int n, vector<int> &result)
    {
        if(currNum > n)
        return;

        result.push_back(currNum);

        for(int append = 0;append<=9;append++)
        {
            int newNumber = (currNum*10) + append;
            if(newNumber > n) return;

            solve(newNumber, n , result);
        }
    }
    vector<int> lexicalOrder(int n) {
        
        vector<int> result;
        for(int starnum = 1; starnum<9; starnum++)
        {
            solve(starnum,n,result);
        }

        return result;
    }
};

int main(){
    Solution sl;

    vector<int> res = sl.lexicalOrder(13);

    for(auto e: res)
    cout<<e<<" ";
}