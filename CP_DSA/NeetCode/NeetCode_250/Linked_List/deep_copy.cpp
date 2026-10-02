/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> mapping;
        Node* newhead = new Node(0);
        Node* curr = newhead;

        Node* old = head;
        while(old != nullptr) {
            curr -> next = new Node(old->val);
            mapping[old] = curr->next;
            curr = curr -> next;
            old = old -> next;
        }

        old = head;
        curr = newhead -> next;
        while(old != nullptr) {
            if(old -> random == nullptr) {
                curr->random = nullptr;
                curr = curr -> next;
                old = old -> next;
            } else {
                curr->random = mapping[old->random];
                curr = curr -> next;
                old = old -> next;
            }
        }

        return newhead->next;
    }
};
