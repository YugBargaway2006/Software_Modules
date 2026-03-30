#include <iostream>
#include <algorithm>
using namespace std;

#define int long long

string sum(string a, string b) {
    if(a.size() < b.size()) swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ans = "";
    int carry = 0;

    for(int i = 0; i < a.size(); i++) {
        int dA = a[i] - '0';
        int dB = (i < b.size()) ? (b[i] - '0') : 0;
        int s = dA + dB + carry;

        ans += (s % 10) + '0';
        carry = s/10;
    }

    if(carry) ans += carry + '0';

    reverse(ans.begin(), ans.end());
    return ans;
}

signed main(void) {
    string ans = "1";

    for(int i = 1; i <= 1000; i++) {
        ans = sum(ans, ans);
    }

    int sum = 0;
    for(auto s : ans) sum += (s - '0');
    cout << sum << endl;
}