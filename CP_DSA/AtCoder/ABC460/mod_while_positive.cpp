// https://atcoder.jp/contests/abc460/tasks
// 14 : 31
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m; cin >> n >> m;
    ll ct = 0;
    while(m != 0) {
        m = n%m;
        ct++;
    }
    cout << ct << endl;
}