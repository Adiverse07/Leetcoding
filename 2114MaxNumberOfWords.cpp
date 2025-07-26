#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int n = sentences.size();
        int maxW = 0;

        for (int i = 0; i < n; i++)
        {
            int currW = (count(sentences[i].begin(), sentences[i].end(), ' ') + 1);
            if (maxW < currW)
            {
                maxW = currW;
            }
        }
        return maxW;
    }
};

int main()
{
    vector<string> sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};

    Solution sl;

    cout << sl.mostWordsFound(sentences);
}