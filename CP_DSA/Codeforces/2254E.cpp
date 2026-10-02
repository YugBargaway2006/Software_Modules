/*
    Solution: 
    1. ai = bi + a(i-1) ==> ai is the prefix sum of bi, and since bi is shuffled, prefix sum of any permutation of b 
    2. Greedy choose the minimum viable option, maintaining positive ai 

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vector<ll> brr(n);
    multiset<ll> ele;
    for(ll i = 0; i < n; i++) {
        cin >> brr[i];
        ele.insert(brr[i]);
    }

    vector<ll> arr;
    ll pre = 0;
    for(ll i = 0; i < n; i++) {
        auto it = ele.upper_bound(-pre);
        if(it == ele.end()) {
            break;
        }
        ll bi = *it;
        pre += bi; 
        ele.erase(it);

        // cout << pre << " " << bi << endl;

        if(pre <= 0) {
            cout << -1 << endl;
            return;
        }
        arr.push_back(pre);
    }

    while(!ele.empty()) {
        ll sm = *ele.begin();
        pre += sm; 
        ele.erase(ele.begin());

        if(pre <= 0) {
            cout << -1 << endl;
            return;
        }
        arr.push_back(pre);
    }

    for(auto x : arr) cout << x << " "; cout << endl;


}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}