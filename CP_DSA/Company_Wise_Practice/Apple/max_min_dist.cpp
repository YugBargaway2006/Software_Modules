// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

bool check(vector<ll>& arr, ll n, ll k, ll d) {
    ll ct = 1;
    ll last = arr[0];
    for(ll i = 0; i < n; i++) {
        if(arr[i] - last >= d) {
            ct += 1;
            last = arr[i];
        }
    }
    if(ct >= k) return true;
    else return false;
}

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll l = 0, r = arr[n-1]+1;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        bool c1 = check(arr, n, k, mid);
        bool c2 = check(arr, n, k, mid+1);

        if(c1 && !c2) {
            cout << mid << endl;
            return;
        } 
        else if(c1 && c2) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}