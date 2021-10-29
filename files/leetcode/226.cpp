#include <iostream>

using namespace std;

//Definition for a binary tree node.
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
    /*void swapNode(TreeNode *node1, TreeNode *node2)
    {
        swap(node1->left, node2->left);
        swap(node1->right, node2->right);
        swap(node1->val, node2->val);
    }
    */

    void dfs(TreeNode *node)
    {
        /*
        if (!node->left && !node->right)
            return;
        if (!node->right)
        {
            node->right = new TreeNode();
            swap(node->left, node->right);
            delete (node->left);
            return;
        }
        */
        if(!node) return;
        swap(node->left, node->right);
        dfs(node->left);
        dfs(node->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;
        dfs(root);
        return root;
    }
};