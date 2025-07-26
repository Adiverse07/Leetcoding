#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canChange(string start, string target)
    {
        // Check if both strings have the same number of 'L' and 'R'
        if (count(start.begin(), start.end(), 'L') != count(target.begin(), target.end(), 'L') ||
            count(start.begin(), start.end(), 'R') != count(target.begin(), target.end(), 'R'))
        {
            return false;
        }

        if (start.size() != target.size())
        {
            return false;
        }

        // Check if one string is full of underscores and the other has non-underscore characters
        if ((start.find_first_not_of('_') == string::npos && target.find_first_not_of('_') != string::npos) ||
            (target.find_first_not_of('_') == string::npos && start.find_first_not_of('_') != string::npos))
        {
            return false;
        }

        int indexS = 0;
        int indexT = 0;

        while (indexS < start.size() && indexT < target.size())
        {
            // Skip spaces in start
            while (indexS < start.size() && start[indexS] == '_')
            {
                indexS++;
            }

            // Skip spaces in target
            while (indexT < target.size() && target[indexT] == '_')
            {
                indexT++;
            }

            // If one string reaches the end but the other doesn't, return false
            if ((indexS == start.size() && indexT != target.size()) || (indexT == target.size() && indexS != start.size()))
            {
                return false;
            }

            // If characters do not match at the current indices, return false
            if (start[indexS] != target[indexT])
            {
                return false;
            }

            // Movement constraints: 'L' cannot move to the right and 'R' cannot move to the left
            if (target[indexT] == 'L' && indexS < indexT)
            {
                return false;
            }

            if (target[indexT] == 'R' && indexS > indexT)
            {
                return false;
            }

            indexS++;
            indexT++;
        }

        return true;
    }
};

int main()
{
    Solution sl;
    string s1 = "_L_R_";
    string s2 = "L___R";

    string s3 = "L_R_L";
    string s4 = "L__RL";

    if (sl.canChange(s1, s2))
    {
        cout << "Yes can change";
    }
    else
    {
        cout << "No cannot change";
    }
}

/*
OG Solution
class Solution {
public:
    bool canChange(string start, string target) {
        if (start == target) {
            return true;
        }
        int waitL = 0;
        int waitR = 0;
        
        for (int i = 0; i < start.length(); i++) {
            char curr = start[i];
            char goal = target[i];
            if (curr == 'R') {
                if (waitL > 0) {
                    return false;
                }
                waitR++;
            }
            if (goal == 'L') {
                if (waitR > 0) {
                    return false;
                }
                waitL++;
            }
            if (goal == 'R') {
                if (waitR == 0) {
                    return false;
                }
                waitR--;
            }
            if (curr == 'L') {
                if (waitL == 0) {
                    return false;
                }
                waitL--;
            }
        }
        return waitL == 0 && waitR == 0;
    }
};
*/
