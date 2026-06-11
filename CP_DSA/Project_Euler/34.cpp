#include <iostream>
#include <vector>
using namespace std;

#define int long long

vector<int> f = {1,1,2,6,24,120,720,5040,40320,362880,3628800};

int sum(int n) {
    int ans = 0;
    while(n != 0) {
        int d = n%10;
        n /= 10;
        ans += f[d];
    }
    return ans;
}

signed main(void) {
    int ans = 0;
    for(int i = 3; i < 1e5; i++) {
        if(i == sum(i)) ans += i;
    }
    cout << ans << endl;
}