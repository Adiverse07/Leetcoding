#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    /*
    Brute Force : 
    int prefixCount(vector<string> &words, string pref)
    {

        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (words[i].find(pref) == 0)
            {
                count++;
            }
        }

        return count;
    }
    */
    
    
    int prefixCount(vector<string> &words, string pref)
    {

        int n = words.size();
        int count = 0;
        int prefLenght = pref.size();

        for (auto const &word : words)
        {
            if (word.size() >= prefLenght && (word.compare(0, prefLenght, pref) == 0))
                count++;
        }

        return count;
    }

    
};

int main()
{
    Solution sl;

    vector<string> words = {"pay", "attention", "practice", "attend"};

    string pref = "at";

    cout << sl.prefixCount(words, pref);
}