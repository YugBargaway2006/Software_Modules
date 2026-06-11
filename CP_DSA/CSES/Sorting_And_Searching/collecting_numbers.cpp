// *** 19 : 32   ::::: Just look the Condition
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

vector<ll> arr;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    arr.resize(n);
    map<ll, ll> idx;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        idx[arr[i]] = i;
    }

    int r = 1;
    for(ll i = 0; i< n-1; i++) {
        if(idx[i+1] > idx[i+2]) r++;
    }
    cout << r << endl;
}