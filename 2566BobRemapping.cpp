#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        
        string big = to_string(num);
        string small = big;
        int msbidx = big.find_first_not_of('9');

        // char msb = (msbidx!=string::npos) ? big[msbidx] : '9';


        if(msbidx!=string::npos)
        {
            char msb =  big[msbidx];
            replace(begin(big), end(big),msb,'9');
        }

        char ch = small[0];
        replace(begin(small),end(small),ch,'0');
        

        return stoi(big) - stoi(small);
    }
};

int main()
{
    Solution sl;
    
    cout<<sl.minMaxDifference(9);
}


//BRUTE FORCE
/*
class Solution {
public:
    int minMaxDifference(int num) {
        
        string numS = to_string(num);
        int n = numS.length();
        string big = numS;
        string small = numS;
        char msb = '9';

        for(int i =0;i<n;i++)
        {
            if(numS[i]!= '9')
            {
                msb = numS[i];
                break;
            }
        }

        cout<<msb<<endl;

        for(int i =0;i<n;i++)
        {
            if(big[i]==msb)
            {
                big[i] = '9';
            }
        }
        cout<<big<<endl;

        for(int i = 0;i<n;i++)
        {
            if(small[i] == numS[0])
            small[i] = '0';
        }

        

        return stoi(big) - stoi(small);
    }
};
*/