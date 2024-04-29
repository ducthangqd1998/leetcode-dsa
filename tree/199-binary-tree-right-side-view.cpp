#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> arr;
        queue<TreeNode *> q;

        if (root == nullptr)
            return {};
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *current = q.front();
                q.pop();
                if (current->left != nullptr)
                    q.push(current->left);
                if (current->right != nullptr)
                    q.push(current->right);
                if (i == n - 1)
                    arr.push_back(current->val);
            }
        }
        return arr;
    }
};