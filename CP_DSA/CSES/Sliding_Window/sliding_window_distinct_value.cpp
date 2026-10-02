// 22 : 52
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, k;
vector<ll> arr;
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
    for(ll i = 1; i <= k; i++) {
        freq[arr[i]]++;
    }
    // cout << sum << endl;

    ll i = k+1;
    ans.push_back(freq.size());
    while(i <= n) {
        // cout << sum << endl;
        freq[arr[i]] += 1;
        if(--freq[arr[i-k]] == 0) {
            // cout << i-k << " " << arr[i-k] << endl;
            freq.erase(arr[i-k]);
        }

        ans.push_back(freq.size());
        i++;
    }
    for(auto x : ans) cout << x << " "; cout << endl;

}