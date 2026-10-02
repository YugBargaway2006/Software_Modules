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
    vector<vector<bool>> board(mxn, vector<bool>(mxn, false));
    
    queue<pair<ll, ll>> q;
    q.push({1, 1});
    while(!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        
        if(i < 1 || j < 1 || i > 15 || j > 15) continue;    
        // cerr << "(" << i << "," << j << ")" << endl;
        bool res = true;
        for(ll k = 0; k < 4; k++) {
            ll ni = i+dx[k];
            ll nj = j+dy[k];
            
            if(ni < 1 || nj < 1 || ni > 15 || nj > 15) continue;
            
            res = res && board[ni][nj];
        }
        if(!res) board[i][j] = true;
        else board[i][j] = false;
        
        q.push({i, j+1});
        if(j == 1) q.push({i+1, j});
    }
    
    ll t; cin >> t;
    while(t--) {
        ll x, y; cin >> x >> y;
        if(board[x][y]) cout << "First" << endl;
        else cout << "Second" << endl;
    }
    
    
    return 0;
}
