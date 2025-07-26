#include <bits/stdc++.h>
using namespace std;
class Solution
{

    int getState( int count_a, int count_b)
    {
        int parity_a = count_a%2;
        int parity_b = count_b % 2;

        if(parity_a == 0 && parity_b == 0) return 0; //(even even) (00)
        if(parity_a == 0 && parity_b == 1) return 1;
        if(parity_a == 1 && parity_b == 0) return 2;

        return 3;
    }
public:
    int maxDifference(string s, int k)
    {
        int n = s.size();

        int result = INT_MIN;

        for(char a = '0'; a<='4';a++)
        {
            for(char b ='0'; b<= '4'; b++)
            {
                if(a==b)
                continue;

                //stateMinPrev_a_b[state] = stores the smallest value of count of a- b

                vector<int> stateMinPrev_a_b(4,INT_MAX);

                //Count of a and b till index r
                int count_a = 0;
                int count_b = 0;

                //Count of a and b till prev index l
                int prev_a = 0;
                int prev_b = 0;

                //Let's start sliding winddow

                int l =-1;
                int r = 0;

                while(r<n)
                {
                    count_a += (s[r] == a) ? 1: 0;
                    count_b += (s[r] == b) ? 1: 0;

                    //Now try to shrink from l

                    while(r - l >=k and count_b - prev_b >=2 && count_a - prev_a >= 1)
                    {
                        int leftState = getState(prev_a, prev_b);

                        stateMinPrev_a_b[leftState] = min(stateMinPrev_a_b[leftState],prev_a - prev_b);

                        l++;
                        prev_a += (s[l]==a) ? 1 : 0;
                        prev_b += (s[l] == b) ? 1: 0;

                    }

                        int rightState = getState(count_a, count_b);
                        int bestLeftState =  rightState ^ 2;

                        int bestMinDiffValueLeft = stateMinPrev_a_b[bestLeftState];

                        if(bestMinDiffValueLeft != INT_MAX)
                        {
                            result = max(result, (count_a - count_b) - bestMinDiffValueLeft);
                        }

                    
                    
                    r++;
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution sl;
    string s = "1122211";
    int k = 3;

    cout << sl.maxDifference(s, k);
}