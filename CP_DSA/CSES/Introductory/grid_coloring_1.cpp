// 02 : 04
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            if((i+j) % 2 == 1) {
                if(arr[i][j] == 'A' || arr[i][j] == 'B') arr[i][j] = 'C';
                else if(arr[i][j] == 'C' || arr[i][j] == 'D') arr[i][j] = 'A';
            } else {
                if(arr[i][j] == 'A' || arr[i][j] == 'B') arr[i][j] = 'D';
                else if(arr[i][j] == 'C' || arr[i][j] == 'D') arr[i][j] = 'B';
            }
        }
    }

    for(auto& vec : arr) {
        for(auto c : vec) cout << c; cout << endl;
    }
}