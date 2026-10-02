/*
    Code Logic: 
    1. Invariant : When we do xor, since the number of elements is even, xor sum becomes S xor ai
    2. If we perform two consequtive operations, with say i and j, what happens: 
        After i, ai and ak xor ai 
        After j, ai xor (aj xor ai) = aj 
                 aj is actually aj xor ai (as per the initial array)
                 ak xor ai xor (aj xor ai) = ak xor aj 
        This means after two operations, either we get permutations of same or differ by one operation 

    3. If permuation of same, sort and find out.
    4. Else, we need to find ai -> since xor sum changes by ai, find ai by Sa xor Sb 
    5. If a does not contain ai, then NO 
    6. Perform the operation and then check for yes

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n), brr(n);
    ll sa = 0, sb = 0;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        sa ^= arr[i];
    }
    for(ll i = 0; i < n; i++) {
        cin >> brr[i];
        sb ^= brr[i];
    }

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    if(arr == brr) {
        cout << "YES" << endl;
        return;
    }

    ll x = sa ^ sb;

    // cout << x << " " << sa << " " << sb << endl;

    bool found = false;
    ll idx = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i] == x) {
            found = true;
            idx = i;
            break;
        }
    }

    if(!found) {
        cout << "NO" << endl;
        return;
    }

    for(ll i = 0; i < n; i++) {
        if(i == idx) continue;
        arr[i] ^= x;
    }

    sort(arr.begin(), arr.end());
    
    if(arr == brr) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;cin >> t;
    while(t--) {
        solve();
    }
}