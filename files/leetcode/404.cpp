#include <iostream>
#include <vector>
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
    bool isLeaf(TreeNode *node)
    {
        return !node->left && !node->right;
    }
    
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int curVal = 0;
        if (root->left != NULL && isLeaf(root->left))
        {
            curVal = root->left->val;
        }
        return curVal + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};