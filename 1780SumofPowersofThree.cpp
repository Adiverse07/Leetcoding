#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        while(n)
        {
            if(n%3 ==2)
            {
                return false;
            }
            n/=3;
        }
        return true;
    }
};

int main()
{
Solution sl;
int n = 12;

if(sl.checkPowersOfThree(n)) cout<<"True"; else false;
}