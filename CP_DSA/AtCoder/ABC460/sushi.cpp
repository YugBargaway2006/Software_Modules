// 14 : 31
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    vector<ll> arr(n), brr(m);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(ll i = 0; i < m; i++) {
        cin >> brr[i];
    }

    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());

    ll ne = 0;
    ll ct = 0;
    for(ll i = 0; i < n; i++) {
        if(ne >= m) break;
        if(brr[ne] > 2*arr[i]) continue;
        ct++;
        ne++; 
    }
    cout << ct << endl;
}