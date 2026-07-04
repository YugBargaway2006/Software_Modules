// https://www.hackerrank.com/contests/goc-cdc-series-4/challenges/smart-strategy/problem?isFullScreen=true
//
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
    
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll r = n-1;
    ll ct = 0;
    for(ll i = 0; i < n; i++) {
        if(arr[i]%2 == 0) continue;
        while(arr[r] %2 == 1) {
            r--;
        }
        if(i >= r) break;
        ct++;
        swap(arr[i], arr[r]); 
    }
    cout << ct << endl;
    
    return 0;
}
