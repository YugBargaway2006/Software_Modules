#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define endl '\n'


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m; cin >> n >> m;
    vector<vector<ll>> arr(n, vector<ll>(3, 0));
    for(ll i = 0; i < m; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    vector<ll> dp(n+1, 0);
    
}