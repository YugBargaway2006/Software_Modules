#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    string s; cin >> s;

    ll ct = 0;
    for(ll i = 1; i < n; i++) {
        if(s[i] == 'o') ct++;
    }

    enum SIDE {
        front,
        back
    };

    SIDE side = (ct%2==0) ? back : front;

    list<ll> arr;
    arr.push_back(1);
    (side == back) ? arr.push_back(2) : arr.push_front(2);
    for(ll i = 1; i < n; i++) {
        if(i != 1) (side == back) ? arr.push_back(i+1) : arr.push_front(i+1);
        if(s[i] == 'x') {
        } 
        else {
            side = (side == back) ? front : back;
        }
    }

    for(auto it : arr) {
        cout << it << " ";
    }
    cout << endl;
} 