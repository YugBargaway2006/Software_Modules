// 23 : 24
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<pair<int,int>> pos;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t;
    cin >> t;

    vector<ll> nums(t);
    ll mx = 0;

    for(int i = 0; i < t; i++) {
        cin >> nums[i];
        mx = max(mx, nums[i]);
    }

    pos.assign(mx + 1, {-1, -1});

    ll s = sqrt(mx);

    for(ll a = 0; a <= s; a++) {
        for(ll b = 0; a*a + b*b <= mx; b++) {
            if(pos[a*a + b*b].first == -1)
                pos[a*a + b*b] = {a, b};
        }
    }

    for(ll n : nums) {
        ll s = sqrt(n);

        bool found = false;

        for(ll i = 0; i <= s && !found; i++) {
            for(ll j = 0; i*i + j*j <= n; j++) {

                ll req = n - i*i - j*j;

                if(pos[req].first != -1) {
                    auto [l, r] = pos[req];

                    cout << i << " " << j << " "
                         << l << " " << r << endl;

                    found = true;
                    break;
                }
            }
        }

        if(!found) cout << -1 << endl;
    }
}