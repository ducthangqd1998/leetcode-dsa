#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    queue<TreeNode*> q;
    void dfs(TreeNode* node) {
        if (node == nullptr)
            return;
        dfs(node->left);
        q.push(node);
        dfs(node->right);
    }
    BSTIterator(TreeNode* root) { dfs(root); }

    int next() {
        TreeNode* node = q.front();
        q.pop();
        return node->val;
    }

    bool hasNext() { return !q.empty(); }
};