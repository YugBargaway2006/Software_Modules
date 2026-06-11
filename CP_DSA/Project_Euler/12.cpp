#include <iostream>
#include <math.h>
using namespace std;

#define int long long

int count(int n) {
    int ans = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n%i == 0) {
            if(n / i == i) ans++;
            else ans += 2;

        }
    }
    return ans;
}

signed main(void) {
    int n = 1;
    while(true) {
        int m = n*(n+1)/2;
        if(count(m) > 500) {
            cout << m << endl;
            break; 
        }
        n++;
        // cout << m << endl;
    }
}