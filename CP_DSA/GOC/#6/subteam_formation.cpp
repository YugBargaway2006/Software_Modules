// https://www.hackerrank.com/contests/goc-cdc-series-6/challenges/team-formation-6-1/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

struct Employee {
    ll skill;
    ll idx;
    ll side; // 0 = left, 1 = right

    bool operator<(const Employee& other) const {
        if(skill != other.skill) return skill < other.skill;
        return idx > other.idx; // smaller index preferred
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n + 1);

    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    priority_queue<Employee> pq;

    ll L = 1;
    ll R = n;

    ll leftAdded = 0;
    ll rightAdded = 0;

    vector<bool> used(n + 1, false);

    while(leftAdded < m && L <= R) {
        pq.push({a[L], L, 0});
        L++;
        leftAdded++;
    }

    while(rightAdded < m && L <= R) {
        pq.push({a[R], R, 1});
        R--;
        rightAdded++;
    }

    vector<ll> ans;

    for(ll take = 0; take < m; take++) {

        while(used[pq.top().idx]) {
            pq.pop();
        }

        auto cur = pq.top();
        pq.pop();

        used[cur.idx] = true;
        ans.push_back(cur.idx);

        if(L <= R) {
            if(cur.side == 0) {
                pq.push({a[L], L, 0});
                L++;
            } else {
                pq.push({a[R], R, 1});
                R--;
            }
        }
    }

    for(ll i = 0; i < m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}