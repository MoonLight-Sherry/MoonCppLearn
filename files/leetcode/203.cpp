using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        auto dummyHead = new ListNode(0, head);//头节点前构造一个dummyHead，排除头节点的特殊情况
        auto cur = dummyHead;
        while (cur->next != nullptr)
        {
            if (cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};