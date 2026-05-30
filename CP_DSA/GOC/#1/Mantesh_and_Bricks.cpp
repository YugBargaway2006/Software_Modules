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
    
    ll n; cin >> n;
    ll m = 1e9;
    vector<vector<ll>> arr(n, vector<ll>(2));
    for(ll i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1]; 
    }
                           
    sort(arr.begin(), arr.end());
    
    vector<vector<ll>> intervals;
    intervals.push_back(arr[0]);
    ll sz = 0;
    for(ll i = 1; i < n; i++) {
        if(arr[i][0] <= intervals[sz][1]) {
            if(arr[i][1] <= intervals[sz][1]) {
                continue;
            } else {
                intervals[sz][1] = arr[i][1];
            }
        } else {
            intervals.push_back(arr[i]);
            sz++;
        }
    }
    
    ll ct = 0;
    for(auto& seg : intervals) {
        ct += (seg[1] - seg[0] + 1);
    }
    cout << ct << endl;
                           
    
    
    
    return 0;
}
