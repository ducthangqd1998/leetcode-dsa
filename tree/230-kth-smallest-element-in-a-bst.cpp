#include <stdio.h>
#include <iostream>

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
    int ans;
    void search(TreeNode* node, int& k) {
        if (node == nullptr)
            return;
        search(node->left, k);
        if (--k == 0)
            ans = node->val;
        search(node->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        search(root, k);
        return ans;
    }
};