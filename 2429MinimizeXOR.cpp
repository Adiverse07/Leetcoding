#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int count = __builtin_popcount(num2);
        int res = 0;

        for(int i = 31; i >=0 and count;i--) 
        {
            if(num1 & (1<<i)) // 1<<i to obtain 1 2 4 8  : 1<<0 = 0001 = 1; 1<<1 = 0010 = 2; and so on
            {
                count--;
                res+= (1<<i);
            }
        }

        for(int i=0;i<32 and count;i++)
        {
            if((num1 & (1<<i))==0)
            {
                count--;
                res+= (1<<i);
            }
        }
        return res;
        
    }
};

int main()
{
Solution sl;
int num1 = 3;
int num2 = 5;

cout<<sl.minimizeXor(num1,num2);
}