#include <bits/stdc++.h>
using namespace std;

class Domino
{

public:
    void doubledominopush(int last_R, int pos, string &dominoes)
    {
        while (last_R < pos)
        {
            dominoes[last_R++] = 'R';
            dominoes[pos--] = 'L';
        }
    }

    void leftDominoPush(int start, int end, string &dominoes)
    {
        while (start <= end)
        {
            dominoes[start++] = 'L';
        }
    }

    void rightDominoPush(int last_R, int pos, string &dominoes)
    {
        while (last_R <= pos)
        {
            dominoes[last_R++] = 'R';
        }
    }
};
class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        Domino d;

        int n = dominoes.size();
        int last_L = -1, last_R = -1;

        for (int pos = 0; pos < n; pos++)
        {
            if (dominoes[pos] == 'L')
            {
                if (last_R > last_L)
                {
                    d.doubledominopush(last_R, pos, dominoes);
                }

                else if ((last_L > last_R) || last_L == -1)
                {
                    d.leftDominoPush(last_L + 1, pos, dominoes);
                }
                last_L = pos;
            }

            else if (dominoes[pos] == 'R')
            {
                if (last_R > last_L)
                {
                    d.rightDominoPush(last_R, pos, dominoes);
                }
                last_R = pos;
            }
        }

        if (last_R > last_L)
        {
            d.rightDominoPush(last_R , n - 1, dominoes);
        }

        return dominoes;
    }
};

int main()
{
    string dominoes = "RR.L";
    Solution sl;

    cout << sl.pushDominoes(dominoes);
}