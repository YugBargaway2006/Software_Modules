// 17 : 12
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Node {
    ll value;
    Node *arr[2];

    Node() {
        value = 0;
        arr[0] = arr[1] = NULL;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(ll pre_xor) {
        Node* temp = root;
        for(ll i = 31; i >= 0; i--) {
            bool val = pre_xor & (1 << i);
            if(temp -> arr[val] == NULL) {
                temp->arr[val] = new Node();
            }
            temp = temp -> arr[val];
        }
        temp->value = pre_xor;
    }

    ll query(ll pre_xor) {
        Node *temp = root;
        for(ll i = 31; i >= 0; i--) {
            bool val = pre_xor & (1 << i);
            if(temp->arr[1-val] != NULL) {
                temp = temp -> arr[1-val];
            } else if(temp->arr[val] != NULL) {
                temp = temp -> arr[val];
            }
        }

        return pre_xor ^ (temp->value);
    }
};

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Trie trie;
    trie.insert(0);

    ll res = INT_MIN, pre_xor = 0;
    for(ll i = 0; i < arr.size(); i++) {
        pre_xor ^= arr[i];
        trie.insert(pre_xor);
        res = max(res, trie.query(pre_xor));
    }
    cout << res << endl;
}