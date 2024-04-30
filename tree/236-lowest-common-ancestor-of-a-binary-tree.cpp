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
    TreeNode *dfs(TreeNode *node, TreeNode *p, TreeNode *q)
    {
        if (node == nullptr)
            return NULL;
        if (node == p || node == q)
            return node;

        TreeNode *l = dfs(node->left, p, q);
        TreeNode *r = dfs(node->right, p, q);

        if (l != nullptr && r != nullptr)
            return node;
        if (l == nullptr)
            return r;
        else
            return l;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return NULL;
        return dfs(root, p, q);
    }
};