#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long 
#define endl '\n'


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while(t--) {
        ll n, k; cin >> n >> k;
        ll res = 0;
        for(ll i = 0; i < n; i++) {
            ll x; cin >> x;
            res = res ^ x;
        }
        if(res == 0) cout << "Second" << endl;
        else cout << "First" << endl;
    }
    return 0;
}
