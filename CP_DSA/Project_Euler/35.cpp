#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

#define int long long

vector<bool> p(1e6+1, true);

void compute() {
    p[0] = p[1] = false;
    // cout << ".";
    for(int i = 2; i < 1e6; i++) {
        if(!p[i]) continue;
        // cout << ".";
        int j = i+i;
        while(j < 1e6) {
            p[j] =  false;
            j += i;
        }
    }
}

int calculate_digits(int n) {
    if (n == 0) return 1;
    int t = 0;
    while(n) { t++; n /= 10; }
    return t;
}

bool check(int n) {
    int d = calculate_digits(n);
    int p10 = pow(10, d - 1);
    int c = n;
    
    for (int i = 0; i < d; i++) {
        int rem = c % 10;
        c = c / 10 + rem * p10;
        if (!p[c]) return false;
    }
    return true;
}

signed main(void) {
    compute();
    int ans = 0;
    for(int i = 2; i < 1e6; i++) {
        if(p[i] && check(i)) {
            ans++;
        }
    }
    cout << ans << endl;
}