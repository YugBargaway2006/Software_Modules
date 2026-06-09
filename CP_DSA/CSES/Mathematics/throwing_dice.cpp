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

    ll n; cin >> n;
    Matrix recur = {
        {1,1,1,1,1,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,1,0,0,0},
        {0,0,0,1,0,0},
        {0,0,0,0,1,0}
    };

    Matrix final = matpow(recur, n);
    cout << final[0][0] << endl;
}