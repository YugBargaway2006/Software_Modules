#include <bits/stdc++.h>
using namespace std;

#define int long long

bool present(string num) {
    vector<int> count(10, 0);
    for(char c : num) count[c - '0']++;

    if(count[0] != 0) return false;
    for(int i = 1; i <= 9; i++) {
        if(count[i] != 1) return false;
    }
    return true;
}

signed main() {
    set<int> products;

    // Case 1: 1-digit × 4-digit
    for(int i = 1; i < 10; i++) {
        for(int j = 1000; j < 10000; j++) {
            int p = i * j;
            string num = to_string(i) + to_string(j) + to_string(p);
            if(num.size() == 9 && present(num)) {
                products.insert(p);
            }
        }
    }

    // Case 2: 2-digit × 3-digit
    for(int i = 10; i < 100; i++) {
        for(int j = 100; j < 1000; j++) {
            int p = i * j;
            string num = to_string(i) + to_string(j) + to_string(p);
            if(num.size() == 9 && present(num)) {
                products.insert(p);
            }
        }
    }

    int ans = 0;
    for(auto x : products) ans += x;

    cout << ans << endl;
}