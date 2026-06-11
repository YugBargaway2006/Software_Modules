#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define int long long

int count(int n) {
    int ans = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n%i==0) {
            if(n/i==i) ans+= i;
            else ans += n/i + i;
        }
    }
    return ans-n;
}

signed main(void) {
    vector<int> dp(10001, 0);
    for(int i = 1; i < 10001; i++) {
        dp[i] = count(i);
    }

    cout << dp[284] << " " << dp[220] << endl;
    int ans = 0;
    for(int i = 1; i < 10001; i++) {
        int j = dp[i];
        if(j < 10001 && j != i && dp[j] == i) {
            ans += i;
        }
    } 
    cout << ans << endl;
}