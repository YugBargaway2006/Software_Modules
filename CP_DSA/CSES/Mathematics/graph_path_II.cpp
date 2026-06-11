// 21 : 02
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

using Matrix = vector<vector<ll>>;
ll mod = 1e9+7;

Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.size();

    Matrix C(n, vector<long long>(n, LLONG_MAX));

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            for(int j = 0; j < n; j++) {
                if(A[i][k] == LLONG_MAX || B[k][j] == LLONG_MAX) continue;
                C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
            }
        }
    }

    return C;
}

Matrix matpow(Matrix A, long long p) {
    int n = A.size();

    Matrix ans(n, vector<long long>(n, LLONG_MAX));
    for(int i = 0; i < n; i++) ans[i][i] = 0;

    while(p) {
        if(p & 1) ans = multiply(ans, A);
        A = multiply(A, A);
        p >>= 1;
    }

    return ans;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k; cin >> n>> m >> k;
    Matrix adj(n, vector<ll>(n,LLONG_MAX));
    for(ll i = 0; i < m; i++) {
        ll x, y, z; cin >> x >> y >> z;
        x--; y--;
        adj[x][y] = min(adj[x][y], z);
    }

    Matrix final = matpow(adj, k);
    ll ans = final[0][n-1];
    if(ans == LLONG_MAX) cout << -1 << endl;
    else cout << ans << endl;
}