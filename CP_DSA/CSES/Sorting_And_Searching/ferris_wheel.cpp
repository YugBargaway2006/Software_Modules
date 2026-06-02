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
 
    int n, x; cin >> n >> x;
    vi wt(n);
    for(int i = 0; i < n ; i++) {
        cin >> wt[i];
    }
 
    sort(wt.begin(), wt.end());
 
    int count = 0;
    int left = 0, right =  n - 1;
    while(left < right) {
        if(wt[left] + wt[right] <= x) {
            count++; left++; right--;
        } else {
            if(wt[right] <= x) {
                right--; count++;
            } else {
                right--;
            }
        }
    }
    if(left == right) {
        if(wt[left] <= x) {
            count++;
        }
    }
    cout << count << endl;
}