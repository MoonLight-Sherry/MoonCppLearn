#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while(fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;
            if(fast == slow)
            {
                while(fast != head)
                {
                    fast = fast->next;
                    head = head->next;
                }
                return head;
            }
        }
        return nullptr;
    }
};