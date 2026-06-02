// ***
#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define int long long 
#define vi vector<int>
#define pi Pair<int, int>
 
void solve() {
 
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    int n, m , k; cin >> n >> m >> k;
    vi dsize(n);
    for(int i = 0; i < n; i++) {
        cin >> dsize[i];
    }
    vi asize(m);
    for(int i = 0; i < m; i++) {
        cin >> asize[i];
    }
 
    sort(dsize.begin(), dsize.end());
    sort(asize.begin(), asize.end());
 
    int count = 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(j < m) {
            if(asize[j] >= dsize[i] - k && asize[j] <= dsize[i] + k) {
                count++;
                j++;
                break;
            }
            if(asize[j] < dsize[i] - k) {
                j++;
            } else {
                break;
            }
        }
    }
 
    cout << count << endl;
}