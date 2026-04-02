#include <string>
#include <iostream>
#include <vector>
using namespace std;

vector<int> lps;

void construct(string& s) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while(i < s.size()) {
        if(s[i] == s[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

}

vector<int> search(string& s, string& p) {
    int n = s.size();
    int m = p.size();

    vector<int> ans;

    construct(p);

    int i = 0; int j = 0;
    while(i < n) {
        if(s[i] == p[j]) {
            i++; j++;

            if(j == m) {
                ans.push_back(i-j);
                j = lps[j-1];
            }
        } else {
            if(j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    return ans;
}

int main(void) {
    string s; cin >> s;
    string p; cin >> p;

    lps.assign(p.size(), 0);

    vector<int> ans = search(s, p);

   cout << ans.size() << endl;

}