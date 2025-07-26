#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        vector<string> splited;
        string temp = "";
        

        for (int i = 0; i <= sentence.size(); i++)
        {
            if (i == sentence.size() || sentence[i] == ' ')
            {
                if (!temp.empty())
                {
                    splited.push_back(temp);
                    temp = "";
                }
            }
            else
            {
                temp += sentence[i];
            }
        }
        int foundindex =-1;

        for (int i = 0; i < splited.size(); i++)
        {
            string temp = splited[i];

            for (int j = 0; j < searchWord.size(); j++)
            {
                if (temp[j] != searchWord[j])
                {
                    foundindex = -1;
                    break;
                }
                foundindex = i;
            }
            if (foundindex != -1)
                break;
        }
        if(foundindex == -1)
        {
            return foundindex;
        }
        else
        {
            return foundindex+1;
        }

    }
};

int main()
{
    Solution s;
    string str = "I love eating burger";
    string sw = "burg";

   int foundindex = s.isPrefixOfWord(str,sw);

    if (foundindex != -1)
    {
        cout << "Element found at index: " << foundindex<< endl;
    }
    else
    {
        cout << "Element not found!";
    }
}