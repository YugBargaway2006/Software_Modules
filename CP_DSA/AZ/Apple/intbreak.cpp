
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'

ll mod = 1e9+7;

ll binexp(ll b, ll p, ll mod) {
    if(p == 0) return 1;
    if(p == 1) return b % mod;

    ll half = binexp(b, p/2, mod);
    ll full = (half * half) % mod;
    if(p % 2 == 1) {
        full = (full * b) % mod;
    }
    return full % mod;
}



int findMaxProd(int n)
{
    if(n == 2) return 1;
    if(n == 3) return 2;
    ll n3 = 0;
    for(ll i = 0; i <= n; i += 2) {
        if((n-i) % 3 == 0) {
            n3 = n-i;
            break;
        } 
    }

    ll p3 = n3/3;
    ll p2 = (n-n3)/2;

    ll ans = binexp(2, p2, mod);
    ans = (ans * binexp(3, p3, mod)) % mod;
    return ans % mod; 
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << findMaxProd(n) << '\n';
    }
    return 0;
}
