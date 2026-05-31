#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long 
#define INT_MAX LLONG_MAX
#define vi vector<int>
#define pi pair<int, int>
#define f(i,k,n) for(int i = k; i < n; i++)
#define mi map<int>
#define si set<int>
 
 
 
 
 
 
void solve() {
    string s; cin >> s;
    int n = s.length();
 
    vi freq(26, 0);
    f(i,0,n) {
        freq[s[i]-'A']++;
    }
    if(n % 2 == 0) {
        f(i,0,26) {
            if(freq[i]%2==1) {
                cout << "NO SOLUTION" << endl;
                return;
            }
        }
        vector<char> ans(n);
        int l = 0, r = n-1;
        f(i,0,26) {
            while(freq[i] != 0) {
                ans[l] = 'A' + i;
                ans[r] = 'A' + i;
                freq[i] -= 2;
                l++;
                r--;
            }
        }
        f(i,0,n) {
            cout << ans[i];
        }
        cout << endl;
 
    } else {
        int od = 0;
        vector<char> ans(n);
        f(i,0,26) {
            if(freq[i]%2==1) {
                od++;
                ans[n/2] = 'A' + i;
                freq[i]--;
            }
        }
        if(od != 1) {
            cout << "NO SOLUTION" << endl;
            return;
        }
 
        int l = 0, r = n-1;
        f(i,0,26) {
            while(freq[i] != 0) {
                ans[l] = 'A' + i;
                ans[r] = 'A' + i;
                freq[i] -= 2;
                l++;
                r--;
            }
        }
        f(i,0,n) {
            cout << ans[i];
        }
        cout << endl;
 
    }
 
 
}
 
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // int t; cin >> t;
    int t = 1;
    while(t--) {
        // cout << "solve called" << endl;
        solve();
    }
}