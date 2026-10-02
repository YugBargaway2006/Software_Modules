// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll mod = 1e16;

using Matrix = vector<vector<ll>>;
bool modded = false;

Matrix matmul(Matrix& A, Matrix& B) {
    Matrix C(2, vector<ll>(2, 0));
    for(ll i = 0; i < 2; i++) {
        for(ll k = 0; k < 2; k++) {
            for(ll j = 0; j < 2; j++) {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    return C;
}

Matrix matexp(Matrix& A, ll p) {
    Matrix I = {
        {1,0},
        {0,1}
    };
    if(p == 0) return I;
    if(p == 1) return A;

    Matrix half = matexp(A, p/2);
    Matrix full = matmul(half, half);
    if(p % 2 == 0) {
        return full;
    } 
    return matmul(full, A);
}

void solve() {
    ll n; cin >> n;
    if(n == 0) {
        cout << 0 << endl; return;
    }
    if(n == 1) {
        cout << 1 << endl; return;
    }
    Matrix A = {
        {1,1},
        {1,0}
    };

    // cout << matexp(A,75)[0][0] << endl;

    ll l = 0; ll r = 75;
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        Matrix ans = matexp(A, mid);
        if(ans[0][0] == n) {
            cout << mid+1 << endl;
            return;
        } else if(ans[0][0] < n) {
            l = mid+1;
        } else {
            r = mid - 1;
        }
    }
    cout << -1 << endl;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}