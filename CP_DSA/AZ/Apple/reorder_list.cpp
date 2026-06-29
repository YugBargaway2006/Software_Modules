
#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define endl '\n';

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void reorderList(ListNode* head) {
    //Complete the function 
    vector<ListNode*> arr;
    ListNode* cur = head;
    while(cur != nullptr) {
        arr.push_back(cur);
        cur = cur -> next;
    }   

    ListNode* newhead = new ListNode();
    cur = newhead;
    for(ll i = 0; i < arr.size(); i+=2) {
        cur -> next = arr[i];
        cur = cur -> next;
    }
    ll end = (arr.size()%2 == 0) ? arr.size()-1 : arr.size()-2;
    for(ll i = end; i >= 0; i-=2) {
        cur -> next = arr[i];
        cur = cur -> next;
    }
    cur -> next = nullptr;

    head = newhead -> next;
}


ListNode* GetList(vector<int> &num) {
    ListNode* head = nullptr;

    if(num.empty()) {
        return head;
    }

    ListNode* cur = head;
    
    for(int i  = 0; i < (int)num.size(); i++) {
        ListNode* temp = new ListNode(num[i]);
        if(!cur) {
            cur = temp;
            head = cur;
        }
        else {
            cur->next = temp;
            cur = temp;
        }
    }
    
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vector<int> num;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        num.push_back(x);
    }

    ListNode* head = GetList(num);

    reorderList(head);

    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
    
    return 0;
}
