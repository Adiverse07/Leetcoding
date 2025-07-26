#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> closestPrimes(int left, int right)
    {

        if (right < -2)
            return {-1, -1};
        vector<bool> isPrime(right + 1, true);

        isPrime[0] = false;
        isPrime[1] = false;

        for (int i = 2; i < sqrt(right) + 1; i++)
        {
            if (!isPrime[i])
                continue;
            for (int j = i*i; j <= right; j += i)
            {
                isPrime[j] = false;
            }
        }

        vector<int> primes;
        for (int i = left; i < right + 1; i++)
        {
            if (isPrime[i])
                primes.push_back(i);
        }

        int minDiff = INT_MAX;
        vector<int> res(2, -1);
        for (int i = 1; i < primes.size(); i++)
        {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff)
            {
                minDiff = diff;
                res[0] = primes[i - 1];
                res[1] = primes[i];
            }
        }
        return res;
    }
};
// Bhosada Time Complexity
/*class Solution
{

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> primes;

        for (int i = left; i <= right; i++)
        {
            if (isPrime(i))
                primes.push_back(i);
        }

        vector<int> res(2, -1);
        int minDiff = INT_MAX;

        for (int i = 1; i < primes.size(); i++)
        {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff)
            {
                minDiff = diff;
                res[0] = primes[i - 1];
                res[1] = primes[i];
            }
        }
        return res;
    }
};*/

int main()
{
    Solution sl;
    int left = 19;
    int right = 31;
    vector<int> res = sl.closestPrimes(left, right);

    for (auto i : res)
        cout << i << " ";
}

//GAND FAAD OPTIMIZATION
/*
class Solution {
public:
    static std::vector<int> closestPrimes(int left, int right)
    {
        if (left <= 2 && right >= 3)
            return { 2, 3 };

        std::vector<int> primes = { 2, 3 };
        primes.reserve(200);

        {
            int prev_prime = -1;

            int i = primes.back();
            do
            {
                i += 2;

                for (int j = 1; j < primes.size(); j++)
                {
                    int prime = primes[j];
                    if (i % prime == 0)
                        break;
                    if (prime * prime > i)
                    {
                        if (i > left)
                        {
                            if (prev_prime == -1)
                                prev_prime = i;
                            else
                            {
                                if (i - prev_prime == 2)
                                    return { prev_prime, i };
                            }
                        }

                        primes.push_back(i);
                        break;
                    }
                }
            } while (primes.back() * primes.back() < right);
        }

        const int lastPrime = primes.back();

        int num1 = -1;
        int num2 = -1;
        int prev_prime = -1;
        int delta = right - left;

        for (int i = (left / 2) * 2 + 1; i <= right; i += 2)
        {
            int j = 1;
            for (; j < primes.size(); j++)
            {
                int prime = primes[j];
                if (i % prime == 0)
                    break;
                if (prime * prime > i)
                {
                    if (num1 == -1)
                    {
                        num1 = i;
                    }
                    else if (num2 == -1)
                    {
                        num2 = i;
                        prev_prime = i;
                        delta = num2 - num1;
                        if (delta == 2)
                            return { num1, num2 };
                    }
                    else
                    {
                        int curr_delta = i - prev_prime;
                        if (curr_delta == 2)
                            return { prev_prime, i };
                        if (curr_delta < delta)
                        {
                            num1 = prev_prime;
                            num2 = i;
                        }
                        prev_prime = i;
                    }
                    
                    break;
                }
            }
            if (j == primes.size())
                throw std::exception();
        }

        if (num1 != -1 && num2 != -1)
            return { num1, num2 };

        return { -1, -1 };
    }
};
*/