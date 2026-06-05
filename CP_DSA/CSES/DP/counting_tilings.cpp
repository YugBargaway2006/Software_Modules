// 16 : 57
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n, m;
ll mod = 1e9+7;
vector<vector<ll>> tilings(1001, vector<ll>(1 << 10));

void fill_column(ll col, ll idx, ll cm, ll nm) {
    if(idx == n) {
        tilings[col+1][nm] = (tilings[col+1][nm] + tilings[col][cm]) % mod;
        return;
    }
    if((cm & (1 << idx))) {
        fill_column(col, idx+1, cm, nm);    // Already Filled
    } else {
        fill_column(col, idx+1, cm, nm | (1 << idx));   // Horizontal Tile
        if(idx+1 < n && (!(cm&(1<<idx+1)))) {   // Vertical Tile
            fill_column(col, idx+2, cm, nm);
        } 
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    tilings[0][0] = 1;
    for(ll col = 0; col < m; col++) {
        for(ll mask = 0; mask < (1 << n); mask++) {
            if(tilings[col][mask] > 0) {
                fill_column(col, 0, mask, 0);
            }
        }
    }

    cout << tilings[m][0] << endl;

}