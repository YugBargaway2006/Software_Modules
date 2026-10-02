#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll l = 0, r = n-1;
    ll ct = 0;
    while(l < r) {
        if(arr[l] == arr[r]) {
            l++; r--;
            continue;
        }

        ct++;
        if(arr[l] < arr[r]) {
            arr[l+1] += arr[l];
            l++;
            continue;
        } else {
            arr[r-1] += arr[r];
            r--;
            continue;
        }
    }
    cout << ct << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}