#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int data)
    {
        val = data;
    }
};

class Solution
{

    int findswap(vector<int> values)
    {
        int min_swaps = 0;
        int n = values.size();

        map<int, int> sorted_map;

        for (int j = 0; j < n; j++)
        {
            sorted_map[values[j]] = j;
        }

        sort(values.begin(), values.end());

        vector<bool> visited(n, false);
        int iteration = 0; // row number of map

        for (auto &[val, idx] : sorted_map)
        {
            if (visited[idx])
            {
                iteration++; // dont process which is already processed
                continue;
            }

            visited[idx] = true;
            int len = 1; // default cycle lenght

            while (idx != iteration) // if idx ends on iterationn that means the cycle is complete
            {
                idx = sorted_map[values[idx]];
                visited[idx] = true;
                len++;
            }

            min_swaps += len - 1;
            iteration++;
        }

        return min_swaps;
    }

public:
    int minimumOperations(TreeNode *root)
    {

        queue<TreeNode *> q;
        q.push(root);
        int min_swaps = 0;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> values;

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                values.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }
            min_swaps += findswap(values);
        }

        return min_swaps;
    }
};