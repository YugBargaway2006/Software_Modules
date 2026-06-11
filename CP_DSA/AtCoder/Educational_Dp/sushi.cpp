// 23 : 54
#include <bits/stdc++.h>
using namespace std;

#define  ll long long
#define endl '\n'

vector<vector<vector<long double>>> dp;
ll n;

long double solve(ll x, ll y, ll z) {
    if(x < 0 || y < 0 || z < 0) return 0;
    if(dp[x][y][z] != -1) {
        return dp[x][y][z];
    }
    // long double n = static_cast<long double>(n);

    dp[x][y][z] = (1 + x/(n*1.0) * solve(x-1, y, z) + y/(n*1.0) * solve(x+1,y-1,z) + z/(1.0*n) * solve(x,y+1,z-1)) / (1 - (n-x-y-z)/(n*1.0));
    return dp[x][y][z]; 
} 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp.assign(n+1, vector<vector<long double>>(n+1, vector<long double>(n+1, -1)));
    ll x, y, z;
    x = y = z = 0;
    for(ll i = 0; i < n; i++) {
        ll t; cin >> t;
        if(t == 1) x++;
        if(t == 2) y++;
        if(t == 3) z++;
    }

    dp[0][0][0] = 0;
    cout << setprecision(10) << solve(x,y,z) << endl;
}