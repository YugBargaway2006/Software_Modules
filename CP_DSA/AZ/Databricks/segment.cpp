// Write your code here
// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    ll mxn = 100000+1;
    vector<ll> arr(mxn, 0);
    ll ct = 0;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        arr[x] = 1;
        ll r = x+1, l = x-1;
        while(r < mxn && arr[r] == 1) {
            r++;
        }
        while(l >= 0 && arr[l] == 1) {
            l--;
        }

        ct = max(ct, r-l-1);
        cout << ct << " ";
    }
    cout << endl;
}