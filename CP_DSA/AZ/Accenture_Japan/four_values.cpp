// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

bool diff(ll a, ll b, ll c, ll d) {
    if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d) {
        return true;
    }
    return false;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x;cin >> n >> x;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    map<ll, vector<pair<ll, ll>>> sum;
    for(ll i = 0; i < n; i++) {
        for(ll j = i+1; j < n; j++) {
            ll req = x - arr[i] - arr[j];
            if(sum.count(req)) {
                for(auto p : sum[req]) {
                    if(diff(i,j,p.first, p.second)) {
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
            sum[arr[i]+arr[j]].push_back({i, j});
        }
    } 
    cout << "NO" << endl;
}