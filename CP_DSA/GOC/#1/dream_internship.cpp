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
    
    ll n, area; cin >> n >> area;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    vector<ll> valid(n, 0);
    ll j = 0;
    for(ll i = n-1; i >= 0; i--) {
        while(j < i && arr[i] * arr[j] <= area) {
            j++;
        }
        valid[i] = min(j, i);
    }
    
    ll ct = 0;
    for(auto x : valid) {
        // cout << x << endl;
        ct += x;
    }
    cout << ct << endl;
    
    return 0;
}
