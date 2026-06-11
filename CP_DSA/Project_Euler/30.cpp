#include <iostream>
#include <math.h>
using namespace std;

#define int long long

int digit_sum(int n) {
    int ans = 0;
    while(n > 0) {
        int d = n%10;
        n /= 10;
        ans += d*d*d*d*d;
    }
    return ans;
}

signed main(void) {
    int ans = 0;
    for(int i = 2; i < 300000; i++) {
        if(i == digit_sum(i)) ans += i;
    }
    cout << ans << endl;
}