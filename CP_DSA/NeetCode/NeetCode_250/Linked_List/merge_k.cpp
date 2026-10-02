/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<>> q;
        for(auto cur : lists) {
            while(cur != nullptr) {
                q.push(cur->val);
                cur = cur -> next;
            }
        } 

        ListNode* head = new ListNode();
        ListNode* cur = head;
        while(!q.empty()) {
            cur -> next = new ListNode(q.top()); q.pop();
            cur = cur -> next;
        }
        return head -> next;
    }
};
