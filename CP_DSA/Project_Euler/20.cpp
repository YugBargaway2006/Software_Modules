#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define int long long

string sum(string a, string b) {
    if(a.size() < b.size()) swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string ans = "";
    int c = 0;
    for(int i = 0; i < a.size(); i++) {
        int da = (a[i] - '0');
        int db = (i < b.size()) ? (b[i] - '0') : 0;

        int s = da + db + c;

        ans += ((s%10) + '0');
        c = s / 10;
    }

    if(c) ans += (c + '0');

    reverse(ans.begin(), ans.end());
    return ans;
}

string product(string a, int b) {
    string ans = "";
    while(b--) {
        ans = sum(ans, a);
    }
    return ans;
}

signed main(void) {
    int n = 1000;
    string ans = "1";
    for(int i = 1; i <= n; i++) {
        cout << ans << " " << i << endl;
        ans = product(ans, i);
    }

    int su = 0;
    for(auto s : ans) su += (s - '0');
    cout << su << endl;
}