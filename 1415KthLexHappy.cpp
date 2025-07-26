#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getHappyString(int n, int k)
    {
        vector<string> happystrings;
        queue<string> q;

        q.push("a");
        q.push("b");
        q.push("c");

        while (!q.empty())
        {
            string curr = q.front();
            q.pop();

            if (curr.size() == n)
            {
                happystrings.push_back(curr);
                continue;
            }

            string first = curr;
            string second = curr;

            if(curr.back()=='a')
            {
             first.push_back('b');
             second.push_back('c');
            }
            else if (curr.back() == 'b')
            {
                first.push_back('a');
                second.push_back('c');
            }
            else if(curr.back()=='c')
            {
                first.push_back('a');
                second.push_back('b');
            }

            //optimization
            if(happystrings.size()>=k)
            break;

            q.push(first);
            q.push(second);

        }

        if(happystrings.size()<k) return "";

        return happystrings[k-1];
    }
};

int main()
{
    Solution sl;
    int n = 3;
    int k = 9;

    cout<<sl.getHappyString(n,k);

}

//OG approach
/*
class Solution {
    int n2;
    string dfs(string prefix, int n, int k) {
        if (n == 0)
            return prefix;
        for (char c = 'a'; c <= 'c'; c++) {
            if (!prefix.empty() && c == prefix.back())
                continue;
            int cnt = (1 << (n2 - prefix.length() - 1));
            if (cnt >= k)
                return dfs(prefix + c, n - 1, k);
            else
                k -= cnt;
        }
        return "";
    }
public:
    string getHappyString(int n, int k) {
        n2 = n;
        return dfs("", n, k);
    }
};
*/