// Write your code here
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

struct st {
    ll i;
    ll wins;
    ll draws;
    ll score;
    ll goals;
    ll conced;
    ll diff;
};

void solve() {
    ll n; cin >> n;
    vector<st> arr(n);
    for(ll i = 0; i < n; i++) {
        arr[i].i = i;
        cin >> arr[i].wins;
    }
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].draws;
    }
    for(ll i = 0; i < n; i++) {
        arr[i].score = 3 * arr[i].wins + arr[i].draws;
        cin >> arr[i].goals;
    }
    for(ll i = 0; i < n; i++) {
        cin >> arr[i].conced;
        arr[i].diff = arr[i].goals - arr[i].conced;
    }

    sort(arr.begin(), arr.end(), [](const st a, const st b) {
        if(a.score != b.score) {
            return a.score > b.score;
        }
        else {
            if(a.diff != b.diff) {
                return a.diff > b.diff;
            }   
            else {
                return a.i < b.i;
            }
        }
    });

    cout << arr[0].i << " " << arr[1].i << endl;

    // for(auto e : arr) {
    //     cout << e.i << " " << e.score << " " << e.diff << endl;
    // }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) {
        solve();
    }
}