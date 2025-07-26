#include <bits/stdc++.h>
using namespace std;

class Solution
{
#define pdi pair<double, int>
public:
    void heappush(priority_queue<pdi> &maxheap, vector<vector<int>> &classes, int idx)
    {
        double curavg = (double)classes[idx][0] / classes[idx][1]; // typecast any one to make the result double

        double newavg = ((double)classes[idx][0] + 1) / (classes[idx][1] + 1);

        double possible_increment = newavg - curavg;
        maxheap.push(make_pair(possible_increment, idx));
    }

    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        int n = classes.size();
        priority_queue<pdi> maxheap;

        for (int i = 0; i < n; i++)
            heappush(maxheap, classes, i);

        while (extraStudents--)
        {
            pdi curr = maxheap.top();
            maxheap.pop();

            int idx = curr.second;
            classes[idx][0]++;
            classes[idx][1]++;

            heappush(maxheap, classes, idx);
        }

        double finalavg = 0.0;

        // for(auto c:classes)
        //     finalavg+= (double)c[0]/c[1];

        for (int i = 0; i < n; i++)
            finalavg += (double)classes[i][0] / classes[i][1];

        return finalavg / n;
    }
};

int main()
{
    Solution sl;
    vector<vector<int>> classes = {{1, 2}, {3, 5}, {2, 2}};
    int extra = 2;

    cout << sl.maxAverageRatio(classes, extra);
}