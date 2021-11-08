#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void check(ListNode* cur, vector<int>& critical, int index)
    {
        if ((cur->val > cur->next->val && cur->next->val < cur->next->next->val) || (cur->val < cur->next->val && cur->next->val > cur->next->next->val))
        {
            critical.push_back(index);
        }
        return;
    }

    int mingap(vector<int> &critical)
    {
        int ans = INT_MAX;
        for (int i = 1; i < critical.size(); ++i)
        {
            ans = min(critical[i], critical[i - 1]);
        }
        return ans;
    }
    
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        vector<int> ans;
        int index = 1;
        while(head->next->next != nullptr)
        {
            check(head, critical, index);
            ++index;
        }
        if (critical.size() < 2)
        {
            ans = {-1, -1};
        }
        else
        {
            ans[1] = critical[critical.size()-1] - critical[0];
            ans[0] = mingap(critical);
        }
        return ans;
    }

    int main()
    {
        
    }
};