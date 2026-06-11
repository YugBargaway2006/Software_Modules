// https://www.hackerrank.com/contests/goc-cdc-series-2/challenges/jhul-in-prison/problem?isFullScreen=true
// :::
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
    
    ll x, y; cin >> x >> y;
    vector<ll> remx(x), remy(y);
    for(ll i = 0; i < x; i++) {
        cin >> remx[i];
    }
    for(ll i = 0; i < y; i++) {
        cin >> remy[i];
    }
    sort(remx.begin(), remx.end());
    sort(remy.begin(), remy.end());
    
    // for x
    ll cansx = 0;
    ll ansx = 0;
    for(ll i = 1; i < x; i++) {
        if(remx[i] == remx[i-1]+1) cansx++;
        else cansx = 0;
        ansx = max(ansx, cansx);   // Help solved
    }
    ll cansy = 0;
    ll ansy = 0;
    for(ll i = 1; i < y; i++) {
        if(remy[i] == remy[i-1]+1) cansy++;
        else cansy = 0;
        ansy = max(ansy, cansy);
    }
    ansx += 2;
    ansy += 2;
    cout << ansx * ansy << endl;
    
    return 0;
}
