#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define endl '\n'

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t; cin >> t;
    while(t--) {
        ll n, m; cin >> n >> m;
        if(m == 1) cout << 2 << endl;
        else if(n % 2 == 0) cout << 2 << endl;
        else cout << 1 << endl;
    }
    return 0;
}
