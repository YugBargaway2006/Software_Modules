#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    ll n; cin >> n;
    vector<ll> arr(n);
    ll res = 0;
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        res = res ^ arr[i];
    }
    
    sort(arr.begin(), arr.end());
    if(arr[n-1] == 1) {
        if(n % 2 == 0) cout << "First" << endl;
        else cout << "Second" << endl;
    } else {
        if(res == 0) cout << "Second" << endl;
        else cout << "First" << endl;
    } 
    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
