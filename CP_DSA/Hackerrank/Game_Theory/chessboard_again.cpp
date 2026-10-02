#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<ll> dx = {-2, -2, 1, -1};
vector<ll> dy = {1, -1, -2, -2};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll mxn = 15+1;
    vector<vector<ll>> board(mxn, vector<ll>(mxn, 0));
    
    queue<pair<ll, ll>> q;
    q.push({1, 1});
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        
        if(i < 1 || j < 1 || i > 15 || j > 15) continue;    
        // cerr << "(" << i << "," << j << ")" << endl;
        vector<bool> found(5, false);
        for(ll k = 0; k < 4; k++) {
            ll ni = i+dx[k];
            ll nj = j+dy[k];
            
            if(ni < 1 || nj < 1 || ni > 15 || nj > 15) continue;
            
            found[board[ni][nj]] = true;
        }
        for(ll k = 0; k < 5; k++) {
            if(!found[k]) {
                board[i][j] = k;
                break;
            }
        }
        
        q.push({i, j+1});
        if(j == 1) q.push({i+1, j});
    }
    
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll res = 0;
        for(ll i = 0; i < n; i++) {
            ll x, y; cin >> x >> y;
            // cout << board[x][y] << " ";
            res = res  ^ board[x][y];        
        }
        // cout << endl;
        if(res != 0) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    
    
    return 0;
}
