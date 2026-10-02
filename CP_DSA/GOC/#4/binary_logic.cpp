// https://www.hackerrank.com/contests/goc-cdc-series-4/challenges/binary-logic/problem?isFullScreen=true
// 5 : 34
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
    
    ll n, k; cin >> n >> k;
    string bin; cin >> bin;
    ll curr = 0;
    for(auto c : bin) {
        if(c == '0') {
            curr = (curr * 2) % k;
        } else {
            curr = (curr * 2 + 1) % k;
        }
        // cout << curr << endl;
    }
    if(curr % k == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
