#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

using Matrix = vector<vector<ll>>;

ll mod = 1e9+7;

void matmul(Matrix& A, Matrix& B, Matrix& C, ll n) {
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            for(ll k = 0; k < n; k++) {
                C[i][k] =
                    (C[i][k] + A[i][j] * B[j][k]) % mod;
            }
        }
    }
}

Matrix matexp(Matrix& A, ll n, ll p) {
    Matrix I(n, vector<ll>(n, 0));
    for(ll i = 0; i < n; i++) I[i][i] = 1;

    if(p == 0) return I;
    if(p == 1) return A;

    Matrix half = matexp(A, n, p / 2);

    Matrix mult(n, vector<ll>(n, 0));
    matmul(half, half, mult, n);

    if(p % 2 == 0) return mult;

    Matrix ans(n, vector<ll>(n, 0));
    matmul(mult, A, ans, n);

    return ans;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; cin >> n >> k;
    Matrix arr(n, vector<ll>(n));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    Matrix res = matexp(arr, n, k);
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {
            ans = (ans + res[i][j]) % mod;
            // cout << res[i][j] << " ";
        }
        // cout << endl;
    }
    cout << ans << endl;
}