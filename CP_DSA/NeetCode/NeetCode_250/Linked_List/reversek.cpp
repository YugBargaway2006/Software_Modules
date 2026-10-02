class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;

        for(int i = 0; i < k; i++) {
            if(curr == nullptr) return head; // less than k nodes
            curr = curr->next;
        }

        ListNode* prev = nullptr;
        curr = head;

        for(int i = 0; i < k; i++) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};