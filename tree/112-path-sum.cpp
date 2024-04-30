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

class Solution {
public:
    bool dfs(TreeNode* node, int targetSum, int currentSum) {
        if (node == nullptr)
            return false;
        currentSum += node->val;
        if (node->left == nullptr && node->right == nullptr)
            return currentSum == targetSum;
        return dfs(node->left, targetSum, currentSum) ||
               dfs(node->right, targetSum, currentSum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        return dfs(root, targetSum, 0);
    }
};