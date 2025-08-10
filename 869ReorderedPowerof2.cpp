#include <bits/stdc++.h>
using namespace std;

//approach 1: 
// class Solution {
// public:
//     string numToSortedString(int n)
//     {
//         string s =  to_string(n);

//         sort(s.begin(),s.end());

//         return s;
//     }
//     bool reorderedPowerOf2(int n) {
//         string number = numToSortedString(n);

//         for(int p = 0; p <= 29; p++)
//         {
//             if( number == numToSortedString(1<<p))
//             {
//                 return true;
//             }
           
//         }
//          return false;
//     }
// };

//approach 2
// class Solution {
// public:
//     string numToSortedString(int n)
//     {
//         string s =  to_string(n);

//         sort(s.begin(),s.end());

//         return s;
//     }
//     bool reorderedPowerOf2(int n) {
//         string numberString = numToSortedString(n);
//         unordered_set<string> allPowers;

//         for(int p = 0; p <= 29; p++)
//         {
//             allPowers.insert(numToSortedString(1<<p));
//         }

//         if(allPowers.find(numberString)!=allPowers.end())
//         return true;
//         return false;
//     }
// };

//approach3
class Solution {
public:

    int getCountFormat(int n)
    {
        int num = 0;

        while(n)
        {
            num += pow(10,n%10);
            n/=10;
        }

        return num;
    }
    bool reorderedPowerOf2(int n) {
        int input = getCountFormat(n);

        for(int p =0;p<=29;p++)
        {
            if(input == getCountFormat(1<<p))
            return true;
        }

        return false;
    }
};
int main()
{
   int n = 125;
   Solution sl;

   if(sl.reorderedPowerOf2(n))
   {
    cout<<"You win";
   }
   else
   {
    cout<<"You lose";
   }
}