// https://www.hackerrank.com/contests/goc-cdc-series-7/challenges/propose-her/problem?isFullScreen=true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

set<string> res;

void find_all(ll n, ll l, ll r, string& curr) {
    if(r > l) return;
    if(l > n) return;
    if(l+r == n+n) {
        if(l == r) {
            res.insert(curr);
        }
        return;
    }
    
    curr.push_back('(');
    find_all(n, l+1, r, curr);
    curr.pop_back();
    
    curr.push_back(')');
    find_all(n, l, r+1, curr);
    curr.pop_back();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    string curr = "";
    find_all(n, 0, 0, curr); 
    cout << res.size() << endl;
    for(auto s : res) {
        cout << s << endl;
    }
    return 0;
}