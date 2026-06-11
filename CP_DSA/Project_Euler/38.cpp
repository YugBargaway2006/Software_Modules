#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;


#define int long long


bool pandigital(string num) {
    vector<int> count(10, 0);
    for(char c : num) count[c - '0']++;

    if(count[0] != 0) return false;
    for(int i = 1; i <= 9; i++) {
        if(count[i] != 1) return false;
    }
    return true;
}

signed main(void) {
    int ans = 0;
    for(int n = 2; n <= 9; n++) {
        int ll = pow(10,9/n-1);
        int up = pow(10,9/n);

        cout << ll << " " << up << endl;

        for(int i = ll; i < up; i++) {
            string curr = "";
            for(int j = 1; j <= n; j++) {
                curr += to_string(i*j);
            }
            if(pandigital(curr)) {
                ans = max(ans, stoll(curr));
            }
        }
    }
    cout << ans << endl;
}