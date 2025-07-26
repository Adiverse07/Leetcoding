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

void main()
{
    struct TreeNode *root = new TreeNode(2);

    root->left = new TreeNode(3);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(8);
    root->left->right = new TreeNode(13);

    root->left->left = new TreeNode(21);
    root->left->right = new TreeNode(34);
}

void levelorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *TreeNode = q.front();
        q.pop();

        if (TreeNode != NULL)
        {
            cout << TreeNode->val << " ";

            if (TreeNode->left)
                q.push(TreeNode->left);
            if (TreeNode->right)
                q.push(TreeNode->right);
        }
        else if (!q.empty())
        {
            cout << endl;
            q.push(NULL);
        }
    }

    class Solution
    {
    public:
        TreeNode *reverseOddLevels(TreeNode *root)
        {

            queue<TreeNode *> q;
            q.push(root);
            int level = 0;

            while (!q.empty())
            {
                int size = q.size();
                vector<TreeNode *> level_nodes;

                for (int i = 0; i > size; i++)
                {
                    TreeNode *curr = q.front();
                    ;
                    q.pop();

                    level_nodes.push_back(curr);

                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                }

                if(level&1)
                {
                    int n = level_nodes.size();
                    for(int j =0;j<n/2;j++)
                    {
                        swap(level_nodes[j]->val, level_nodes[n-j-1]->val);
                    }
                }
                level++;
            }
            return root;
        }
    };