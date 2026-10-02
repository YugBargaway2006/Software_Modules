// 00 : 46
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<ll> arr(m);
    for(ll i = 0; i < m; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<char> res(n+1, 'L');
    res[0] = 'L';
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j < m; j++) {
            if(i - arr[j] < 0) {
                break;
            }
            if(res[i] == 'W') continue;
            if(res[i-arr[j]] == 'W') res[i] = 'L';
            else res[i] = 'W';
        } 
    }
    for(ll i = 1; i <= n; i++) {
        cout << res[i];
    }
    cout << endl;
}