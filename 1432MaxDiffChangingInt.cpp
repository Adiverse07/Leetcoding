#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDiff(int num)
    {

        string big = to_string(num);
        string small = to_string(num);

        int msbidx = big.find_first_not_of('9');

        if (msbidx != string::npos)
        {
            char msb = big[msbidx];
            replace(begin(big), end(big), msb, '9');
        }

        if (small.size() != 1)
        {
            int msbidx2 = small.find_first_not_of("01");
          

            if (msbidx2 != string::npos)
            {
                char ch = small[msbidx2];
                if (msbidx2 != 0)
                {

                    replace(begin(small), end(small), ch, '0');
                }
                else
                {
                    replace(begin(small), end(small), ch, '1');
                }
            }
        }
        else
        {
            small[0] = '1';
        }

        cout << big << endl
             << small << endl;
        return stoi(big) - stoi(small);
    }
};

int main()
{
    Solution sl;

    cout << sl.maxDiff(1111);
}