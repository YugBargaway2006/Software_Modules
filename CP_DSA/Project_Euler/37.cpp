#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
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

bool left(int n) {
    bool res = true;

    while(n != 0) {
        // cout << n << endl;
        if(!p[n]) {
            return false;
        }
        n /= 10;
    }
    return true;
}

bool right(int n) {
    bool res = true;

    while(n != 0) {
        // cout << n << endl;
        if(!p[n]) {
            return false;
        }
        int d = floor(log10(n)) + 1;
        n %= (int)pow(10, d-1);
    }
    return true;
}

bool check(int n) {
    return left(n) && right(n);
}

signed main(void) {
    compute();
    int c = 0;
    int ans = 0;
    for(int i = 10; i <= 1e6; i++) {
        if(check(i)) {
            c++;
            ans += i;
        }
    }
    cout << c << endl;
    cout << ans << endl;

    // cout << right(100) << endl;
}