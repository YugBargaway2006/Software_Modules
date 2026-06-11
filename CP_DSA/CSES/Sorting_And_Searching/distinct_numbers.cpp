// ***
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long 
#define vi vector<int>
#define pi Pair<int, int>
 

 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
 
    if(n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int count = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] != a[i - 1]) count++;
    }
    cout << count << endl;
}