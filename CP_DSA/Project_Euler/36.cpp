#include <iostream>
#include <algorithm>
using namespace std;

string intToBinary(int n) {
    if (n == 0) return "0";
    string r;
    while (n != 0) {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    reverse(r.begin(), r.end());
    return r;
}

bool check(int n) {
    string b10 = to_string(n);
    string b2  = intToBinary(n);

    string b10r = b10;
    string b2r = b2;
    reverse(b10r.begin(), b10r.end());
    reverse(b2r.begin(), b2r.end());

    return (b10 == b10r && b2 == b2r);
}

int main(void) {
    int ans = 0;
    for(int i = 1; i <= 1e6; i++) {
        if(check(i)) ans += i;
    }
    cout << ans << endl;
}