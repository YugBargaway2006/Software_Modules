// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> arr(n), brr;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    brr = arr;

    sort(brr.begin(), brr.end());

    ll mxn = 1e5+1;
    ll add = 0;
    vector<ll> freqa(mxn, 0);
    vector<ll> freqb(mxn, 0);

    ll ct = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i] != brr[i]) {
            if(freqb[arr[i]] == 0) {
                freqa[arr[i]] += 1;
                add++;
            } else {
                freqb[arr[i]] -= 1;
                add--;
            }
            if(freqa[brr[i]] == 0) {
                freqb[brr[i]] += 1;
                add++;
            } else {
                freqa[brr[i]] -= 1;
                add--;
            }
        }
        if(add == 0) ct++;
    }
    if(add != 0) cout << 0 << endl;
    else cout << ct << endl;
}