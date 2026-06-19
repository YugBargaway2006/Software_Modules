// https://www.hackerrank.com/contests/5-days-of-game-theory/challenges

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
    
    ll mxn = 100+1;
    vector<bool> win1(mxn, false);
    win1[2] = win1[3] = win1[4] = win1[5] = true;
    for(ll i = 6; i < mxn; i++) {
        bool res = win1[i-2] && win1[i-3] && win1[i-5];
        if(!res) win1[i] = true;
        else win1[i] = false;
    }
    
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        if(win1[n]) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    
    return 0;
}
