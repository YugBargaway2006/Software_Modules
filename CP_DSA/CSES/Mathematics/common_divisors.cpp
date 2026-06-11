// 13 : 58  :::::::: Remember 
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

vector<int> divisors(1e6 + 1, 0);

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;

    while(n--) {
        int x;
        cin >> x;
        const int up = (int)sqrt(x);
		for (int div = 1; div <= up; div++) {
			if (x % div == 0) {
				divisors[div]++;
				if (div != x / div) { divisors[x / div]++; }
			}
		}
    }

    for (int i = 1e6; i >= 1; i--) {
		if (divisors[i] >= 2) {
			cout << i << endl;
			break;
		}
	}
}