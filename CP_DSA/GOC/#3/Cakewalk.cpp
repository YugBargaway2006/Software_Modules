// https://www.hackerrank.com/contests/goc-cdc-series-3/challenges/cakewalk-3-4/problem?isFullScreen=true
// 16 : 35   ::::::: NEW CONCEPT
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    while(n%2 == 0) {
        n/=2;
    }
    
    ll ct = 1;
    for(ll i = 3; i*i <= n; i+=2) {
        if (n % i == 0) {
            ll count = 0;
            while (n % i == 0) {
                count++;
                n /= i;
            }
            // Number of divisors formula: multiply (exponent + 1)
            ct *= (count + 1);
        }
    }
    if (n > 1) {
        ct *= 2; 
    }
    
    cout << ct-1 << endl;    
    return 0;
}
