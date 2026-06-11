// 00 : 00 :::: Remember the Greedy Logic
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

ll n;
vector<ll> arr;

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    arr.assign(n, 0);
    for(ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<ll> tail;
    for(auto x : arr) {
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if(it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    cout << tail.size() << endl;
}