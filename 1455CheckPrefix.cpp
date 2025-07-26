#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        istringstream stream(sentence);
        string word;
        int index =1;

        while(stream>>word)
        {
            if(word.find(searchWord)==0)
            {
                return index;
            }
            index++;
        }

        return -1;
    }
};

int main()
{
    Solution s;
    string str = "I love eating burger";
    string sw = "burg";

    int foundindex = s.isPrefixOfWord(str, sw);

    if (foundindex != -1)
    {
        cout << "Element found at index: " << foundindex << endl;
    }
    else
    {
        cout << "Element not found!";
    }
}