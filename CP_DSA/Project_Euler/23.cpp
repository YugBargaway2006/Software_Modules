#include <iostream>
#include <vector>
#include <math.h>
#include <set>
using namespace std;

#define int long long

bool count(int n) {
    int ans = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n%i==0) {
            if(n/i==i) ans+= i;
            else ans += n/i + i;
        }
    }
    return ((ans-n) > n);
}

signed main(void) {
    vector<bool> abun(29000, false);
    vector<int> num;
    for(int i = 1; i < 29000; i++) {
        abun[i] = count(i);
        if(abun[i]) num.push_back(i);
    }

    // cout << abun[12] << endl;
    set<int> unique;
    for(int i = 0; i < num.size(); i++) {
        for(int j = i; j < num.size(); j++) {
            if(num[i] + num[j] <= 28123) unique.insert(num[i] + num[j]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= 28123; i++) {
        if(unique.count(i) == 0) ans += i;
    }
    cout << ans << endl;
    
}