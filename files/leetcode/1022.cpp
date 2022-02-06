#include <algorithm>
#include <vector>

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

class Solution
{
public:
    int result = 0;

    void dfs(TreeNode *node, int cur)
    {
        if (node != nullptr)
        {
            cur = (cur << 1) + node->val;//注意<<优先级，需要加括号！
            if (node -> left == nullptr && node -> right == nullptr)
            {
                result += cur;
                return;
            }
            dfs(node->left, cur);
            dfs(node->right, cur);
        }
    }

    int sumRootToLeaf(TreeNode *root)
    {
        dfs(root, 0);
        return result;
    }
};