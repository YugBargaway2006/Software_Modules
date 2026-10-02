// 22 : 52
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, k;
vector<ll> arr;
set<pair<ll, ll>> res;
map<ll, ll> freq;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    arr.assign(n+1, 0);
    for(ll i = 1;i <= n; i++) {
        cin >> arr[i];
    }

    vector<ll> ans;
    ll mxn = 2e5+1;
    for(ll i = 0; i < mxn; i++) {
        res.insert({0, i});
        freq[i] = 0;
    }
    for(ll i = 1; i <= k; i++) {
        ll x = freq[arr[i]];
        res.erase({x, arr[i]});
        freq[arr[i]]++;
        res.insert({x+1, arr[i]});
    }
    // cout << sum << endl;

    ll i = k+1;
    ans.push_back(res.begin()->second);
    while(i <= n) {
        // cout << sum << endl;
        ll x = freq[arr[i]];
        // cout << x << endl;
        res.erase({x, arr[i]});
        freq[arr[i]]++;
        res.insert({x+1, arr[i]});

        x = freq[arr[i-k]];
        res.erase({x, arr[i-k]});
        freq[arr[i-k]]--;
        res.insert({x-1, arr[i-k]});

        ans.push_back(res.begin()->second);
        i++;
    }
    for(auto x : ans) cout << x << " "; cout << endl;
}