#include <bits/stdc++.h>
using  namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
      
        int n = digits.size();
        vector<int> avaialble(10,0);
        vector<int> res;

        for(int d: digits)
        avaialble[d]++;

        for(int i = 100;i<=999;i+=2)
        {
            int a = i/100;
            int b = (i/10)%10;
            int c = i%10;

            vector<int> used(10,0);

            used[a]++;
            used[b]++;
            used[c]++;

            bool valid = true;

            if(used[a]>avaialble[a] || used[b]>avaialble[b] || used[c]>avaialble[c])
            valid = false;

            if(valid)
            res.push_back(i);

        }
        return res;

    }
};

/*

Literally bakchodi
class Solution {

    int vectortonum(vector<int> arr)
    {
        int number = 0;

        for(int i =0;i<3;i++)
        {
            number = number*10 + arr[i];
        }
        return number;

    }
    void findPermute(vector<int> &digits, vector<int> &ds,set<int> &evenDigits, vector<bool> &freq)
    {
        if(ds.size()==3)
        {
            if(ds[2]%2==0 && ds[0]!=0)
                evenDigits.insert(vectortonum(ds));
            
            return;
        }

        for(int i =0;i<digits.size();i++)
        {
            if(!freq[i])
            {
             freq[i]=true;
             ds.push_back(digits[i]);
             findPermute(digits,ds,evenDigits,freq);
             ds.erase(ds.end()-1);
             freq[i]=false;
            }
        }
    }
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
      int n = digits.size();
      vector<bool> freq(n,false);
      vector<int> ds;
    
      set<int> evenDigits;

      findPermute(digits,ds,evenDigits,freq);
     

      return vector(evenDigits.begin(), evenDigits.end()) ;
    }
};

*/

int main()
{
    vector<int> digits = {2,1,3,0};
    Solution sl;

    vector<int> res = sl.findEvenNumbers(digits);

    for(auto i : res)
    cout<<i<<" ";
}