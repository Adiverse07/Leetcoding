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
        left = right = NULL;
    }
};
class Solution
{
public:
    vector<int> largestValues(TreeNode *root)
    {

        vector<int> maxelements;
        int maxele = INT_MIN;
        if(root==NULL)
        {
        return maxelements;
        }

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr != NULL)
            {
                if (curr->val > maxele)
                    maxele = curr->val;
                

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            else if(!q.empty())
            {
                maxelements.push_back(maxele);
                q.push(NULL);
                maxele = INT_MIN;
                
            }
        }
        maxelements.push_back(maxele);

        return maxelements;
    }
};

int main()
{
    Solution sl;
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> res = sl.largestValues(root);

    for(auto e: res)
        cout<<e<<" ";


}