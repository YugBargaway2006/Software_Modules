#include <iostream>
#include <vector>
using namespace std;

#define int long long

vector<bool> primes(10000, true);

void process() {
    for(int i = 2; i < primes.size(); i++) {
        if(!primes[i]) continue;
        int j = i + i;
        while(j < primes.size()) {
            primes[j] = false;
            j += i;
        } 
    }
}

int max_n(int a, int b) {
    int n = 0;
    while(primes[n*n + a*n + b]) {
        n++;
    }
    return n;
}

signed main(void) {
    process();

    int mv = 0;
    int ans = 0;
    for(int a = -999; a < 1000; a++) {
        for(int b = -1000; b <= 1000; b++) {
            int count = max_n(a, b);
            if(count > mv) {
                mv = count;
                ans = a * b;
            }
        }
    }
    cout << ans << endl;
}