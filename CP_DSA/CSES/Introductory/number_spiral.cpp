#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define ll long long
#define f(i,k,n) for(int i = k; i < n; i++)
 
void solve() {
    int x, y; cin >> x >> y;
 
    if(x == y) {
        cout << x*x - x + 1 << endl;
        return;
    }
    if(x > y) {
        if(x%2 == 0) {
            int ans = x*x+1;
            f(i,0,y) {
                ans--;
            }
            cout << ans << endl;
            return;
        } else {
            int ans = (x-1)*(x-1);
            f(i,0,y) {
                ans++;
            }
            cout << ans << endl;
            return;
        }
    } 
    else {
        // debug(x);
        // debug(y);
        if(y%2 == 0) {
            int ans = (y-1)*(y-1);
            // debug(ans);
            f(i,0,x) {
                ans++;
            }
            cout << ans << endl;
            return;
        } else {
            int ans = y*y+1;
            f(i,0,x) {
                ans--;
            }
            cout << ans << endl;
            return;
        }
    }
}
 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    // int t = 1;
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
}
