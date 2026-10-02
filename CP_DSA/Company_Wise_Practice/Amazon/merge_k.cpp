
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#define ll long long 

ListNode* mergeKLists(vector<ListNode*> head) {
    //Complete the function
    ListNode* newhead = new ListNode();
    ListNode* curr = newhead;
    bool done = false;
    ll n = head.size();
    while(!done) {
        done = true;
        for(ll i = 0; i < n; i++) {
            if(head[i] != nullptr) {
                done = false;
                break;
            }
        }
        if(done) break;

        ll midx = 0;
        ll mn = 1e12;
        for(ll i = 0; i < n; i++) {
            if(head[i] == nullptr) continue;
            if(mn > head[i]->val) {
                mn = head[i]->val;
                midx = i;
            }
        }

        curr -> next = head[midx];
        curr = curr -> next;
        head[midx] = head[midx] -> next;
        curr->next = nullptr;
    }

    return newhead -> next;
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

vector<ListNode*> GetList(int K, vector<vector<int>> &num) {
    vector<ListNode*> head(K);
    for(int i = 0; i < K; i++) {
        head[i] = GetList(num[i]);
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int K;
    cin >> K;

    vector<vector<int>> num(K);

    for(int i = 0; i < K; i++) {
        int n;
        cin >> n;
        for(int j = 0; j < n; j++) {
            int x;
            cin >> x;
            num[i].push_back(x);
        }
    }

    vector<ListNode*> head = GetList(K, num);

    ListNode* mergeHead = mergeKLists(head);

    while(mergeHead) {
        cout << mergeHead->val << " ";
        mergeHead = mergeHead->next;
    }
    cout << "\n";
    
    return 0;
}
