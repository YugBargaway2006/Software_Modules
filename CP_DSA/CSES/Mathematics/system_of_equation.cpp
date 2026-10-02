// 21 : 02
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

using Matrix = vector<vector<ll>>;
ll mod = 1e9+7;

Matrix multiply(Matrix &A, Matrix &B) {
    int n = A.size();
    ll m = B[0].size();
    ll l = A[0].size();

    Matrix C(n, vector<long long>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int k = 0; k < l; k++) {
            for(int j = 0; j < m; j++) {
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
    Matrix A(n, vector<ll>(m));
    Matrix B(n, vector<ll>(m, 1));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> A[i][j];
        }
        cin >> B[i][0];
    }

    Matrix invA = matpow(A, mod-2);
    Matrix ans = multiply(invA, B);
    for(ll i = 0; i < n; i++) {
        cout << ans[i][0] << " ";
    }
    cout << endl;
}