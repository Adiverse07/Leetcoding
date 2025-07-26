#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    int bestStartingPoint(string &word, int n)
    {
       int i = 0,j = 1;

       while(j  < n)
       {
        int k = 0;


        //skipping equal characters 
        while(j+k < n && word[i+k] == word[j+k])
        {
            k++;
        }

        if(word[j+k] > word[i+k])
        {
            i = j;
            j = j+1;
        }
        else
        {
            j = j + k + 1; //skipping already checked chars
        }
       }

       return i;
    }
    string answerString(string word, int numFriends)
    {

        int n = word.size();
        
        if(numFriends == 1)
        return word;

        int i = bestStartingPoint(word,n);

        int longestPossileLength = n -(numFriends -1);
        int canTakePossible =  min(longestPossileLength, n -i);
        
        return word.substr(i,canTakePossible);
    }
};

int main()
{
    string word = "dbca"; //"gggg;"
    int numFriends = 2;

    Solution sl;

    cout << sl.answerString(word, numFriends);
}