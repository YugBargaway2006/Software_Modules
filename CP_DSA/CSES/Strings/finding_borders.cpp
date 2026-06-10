#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define int long long
 
signed main() {
    string s;
    cin >> s;
 
    int n = s.size();
    vector<int> pi(n, 0);
 
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
 
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
 
        if (s[i] == s[j]) {
            j++;
        }
 
        pi[i] = j;
    }
 
    vector<int> ans;
    int j = pi[n - 1];
 
    while (j > 0) {
        ans.push_back(j);
        j = pi[j - 1];
    }
 
    reverse(ans.begin(), ans.end());
 
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
 
    return 0;
}
