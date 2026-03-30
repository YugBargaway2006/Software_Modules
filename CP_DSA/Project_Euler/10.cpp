#include <iostream>
#include <vector>
using namespace std;

#define int long long

void sieve_of_eratothesis() {
    vector<bool> sieve(2000001, false);
    int ans = 0;
    sieve[1] = true;

    int n = 2000001;
    for(int i = 2; i < 2000001; i++) {
        if(!sieve[i]) {
            ans += i;
            int j = i;
            while(j < n) {
                sieve[j] = true;
                j += i;
            }
        }
    }

    cout << ans << endl;
}

signed main(void) {
    sieve_of_eratothesis();
}