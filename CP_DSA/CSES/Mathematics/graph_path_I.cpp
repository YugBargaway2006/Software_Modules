// 21 : 02
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

using Matrix = vector<vector<ll>>;
ll mod = 1e9+7;

Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.size();

    Matrix C(n, vector<long long>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            for(int j = 0; j < n; j++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
            }
        }
    }

    return C;
}

Matrix matpow(Matrix A, long long p) {
    int n = A.size();

    Matrix ans(n, vector<long long>(n, 0));
    for(int i = 0; i < n; i++) ans[i][i] = 1;

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
    Matrix adj(n, vector<ll>(n,0));
    for(ll i = 0; i < m; i++) {
        ll x, y; cin >> x >> y;
        x--; y--;
        adj[x][y]++;
    }

    Matrix final = matpow(adj, k);
    ll ans = final[0][n-1];
    cout << ans << endl;
}