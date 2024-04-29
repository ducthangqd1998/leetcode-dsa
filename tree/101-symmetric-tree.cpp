#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution
{
public:
    bool dfs(TreeNode *r, TreeNode *l)
    {
        if (r == nullptr || l == nullptr)
            return r == l;
        if (r->val != l->val)
            return false;
        return dfs(r->right, l->left) && dfs(r->left, l->right);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        bool out = dfs(root->right, root->left);
        return out;
    }
};