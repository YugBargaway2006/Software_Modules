#include <iostream>
using namespace std;

#define int long long

signed main(void) {
    int ans = 1;
    int count = 1;
    for(int i = 2; i < 1001; i+=2) {
        for(int j = 0; j < 4; j++) {
            count += i;
            ans += count; 
        }
    }
    cout << ans << endl;
}