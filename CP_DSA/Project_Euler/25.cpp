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

signed main(void) {
    string fnm1 = "1";
    string fnm2 = "1";
    
    string fn = "";
    int idx = 3;
    while(fn.size() != 1000) {
        fn = sum(fnm1, fnm2);
        cout << idx << " -> " << fn << endl;
        idx++;
        fnm2 = fnm1;
        fnm1 = fn;
    }

    cout << idx-1  << endl;
    cout << fn << endl;
}
