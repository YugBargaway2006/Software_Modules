// 17 : 09
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    map<int, int> arr; 
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(arr.count(x-a) != 0) {
            cout << arr[x-a]+1 << " " << i+1 << endl;
            return 0;
        }

        arr[a] = i;
    }
    cout << "IMPOSSIBLE" << endl;
}