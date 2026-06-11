// https://www.hackerrank.com/contests/goc-cdc-series-5/challenges/superstition/problem?isFullScreen=true
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
    string s; cin >> s;
    vector<pair<char, ll>> st;
    for(auto c : s) { 
        if (st.empty() || st.back().first != c) {
            st.push_back({c, 1});
        } else {
            st.back().second++;

            if (st.back().second == k) {
                st.pop_back();
            }
        }
    }
    
    string ans = "";
    for(auto p : st) {
        for(ll i = 0; i < p.second; i++) ans += p.first;
    }
    cout << ans << endl;
    
    return 0;
}
