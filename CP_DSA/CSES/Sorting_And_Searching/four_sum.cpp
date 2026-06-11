// 23 : 55    ::::: Remember the Two pointer approach
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, x; cin >> n >> x;
    vector<pair<ll,ll>> a;

    for(int i=0;i<n;i++){
        ll x;
        cin >> x;
        a.push_back({x,i+1});
    }

    sort(a.begin(), a.end());

    for(int i=0;i<n;i++){
        for(ll j = i+1; j < n; j++) {
            ll target = x - a[i].first - a[j].first;
            int l = j+1;
            int r = n-1;
    
            while(l < r){
                ll sum = a[l].first + a[r].first;
    
                if(sum == target){
                    // cout << a[i].first << " " << a[j].first << " "  << a[l].first << " " << a[r].first << endl;
                    cout << a[i].second << " " << a[j].second << " "
                        << a[l].second << " "
                        << a[r].second;
                    return 0;
                }
                else if(sum < target) l++;
                else r--;
            }
        }
    }

    cout << "IMPOSSIBLE";


}