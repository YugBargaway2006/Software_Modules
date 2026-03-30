#include <iostream>
using namespace std;

#define int long long

signed main(void) {
    int ans = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            for(int k = 1; k <= 1000; k++) {
                if(i+j+k == 1000) {
                    if(i*i + j*j == k*k) {
                        ans = i*j*k;
                    }
                }
            }
        }
    }
    cout << ans << endl;
} 