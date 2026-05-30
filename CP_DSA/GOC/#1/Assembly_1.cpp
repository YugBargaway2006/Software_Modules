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
    vector<ll> arr(n), boys, girls;
    
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] % 2 == 0) {
            boys.push_back(arr[i]);
        } else {
            girls.push_back(arr[i]);
        }
    }
    
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    
    ll b = 0, g = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            arr[i] = boys[b]; b++;
        } else {
            arr[i] = girls[g]; g++;
        }
    }
    
    for(auto x  : arr) cout << x << " "; cout << endl;
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