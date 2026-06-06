// https://www.hackerrank.com/contests/goc-cdc-series-5/challenges/minimum-largest-element/problem?isFullScreen=true
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

ll n, k; 
vector<ll> arr;

bool check(ll m) {
    ll ct = 0;
    for(ll i = 0; i < n; i++) {
        if(m < arr[i]) return false;
        ct += (m-arr[i])/(i+1);
    }
    return ct >= k;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    arr.assign(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ll l = 0, r = 1e15;
    while(l <= r) {
        ll mid = l+(r-l)/2;
        bool c1 = check(mid-1);
        bool c2 = check(mid);
        
        if(!c1 && c2) {
            cout << mid << endl;
            break;
        } else if(c1 && c2) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    return 0;
}
