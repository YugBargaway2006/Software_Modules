// https://www.hackerrank.com/contests/goc-cdc-series-5/challenges/reached-safely-or-not/problem?isFullScreen=true
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
    
    ll n, m; cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m, 0));
    for(ll i = 0; i < n; i++) {
        for(ll j= 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    
    vector<vector<ll>> dp(n, vector<ll>(m, 1e15));
    dp[0][0] = (arr[0][0] == '#');

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i){
                dp[i][j] = min(dp[i][j],
                    dp[i-1][j] + (arr[i-1][j]=='.' && arr[i][j]=='#'));
            }
            if(j){
                dp[i][j] = min(dp[i][j],
                    dp[i][j-1] + (arr[i][j-1]=='.' && arr[i][j]=='#'));
            }
        }
    }
    cout << dp[n-1][m-1] << endl;
    
    return 0;
}
