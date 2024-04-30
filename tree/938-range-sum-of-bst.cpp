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
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return -1;
        queue<TreeNode*> q;
        int sum = 0;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (low <= current->val && current->val <= high)
                sum += current->val;
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        return sum;
    }   
};