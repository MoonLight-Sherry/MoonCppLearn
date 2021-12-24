#define NULL nullptr

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int rangeSumBST(struct TreeNode *root, int low, int high)
{
    struct TreeNode *roots[40000];
    int left = 0, right = 0;
    long long sum = 0;
    roots[right++] = root;
    while(left < right)
    {
        struct TreeNode *curNode = roots[left++];
        if (curNode == NULL)
        {
            continue;
        }
        else if (curNode->val < low)
        {
            roots[right++] = curNode->right;
        }
        else if (curNode->val > high)
        {
            roots[right++] = curNode->left;
        }
        else
        {
            sum += curNode->val;
            roots[right++] = curNode->left;
            roots[right++] = curNode->right;
        }
    }
    return sum;
}