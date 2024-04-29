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
    void dfs(TreeNode *node, vector<vector<int>> &arr, int h)
    {
        if (node == nullptr)
            return;
        if (h >= arr.size())
            arr.push_back({});
        arr[h].push_back(node->val);
        dfs(node->left, arr, h + 1);
        dfs(node->right, arr, h + 1);
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> arr;
        this->dfs(root, arr, 0);
        return arr;
    }
};